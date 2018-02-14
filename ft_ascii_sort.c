/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:29:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/10 16:29:00 by vtolochk         ###   ########.fr       */
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
static unsigned int ft_arr_len(char **arr)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = 0;
	while (arr[i++])
		len++;
	return (len);
}

void ft_ascii_sort(char **arr)
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
		while (j != len)
		{
			if (ft_strcmp(arr[j], arr[j+1]) > 0)
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