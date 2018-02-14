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

void ft_error_first(char **argv, char **arg_files)
{
	int i;

	i = 0;
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

void ft_files_second (char **argv, char **arg_files) // later you will need to add pointer to func
{                                                    // which will print long or simple format
	int i;
	char file_type;

	i = 0;
	while (arg_files[i])
	{
		if (arg_files[i][0] == '\0')
		{
			i++;
			continue ;
		}
		if ((file_type = ft_get_file_type(arg_files[i])) == '-')
		{
			ft_ls_print(arg_files[i], argv, file_type);
			arg_files[i][0] = '\0';
		}
		i++;
	}
}

void ft_dirs_third(char **argv, char **arg_files)
{
	int i;
	char file_type;

	i = 0;
	while (arg_files[i])
	{
		if (arg_files[i][0] == '\0')
		{
			i++;
			continue ;
		}
		file_type = ft_get_file_type(arg_files[i]);
		ft_printf("%s:\n", arg_files[i]); // only if -R flag
		ft_ls_print(arg_files[i], argv, file_type);
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
