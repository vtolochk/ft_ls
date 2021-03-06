/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:29:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 14:26:20 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned int		ft_arr_len(char **arr)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (!arr)
		return (0);
	while (arr[i++])
		len++;
	return (len);
}

static void			ft_swap(char **arr, int j)
{
	char *temp;

	temp = arr[j];
	arr[j] = arr[j + 1];
	arr[j + 1] = temp;
}

static void			ft_reverse_ascii(char **arr, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i != len - 1)
	{
		j = 0;
		while (j != len - i - 1)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) < 0)
				ft_swap(arr, j);
			j++;
		}
		i++;
	}
}

void				ft_ascii_sort(char **arr, char reverse)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	if ((len = ft_arr_len(arr)) == 0)
		return ;
	if (reverse)
		ft_reverse_ascii(arr, len);
	else
	{
		while (i != len - 1)
		{
			j = 0;
			while (j != len - i - 1)
			{
				if (ft_strcmp(arr[j], arr[j + 1]) > 0)
					ft_swap(arr, j);
				j++;
			}
			i++;
		}
	}
}
