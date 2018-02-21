/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:27:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/21 18:27:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void ft_swap(char **arr, int index_1, int index_2)
{
	char *tmp[2];

	tmp[0] = ft_strdup(arr[index_1]);
	tmp[1] = ft_strdup(arr[index_2]);
	free(arr[index_1]);
	free(arr[index_2]);
	arr[index_1] = tmp[1];
	arr[index_2] = tmp[0];
}

static int ft_timecmp(char *file_1, char *file_2, t_ls *f)
{
	struct stat status_1;
	struct stat status_2;
	char *temp;

	temp = ft_strjoin(f->path_to_dir, file_1);
	lstat(temp, &status_1);
	free(temp);
	temp = ft_strjoin(f->path_to_dir, file_2);
	lstat(temp, &status_2);
	free(temp);
	if (status_1.st_mtimespec.tv_sec >= status_2.st_mtimespec.tv_sec)
		return (1);
	return (0);
}

void ft_time_sort(char **arr, t_ls *f)
{
	unsigned int    i;
	unsigned int    j;
	unsigned int    len;
	char            flag;

	i = 0;
	len = ft_arr_len(arr);
	while (i != len - 1)
	{
		j = 0;
		flag = 0;
		while (j != (len - i))
		{
			if (ft_timecmp(arr[j], arr[j + 1], f) == 1)
			{
				ft_swap(arr, j, j + 1);
				flag = 1;
			}
			j++;
		}
		if (!flag)
			return ;
		i++;
	}
}
