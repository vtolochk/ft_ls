/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:15:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/27 11:46:46 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		i += ft_putchar(*str, 1);
		str++;
	}
	return (i);
}
