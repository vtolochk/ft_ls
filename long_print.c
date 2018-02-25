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

static void write_blocks(char **files, t_ls *data, int *link_width)
{
	char *temp;
	struct stat status;
	int i;
	int blocks;
	int temp_width;

	i = 0;
	blocks = 0;
	while (files[i])
	{
		temp = ft_strjoin(data->path_to_dir, files[i++]);
		lstat(temp, &status);
		ft_strdel(&temp);
		temp = ft_itoa(status.st_nlink);
		temp_width = (unsigned int)ft_strlen(temp);
		if (*link_width <= temp_width)
			*link_width = temp_width;
		blocks += status.st_blocks;
		ft_strdel(&temp);
	}
	if (data->arg_nb > 0)
	{
		write(1, "total ", 6);
		ft_printf("%d\n", blocks);
	}
}

static void ft_print_owner_and_group(struct stat status, int usr_indent, int grg_indent)
{
	struct passwd *user_id;
	struct group *group_id;

	user_id = getpwuid(status.st_uid);
	group_id = getgrgid(status.st_gid);
	ft_printf("%-*s", usr_indent, user_id->pw_name);
	ft_printf("  %-*s", grg_indent, group_id->gr_name);
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
		if ((cur_time - status.st_mtimespec.tv_sec > 15778463) || cur_time < status.st_mtimespec.tv_sec)
		{
			time_str[7] = '\0';
			write(1, time_str, ft_strlen(time_str));
			time_str += 8;
			ft_printf(" %d ", ft_atoi(ft_strrchr(time_str, ' ') + 1));
		}
		else
		{
			time_str[12] = '\0';
			write(1, time_str, ft_strlen(time_str));
			write(1, " ", 1);
		}
	}
}

static void ft_join_dirs(t_ls *f, char **files, struct stat *status)
{
	char *temp;

	temp = f->path_to_dir;
	f->path_to_dir = ft_strjoin(f->path_to_dir, "/");
	ft_strdel(&temp);
	temp = ft_strjoin(f->path_to_dir, files[0]);
	if (lstat(temp, status) == -1)
	{
		if (files[0][0] == '/')
		{
			free(f->path_to_dir);
			f->path_to_dir = ft_strdup("/");
		}
	}
	ft_strdel(&temp);
}

void ft_long_print(char **files, t_ls *data)
{
	int i;
	int link_width;
	int size_width;
	int grg_width;
	int usr_width;
	struct stat status;
	char *temp;

	i = 0;
	link_width = 0;
	if (files[i])
	{
		ft_join_dirs(data, files, &status);
		write_blocks(files, data, &link_width);
		size_width = ft_get_size_width(files, data);
		grg_width = ft_get_grg_indent(files, data, 0);
		usr_width = ft_get_user_indent(files, data, 0);
	}
	while (files[i])
	{
		temp = ft_strjoin(data->path_to_dir, files[i]);
		lstat(temp, &status);
		print_file_mode(temp, status.st_mode);
		ft_printf(" %*u ", link_width + 1, status.st_nlink);
		ft_print_owner_and_group(status, usr_width, grg_width);
		if (S_ISBLK(status.st_mode) || S_ISCHR(status.st_mode))
			ft_printf(" %u,   %u ", status.st_rdev >> 24 & 0xff, status.st_rdev & 0xffffff);
		ft_printf("%*lld ", size_width + 2, status.st_size);
		ft_print_time(status);
		write(1, files[i], ft_strlen(files[i]));
		i++;
		if (S_ISLNK(status.st_mode))
			ft_printf(" -> %s\n", ft_get_link_value(temp));
		else
			write(1, "\n", 1);
		free(temp);
	}
}