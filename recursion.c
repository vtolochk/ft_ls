/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:18:15 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 13:19:49 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	join_dirs(char **f_arr, unsigned int *i, char **next, char *name)
{
	char *temp;

	if (ft_strncmp(f_arr[(*i)], ".", 2) == 0)
		(*i)++;
	if (ft_strncmp(f_arr[(*i)], "..", 3) == 0)
		(*i)++;
	if (ft_strncmp(f_arr[(*i)], ".", 2) == 0)
		(*i)++;
	if (!(f_arr[(*i)]))
	{
		ft_free_tab((void **)f_arr);
		return (1);
	}
	temp = ft_strjoin(name, "/");
	*next = ft_strjoin(temp, f_arr[(*i)]);
	free(temp);
	(*i) += 1;
	return (OK);
}

static int	if_dir_is_empty(char *dir_name, t_ls **f, char **files_arr)
{
	ft_printf("%s:\n", dir_name);
	if ((*f)->arg_nb > 1 && (*f)->first_dir == 1 && (*f)->double_minus == 0)
		write(1, "\n", 1);
	(*f)->first_dir = 0;
	ft_free_tab((void **)files_arr);
	return (OK);
}

static void	pt_a_srt(t_ls **f, char *d, char **f_a, void (*p)(char **, t_ls *))
{
	if ((ft_arr_len(f_a) > 0 || (*f)->arg_nb > 2) &&
	((*f)->first_dir == 0 || (*f)->arg_nb != 1))
		ft_printf("%s:\n", d);
	if (!((*f)->f))
		ft_ascii_sort(f_a, (*f)->reverse);
	if ((*f)->time_sort == 1 && !((*f)->f))
		ft_time_sort(f_a, *f, d);
	ft_strdel(&((*f)->path_to_dir));
	(*f)->path_to_dir = ft_strdup(d);
	p(f_a, *f);
	(*f)->printed = 1;
}

static void	norma(t_ls **f)
{
	write(1, "\n", 1);
	(*f)->first_dir = 0;
}

int			ft_dirwalk(char *dir_name, void (*print)(char **, t_ls *), t_ls **f)
{
	char			*next_dir;
	char			**files_arr;
	unsigned int	i;

	i = 0;
	if (!dir_name || !dir_name[0])
		return (OK);
	if (!(files_arr = ft_write_to_arr(dir_name, f)))
		return ((*f)->next_dir == 1 ? OK : FAIL);
	if (*files_arr == NULL)
		return (if_dir_is_empty(dir_name, f, files_arr));
	pt_a_srt(f, dir_name, files_arr, print);
	while (files_arr[i])
	{
		if (join_dirs(files_arr, &i, &next_dir, dir_name) == 1)
			return (OK);
		if (ft_isdir(next_dir, *f, files_arr))
		{
			norma(f);
			ft_dirwalk(next_dir, print, f);
		}
		free(next_dir);
	}
	ft_free_tab((void**)files_arr);
	return (OK);
}
