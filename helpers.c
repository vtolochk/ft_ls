/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:25:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/10 16:25:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char ft_get_file_type(char *file_name)
{
	struct stat file_stat;

	if (lstat(file_name, &file_stat) == -1)
		return ('e');
	if (file_stat.st_mode & S_IFIFO)
		return ('f');
	else if (file_stat.st_mode & S_IFCHR)
		return ('c');
	else if (file_stat.st_mode & S_IFDIR)
		return ('d');
	else if (file_stat.st_mode & S_IFBLK)
		return ('b');
	else if (file_stat.st_mode & S_IFREG)
		return ('-');
	else if (file_stat.st_mode & S_IFLNK)
		return ('l');
	else if (file_stat.st_mode & S_IFSOCK)
		return ('s');
	else if (file_stat.st_mode & S_IFWHT)
		return ('w');
	return ('e');
}

int ft_is_link(char *dir)
{
	struct stat status;

	lstat(dir, &status);
	if (S_ISLNK(status.st_mode))
		return (0);
	return (1);
}

char ft_isdir(char *dir, t_ls *f, char **files_arr)
{
	DIR *ptr;
	char *temp;

	if (ft_is_link(dir) == 0)
		return (0);
	if ((ptr = opendir(dir)))
	{
		if (readdir(ptr))
		{
			closedir(ptr);
			return (1);
		}
	}
	else
	{
		if (ft_get_file_type(dir) == 'd')
		{
			if (f->first_dir == 0 || ft_arr_len(files_arr) > 1)
			{
				write(1, "\n", 1);
				write(1, dir, ft_strlen(dir));
				write(1, ":\n", 2);
				f->first_dir = 0;
			}
			temp = ft_strrchr(dir, '/');
			ft_print_errno(++temp);
		}
	}
	return (0);
}

void ft_error_first(char **arg_files, t_ls *f)
{
	int i;

	i = 0;
	f->big_g = 0; // u have to color this shit in red :)
	while (arg_files[i])
	{
		if ((ft_get_file_type(arg_files[i])) == 'e')
		{
			ft_print_errno(arg_files[i]);
			arg_files[i][0] = '\0';
		}
		i++;
	}
}

void ft_get_dir(char **temp_argv, char **arg_files, unsigned int *i, unsigned int *k)
{
	char *buf;
	struct stat inf;

	buf = ft_strnew(127);
	readlink(arg_files[(*i)], buf, 127);
	lstat(buf, &inf);
	if (S_ISDIR(inf.st_mode))
	{
		arg_files[(*i)] = buf;
		return ;
	}
	temp_argv[(*k)] = ft_strdup(arg_files[(*i)]);
	arg_files[(*i)][0] = '\0';
	(*k)++;
}

void ft_files_second(char **arg_files, t_ls *f, void (*print)(char **, t_ls *))
{
	unsigned int i;
	unsigned int k;
	char **temp_arg_files;

	i = 0;
	k = 0;
	temp_arg_files = (char **)malloc((ft_arr_len(arg_files) + 1) * (sizeof(char *)));
	while (arg_files[i])
	{
		if (ft_get_file_type(arg_files[i]) == '-' || ft_get_file_type(arg_files[i]) == 'c')
		{
			if (ft_is_link(arg_files[i]) == 0 && f->list == 0)
			{
				ft_get_dir(temp_arg_files, arg_files, &i, &k);
			}
			else
			{
				temp_arg_files[k] = ft_strdup(arg_files[i]);
				arg_files[i][0] = '\0';
				k++;
			}
		}
		i++;
	}
	temp_arg_files[k] = NULL;
	if (ft_strncmp(arg_files[0], ".", 2) == 0 && arg_files[1] == NULL)
	{
		ft_free_tab((void**)temp_arg_files);
		return ;
	}
	print(temp_arg_files, f);
	if (i > k && k)
		write(1, "\n", 1);
	ft_free_tab((void**)temp_arg_files);
}

int ft_print_errno(char *file_name)
{
	write(2, "ls", 2);
	write(2, ": ", 2);
	write(2, file_name, ft_strlen(file_name));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return (FAIL);
}
