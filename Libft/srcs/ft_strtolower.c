/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:33:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/27 11:42:56 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strtolower(char **str)
{
	size_t i;

	i = 0;
	if (!str || *str == NULL)
		return ;
	while (**str)
	{
		i++;
		**str = ft_tolower(**str);
		(*str)++;
	}
	*str = *str - i;
}
