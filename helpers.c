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

char ft_isdir(char *dir, t_ls *f, char **files_arr)
{
	DIR *ptr;
	char *temp;

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
			ft_print_errno(f->argv_temp, ++temp);
		}
	}
	return (0);
}

void ft_error_first(char **argv, char **arg_files, t_ls *f)
{
	int i;

	i = 0;
	f->big_g = 0; // u have to color this shit in red :)
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
			temp_arg_files[k] = ft_strdup(arg_files[i]);
			arg_files[i][0] = '\0';
			k++;
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
	ft_free_tab((void**)temp_arg_files);
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
