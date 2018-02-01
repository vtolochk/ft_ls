/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:10:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/31 15:20:38 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_uputstr(unsigned int *str)
{
	unsigned int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		i += ft_putchar(*str);
		str++;
	}
	return (i);
}
