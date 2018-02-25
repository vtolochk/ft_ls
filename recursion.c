/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:01:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/11 15:01:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int join_dirs(char **files_arr, unsigned int *i, char **next_dir, char *dir_name)
{
	char *temp;

	if (ft_strncmp(files_arr[(*i)], ".", 2) == 0)
		(*i)++;
	if (ft_strncmp(files_arr[(*i)], "..", 3) == 0)
		(*i)++;
	if (ft_strncmp(files_arr[(*i)], ".", 2) == 0)
		(*i)++;
	if (!(files_arr[(*i)]))
		return (1);
	temp = ft_strjoin(dir_name, "/");
	*next_dir = ft_strjoin(temp, files_arr[(*i)]);
	free(temp);
	(*i) += 1;
	return (OK);
}

static int if_dir_is_empty(char *dir_name, t_ls **f)
{
	ft_printf("%s:\n", dir_name);
	if ((*f)->arg_nb > 1 && (*f)->first_dir == 1 && (*f)->double_minus == 0)
		write(1, "\n", 1);
	(*f)->first_dir = 0;
	return (OK);
}

static void print_and_sort(t_ls **f, char *dir_name, char **files_arr, void (*print)(char **, t_ls *))
{
	if ((ft_arr_len(files_arr) > 0 || (*f)->arg_nb > 2) && ((*f)->first_dir == 0 || (*f)->arg_nb != 1))
		ft_printf("%s:\n", dir_name);
	ft_ascii_sort(files_arr, (*f)->reverse);
	if ((*f)->time_sort == 1)
		ft_time_sort(files_arr, *f, dir_name);
	(*f)->path_to_dir = ft_strdup(dir_name);
	print(files_arr, *f);
	(*f)->printed = 1;
}

int ft_dirwalk(char *dir_name, void (*print)(char **, t_ls *), t_ls **f)
{
	char *next_dir;
	char **files_arr;
	unsigned int i;

	i = 0;
	if (!dir_name || !dir_name[0])
		return (OK);
	if (!(files_arr = ft_write_to_arr(dir_name, f)))
		return ((*f)->next_dir == 1 ? OK : FAIL);
	if (*files_arr == NULL)
		return (if_dir_is_empty(dir_name, f));
	print_and_sort(f, dir_name, files_arr, print);
	while (files_arr[i])
	{
		if (join_dirs(files_arr, &i, &next_dir, dir_name) == 1)
			return (OK);
		if (ft_isdir(next_dir, *f, files_arr))
		{
			write(1, "\n", 1);
			(*f)->first_dir = 0;
			ft_dirwalk(next_dir, print, f);
		}
		free(next_dir);
	}
	ft_free_tab((void**)files_arr);
	return (OK);
}


