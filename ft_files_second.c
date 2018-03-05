/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:15:47 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 16:44:44 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_get_dir(char **temp_argv, char **arg_files, int *i, int *k)
{
	char		*buf;
	struct stat inf;

	buf = ft_strnew(127);
	readlink(arg_files[(*i)], buf, 127);
	lstat(buf, &inf);
	if (S_ISDIR(inf.st_mode))
	{
		arg_files[(*i)] = buf;
		return ;
	}
	temp_argv[(*k)] = ft_strdup(arg_files[(*i)]);
	arg_files[(*i)][0] = '\0';
	(*k)++;
	ft_strdel(&buf);
}

static void		ft_free_and_print_nl(char **files, int k, int i)
{
	if (i > k && k > 1)
		write(1, "\n", 1);
	ft_free_tab((void**)files);
}

static void		write_arr(char **tmp_arg_files, char **arg_files, int *k, int i)
{
	tmp_arg_files[*k] = ft_strdup(arg_files[i]);
	(*k)++;
	arg_files[i][0] = '\0';
}

void			fls_sc(char **arg, t_ls *f, void (*pt)(char **, t_ls *), int k)
{
	int		i;
	char	**temp_arg_files;

	i = -1;
	temp_arg_files = (char **)malloc((ft_arr_len(arg) + 1) * (sizeof(char *)));
	while (arg[++i])
	{
		if (ft_get_file_type(arg[i]) == '-' || ft_get_file_type(arg[i]) == 'c')
		{
			if (ft_is_link(arg[i]) == 0 && f->list == 0)
				ft_get_dir(temp_arg_files, arg, &i, &k);
			else
				write_arr(temp_arg_files, arg, &k, i);
		}
	}
	temp_arg_files[k] = NULL;
	if (ft_strncmp(arg[0], ".", 2) == 0 && arg[1] == NULL)
		ft_free_tab((void**)temp_arg_files);
	else
	{
		pt(temp_arg_files, f);
		ft_free_and_print_nl(temp_arg_files, k, i);
	}
}
