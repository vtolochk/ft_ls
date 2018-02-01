/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:38:21 by vtolochk          #+#    #+#             */
/*   Updated: 2017/11/23 11:16:58 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					flag;
	unsigned long int	result;

	result = 0;
	flag = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
		*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0' && ft_isdigit(*str) == 1)
	{
		result = (result * 10) + (*str - '0');
		if (result >= 9223372036854775807 && flag == 1)
			return (-1);
		else if (result > 9223372036854775807 && flag == -1)
			return (0);
		str++;
	}
	return ((int)result * flag);
}
