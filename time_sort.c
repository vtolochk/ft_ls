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

static int ft_timecmp(char *file_1, char *file_2, char *arg_path, t_ls *f)
{
	struct stat status_1;
	struct stat status_2;
	char *temp;

	arg_path = ft_strjoin(arg_path, "/");
	temp = ft_strjoin(arg_path, file_1);
	if (!temp)
		temp = ft_strdup(file_1);
	if (lstat(temp, &status_1) == -1)
	{
		free(temp);
		temp = ft_strjoin(arg_path, "/");
		temp = ft_strjoin(temp, file_1);
		lstat(temp, &status_1);
	}
	free(temp);
	temp = ft_strjoin(arg_path, file_2);
	if (!temp)
		temp = ft_strdup(file_2);
	if (lstat(temp, &status_2) == -1)
	{
		free(temp);
		temp = ft_strjoin(arg_path, "/");
		temp = ft_strjoin(temp, file_2);
		lstat(temp, &status_2);
	}
	free(temp);
	if (status_1.st_mtimespec.tv_sec < status_2.st_mtimespec.tv_sec)
		return (1);
	else if (status_1.st_mtimespec.tv_sec == status_2.st_mtimespec.tv_sec)
	{
		if (status_1.st_mtimespec.tv_nsec < status_2.st_mtimespec.tv_nsec)
			return (1);
		else if (status_1.st_mtimespec.tv_nsec == status_2.st_mtimespec.tv_nsec &&
				(f->recursion == 1 && f->reverse == 1))
			return (1);
		else if (status_1.st_mtimespec.tv_nsec == status_2.st_mtimespec.tv_nsec)
			return (0);
	}
	return (0);
}

static void ft_rev_time(char **arr, char *arg_path, unsigned int len, t_ls *f)
{
	unsigned int    i;
	unsigned int    j;
	char            *tmp;

	i = 0;
	while (i != len - 1)
	{
		j = 0;
		while (j != len - i - 1)
		{
			if (ft_timecmp(arr[j], arr[j + 1], arg_path, f) == 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void ft_time_sort(char **arr, t_ls *f, char *arg_path)
{
	unsigned int    i;
	unsigned int    j;
	unsigned int    len;
	char            *tmp;

	i = 0;
	len = ft_arr_len(arr);
	if (f->reverse)
	{
		ft_rev_time(arr,  arg_path, len, f);
		return ;
	}
	while (i != len - 1)
	{
		j = 0;
		while (j != len - i - 1)
		{
			if (ft_timecmp(arr[j], arr[j + 1], arg_path, f))
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
