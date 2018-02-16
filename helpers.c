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

char ft_isdir(char *dir)
{
	DIR *ptr;

	if ((ptr = opendir(dir)))
	{
		if (readdir(ptr))
		{
			closedir(ptr);
			return (1);
		}
	}
	return (0);
}

void ft_error_first(char **argv, char **arg_files, t_ls f)
{
	int i;

	i = 0;
	f.big_g = 0; // u have to color this shit in red :)
	while (arg_files[i])
	{
		if ((ft_get_file_type(arg_files[i])) == 'e')
		{
			ft_print_errno(argv, arg_files[i]);
			arg_files[i][0] = '\0';
		}
		i++;
	}
}

void ft_files_second(char **arg_files, t_ls f, void (*print)(char *, t_ls))
{
	unsigned int i;

	i = 0;
	while (arg_files[i])
	{
		if (ft_get_file_type(arg_files[i]) == '-')
		{
			print(arg_files[i], f);
			arg_files[i][0] = '\0';
		}
		i++;
	}
}

int ft_print_errno(char **argv, char *file_name)
{
	write(2, argv[0], ft_strlen(argv[0]));
	write(2, ": ", 2);
	write(2, file_name, ft_strlen(file_name));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return (FAIL);
}
