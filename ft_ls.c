/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:58:05 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/07 10:55:35 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char ft_get_file_type(char *file_name)
{
	struct stat file_stat;

	if (stat(file_name, &file_stat) == -1)
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
	return ('-');
}

int ft_ls(int argc, char **argv)
{
	t_ls_flgs flags;
	char **arg_files;

	if (ft_get_flags(argc, argv, &flags))
		return (ERROR);
	arg_files = ft_get_arg_files(argc, argv);
	ft_ascii_sort(arg_files);
	ft_error_first(argv, arg_files);
	ft_files_second(argv, arg_files);
	ft_dirs_third(argv, arg_files);

	return (SUCCESS);
}

int main(int argc, char **argv)
{
	return (ft_ls(argc, argv));
}
