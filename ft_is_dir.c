/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:17:01 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 15:46:35 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_write_dir_or_error(char *dir, char **files_arr, t_ls *f)
{
	char *temp;

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
		ft_print_errno(++temp);
	}
}

char			ft_isdir(char *dir, t_ls *f, char **files_arr)
{
	DIR *ptr;

	if (ft_is_link(dir) == 0)
		return (0);
	if ((ptr = opendir(dir)))
	{
		if (readdir(ptr))
		{
			closedir(ptr);
			return (1);
		}
	}
	else
		ft_write_dir_or_error(dir, files_arr, f);
	return (0);
}
