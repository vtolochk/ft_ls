/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:06:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/18 15:06:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_one_print(char **file, t_ls *data)
{
	unsigned int i;

	i = 0;
	while (file[i])
	{
		ft_printf("%s\n", file[i]);
		i++;
	}
	data->big_g = 0;
}