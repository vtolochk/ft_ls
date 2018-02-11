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

	ft_memcpy(tmp, arr[index_1], sizeof(tmp));
	ft_memcpy(arr[index_1], arr[index_2], sizeof(arr[index_1]));
	ft_memcpy(arr[index_2], tmp, sizeof(arr[index_2]));
}

void ft_ascii_sort(char **arr)      //u could make it faster
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (arr[i++])
		len++;
	if (!len)
		return ;
	i = 0;
	while (i != len)
	{
		if (!arr[i + 1])
			return ;
		if (ft_strcmp(arr[i], arr[i+1]) > 0)
		{
			ft_swap(arr, i, i + 1);
			i = 0;
			continue;
		}
		i++;
	}
}