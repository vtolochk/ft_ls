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

void ft_dirs_third(char **arg_files, void (*print)(char *))
{
	unsigned int    i;
	unsigned int    j;
	char            **dir_files;

	i = 0;
	while (arg_files[i])
	{
		j = 0;
		while (arg_files[i] && !(arg_files[i][0]))
			i++;
		if (ft_get_file_type(arg_files[i]) == 'd')
		{
			if (ft_arr_len(arg_files) > 1)
				ft_printf("%s:\n", arg_files[i]);
			dir_files = ft_write_to_arr(arg_files[i]);
			ft_ascii_sort(dir_files);
			while (dir_files[j])
				print(dir_files[j++]);
			ft_free_tab((void**)dir_files);
			arg_files[i][0] = '\0';
		}
		if (!arg_files[i++])
			return ;
	}
}
