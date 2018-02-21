/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:05:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/18 15:05:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void write_blocks(char **files, t_ls *data, unsigned int *link_width)
{
	char *temp;
	unsigned int i;
	struct stat status;
	unsigned int blocks;
	unsigned int temp_width;

	i = 0;
	blocks = 0;
	while (files[i])
	{
		temp = ft_strjoin(data->path_to_dir, files[i++]);
		lstat(temp, &status);
		temp_width = (unsigned int)ft_strlen(ft_itoa(status.st_nlink));
		if (*link_width <= temp_width)
			*link_width = temp_width;
		blocks += status.st_blocks;
		free(temp);
	}
	if (data->arg_nb > 0)
		ft_printf("total %d\n", blocks);
}

static void write_file_type(char *file)
{
	char c;
	struct stat status;

	c = '-';
	lstat(file, &status);
	if (S_ISBLK(status.st_mode))
		c = 'b';
	else if (S_ISCHR(status.st_mode))
		c = 'c';
	else if (S_ISDIR(status.st_mode))
		c = 'd';
	else if (S_ISFIFO(status.st_mode))
		c = 'f';
	else if (S_ISREG(status.st_mode))
		c = '-';
	else if (S_ISLNK(status.st_mode))
		c = 'l';
	else if (S_ISSOCK(status.st_mode))
		c = 's';
	write(1, &c, 1);
}

static void print_file_mode(char *file, mode_t st_mode, unsigned int k, unsigned int i)
{
	char *temp;

	temp = ft_itoa_base(st_mode, 8);
	i = (unsigned int)ft_strlen(temp) - 4;
	if ((int)i < 0)
		return ;
	write_file_type(file);
	while (k++ != 3)
	{
		if (temp[++i] == '0')
			write(1, NO_ACCESS, 3);
		else if (temp[i] == '1')
			write(1, X_ACCESS, 3);
		else if (temp[i] == '2')
			write(1, W_ACCESS, 3);
		else if (temp[i] == '3')
			write(1, WX_ACCESS, 3);
		else if (temp[i] == '4')
			write(1, R_ACCESS, 3);
		else if (temp[i] == '5')
			write(1, RX_ACCESS, 3);
		else if (temp[i] == '6')
			write(1, RW_ACCESS, 3);
		else if (temp[i] == '7')
			write(1, RWX_ACCESS, 3);
	}
	free(temp);
}

static unsigned int ft_get_user_indent(char **files, t_ls *data)
{
	unsigned int i;
	unsigned int temp;
	unsigned int indentation;
	struct passwd *user_id;
	struct stat status;
	char *str;

	i = 0;
	indentation = 0;
	while (files[i++])
	{
		str = ft_strjoin(data->path_to_dir, files[i]);
		lstat(str, &status);
		user_id = getpwuid(status.st_uid);
		if (str)
			if (indentation <= (temp = (unsigned int)ft_strlen(user_id->pw_name)))
				indentation = temp;
		ft_strdel(&str);
	}
	return (indentation);
}

static unsigned int ft_get_grg_indent(char **files, t_ls *data)
{
	unsigned int i;
	unsigned int temp;
	unsigned int indentation;
	struct group *group_id;
	struct stat status;
	char *str;

	i = 0;
	indentation = 0;
	while (files[i])
	{
		str = ft_strjoin(data->path_to_dir, files[i++]);
		lstat(str, &status);
		group_id = getgrgid(status.st_gid);
		if (str)
			if (indentation <= (temp = (unsigned int)ft_strlen(group_id->gr_name)))
				indentation = temp;
		ft_strdel(&str);
	}
	return (indentation);
}

static void ft_print_owner_and_group(struct stat status, unsigned int usr_indent, unsigned int grg_indent)
{
	struct passwd *user_id;
	struct group *group_id;

	user_id = getpwuid(status.st_uid);
	group_id = getgrgid(status.st_gid);
	ft_printf("%-*s ", usr_indent + 1, user_id->pw_name);
	ft_printf("%-*s", grg_indent, group_id->gr_name);
}

static unsigned int ft_get_size_width(char **files, t_ls *data)
{
	char *temp;
	unsigned int i;
	struct stat status;
	unsigned int size_width;
	unsigned int temp_width;

	i = 0;
	size_width = 0;
	while (files[i])
	{
		temp = ft_strjoin(data->path_to_dir, files[i++]);
		lstat(temp, &status);
		temp_width = (unsigned int)ft_strlen(ft_itoa((int)status.st_size));
		if (size_width <= temp_width)
			size_width = temp_width;
		free(temp);
	}
	return (size_width);
}

static void ft_print_time(struct stat status)
{
	char *time_str;
	time_t cur_time;

	cur_time = time(NULL);
	time_str = ctime(&status.st_mtimespec.tv_sec);
	if (time_str)
	{
		time_str += 4;
		if (cur_time -  status.st_mtimespec.tv_sec > 15778463)
		{
			time_str[7] = '\0';
			ft_printf("%s", time_str);
			time_str += 15;
			time_str[5] = '\0';
			ft_printf("%s ", time_str);
		}
		else
		{
			time_str[12] = '\0';
			ft_printf("%s ", time_str);
		}
	}
}

char *ft_get_link_value(char *file)
{
	char *buf;

	buf = ft_strnew(127);
	readlink(file, buf, 126);
	return (buf);
}

void ft_long_print(char **files, t_ls *data)
{
	unsigned int i;
	unsigned int link_width;
	unsigned int size_width;
	unsigned int grg_width;
	unsigned int usr_width;
	struct stat status;
	char *temp;

	i = 0;
	link_width = 0;
	size_width = 0;
	if (files[i])
	{
		temp = data->path_to_dir;
		data->path_to_dir = ft_strjoin(data->path_to_dir, "/");
		free(temp);
		if (lstat(ft_strjoin(data->path_to_dir, files[i]), &status) == -1) // new thing
		{
			if (files[i][0] == '/')
			{
				free(data->path_to_dir);
				data->path_to_dir = ft_strdup("/");
			}
		} // end of this
		write_blocks(files, data, &link_width);
		size_width = ft_get_size_width(files, data);
		grg_width = ft_get_grg_indent(files, data);
		usr_width = ft_get_user_indent(files, data);
	}
	while (files[i])
	{
		temp = ft_strjoin(data->path_to_dir, files[i]);
		lstat(temp, &status);                                   // when should i use stat???
		print_file_mode(temp, status.st_mode, 0, 0);
		ft_printf(" %*u ", link_width + 1, status.st_nlink);
		ft_print_owner_and_group(status, usr_width, grg_width);
		ft_printf("%*lld ", size_width + 2, status.st_size);
		ft_print_time(status);
		ft_printf("%s", files[i++]);// file name
		if (S_ISLNK(status.st_mode))
			ft_printf(" -> %s\n", ft_get_link_value(temp));
		else
			write(1, "\n", 1);
		free(temp);
	}
}