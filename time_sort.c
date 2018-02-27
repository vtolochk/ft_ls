/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:27:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 13:17:54 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_get_time(char *file, char *arg_path, struct stat *status)
{
	char		*temp;
	char		*temp_2;

	if (lstat(file, status) == -1)
	{
		ft_strdel(&file);
		temp = ft_strjoin(arg_path, "/");
		temp_2 = file;
		file = ft_strjoin(temp, file);
		ft_strdel(&temp_2);
		lstat(temp, status);
	}
}

static int		ft_timecmp(char *file_1, char *file_2, char *arg_path, t_ls *f)
{
	struct stat	stat_1;
	struct stat stat_2;
	char		*temp;

	arg_path = ft_strjoin(arg_path, "/");
	temp = ft_strjoin(arg_path, file_1);
	if (!temp)
		temp = ft_strdup(file_1);
	ft_get_time(temp, arg_path, &stat_1);
	temp = ft_strjoin(arg_path, file_2);
	if (!temp)
		temp = ft_strdup(file_2);
	ft_get_time(temp, arg_path, &stat_2);
	return (ls_time_cmp(stat_1, stat_2, f));
}

static void		ft_swap(char **arr, int j)
{
	char *temp;

	temp = arr[j];
	arr[j] = arr[j + 1];
	arr[j + 1] = temp;
}

static void		ft_rev_time(char **arr, char *a_path, unsigned int len, t_ls *f)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i != len - 1)
	{
		j = 0;
		while (j != len - i - 1)
		{
			if (ft_timecmp(arr[j], arr[j + 1], a_path, f) == 0)
				ft_swap(arr, j);
			j++;
		}
		i++;
	}
}

void			ft_time_sort(char **arr, t_ls *f, char *arg_path)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	if ((len = ft_arr_len(arr)) == 0)
		return ;
	if (f->reverse)
	{
		ft_rev_time(arr, arg_path, len, f);
		return ;
	}
	while (i != len - 1)
	{
		j = 0;
		while (j != len - i - 1)
		{
			if (ft_timecmp(arr[j], arr[j + 1], arg_path, f))
				ft_swap(arr, j);
			j++;
		}
		i++;
	}
}
