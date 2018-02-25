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

char *l_v(char *file)
{
	char *buf;

	buf = ft_strnew(127);
	readlink(file, buf, 126);
	return (buf);
}

void ft_error_first(char **arg_files, t_ls *f)
{
	int i;
	int len;

	i = 0;
	len = ft_arr_len(arg_files);
	f->big_g = 0; // u have to color this shit in red :)
	while (arg_files[i])
	{
		if ((ft_get_file_type(arg_files[i])) == 'e')
		{
			ft_print_errno(arg_files[i]);
			arg_files[i][0] = '\0';
		}
		if ((ft_get_file_type(arg_files[i])) == 'd' && ft_check_for_perm(arg_files[i]))
		{
			ft_print_no_perm(len, arg_files, i);
			arg_files[i][0] = '\0';
		}
		i++;
	}
}

int ft_print_errno(char *file_name)
{
	write(2, "ls: ", 4);
	write(2, file_name, ft_strlen(file_name));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return (FAIL);
}
