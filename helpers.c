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

void ft_error_first(char **argv, char **arg_files)
{
	int i;

	i = 0;
	while (arg_files[i])
	{
		if ((ft_get_file_type(arg_files[i])) == 'e')
		{
			ft_print_error(argv, arg_files[i]);
			free(arg_files[i]);
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
			free(arg_files[i]);
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
		ft_ls_print(arg_files[i], argv, file_type);
		i++;
	}
}

int ft_print_error(char **argv, char *file_name)
{
	ft_printf("%s: %s: %s\n", argv[0], file_name, strerror(errno));
	return (ERROR);
}
