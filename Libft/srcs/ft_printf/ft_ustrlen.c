/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:54:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/27 11:40:45 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_ustrlen(unsigned int *str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}
