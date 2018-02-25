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


static int skip_errors(int *i, char **arg_f)
{
	if (!arg_f[(*i)])
		return (1);
	(*i)++;
	while (arg_f[(*i)] && !(arg_f[(*i)][0]))
		(*i)++;
	if (!arg_f[(*i)])
		return (1);
	if (arg_f[(*i)])
		write(1, "\n", 1);
	return (0);
}

void ft_dirs_third(char **arg_f, void (*print)(char **, t_ls *), t_ls **f, int i)
{
	char            **dir_files;

	while (arg_f[i])
	{
		while (arg_f[i] && !(arg_f[i][0]))
			i++;
		if (arg_f[i] == NULL)
			return ;
		if (ft_get_file_type(arg_f[i]) == 'd')
		{
			if (ft_arr_len(arg_f) > 1)
				ft_printf("%s:\n", arg_f[i]);
			dir_files = ft_write_to_arr(arg_f[i], f);
			ft_ascii_sort(dir_files, (*f)->reverse);
			if ((*f)->time_sort == 1)
				ft_time_sort(dir_files, *f, arg_f[i]);
			(*f)->path_to_dir = ft_strdup(arg_f[i]);
			print(dir_files, *f);
			ft_free_tab((void**)dir_files);
			arg_f[i][0] = '\0';
		}
		if (skip_errors(&i, arg_f))
			return ;
	}
}
