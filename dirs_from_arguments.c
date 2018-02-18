/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs_from_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:21:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/15 19:21:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_dirs_third(char **arg_files, void (*print)(char **, t_ls *), t_ls **f)
{
	unsigned int    i;
	char            **dir_files;

	i = 0;
	while (arg_files[i])
	{
		while (arg_files[i] && !(arg_files[i][0]))
			i++;
		if (ft_get_file_type(arg_files[i]) == 'd')
		{
			if (ft_arr_len(arg_files) > 1)
				ft_printf("%s:\n", arg_files[i]);
			dir_files = ft_write_to_arr(arg_files[i], f);
			ft_ascii_sort(dir_files);
			(*f)->path_to_dir = ft_strdup(arg_files[i]);
			print(dir_files, *f);
			ft_free_tab((void**)dir_files);
			arg_files[i][0] = '\0';
		}
		if (!arg_files[i++])
			return ;
	}
}
