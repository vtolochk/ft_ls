/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_act_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:05:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/27 12:20:33 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_get_act_bits(unsigned int c)
{
	int i;
	int size;

	i = 1;
	size = 0;
	while (i != 33)
	{
		if ((c & 1) == 1)
			size = i;
		c >>= 1;
		i++;
	}
	return (size);
}
