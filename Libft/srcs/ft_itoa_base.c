/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:15:35 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/08 16:05:09 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_write_to_arr(size_t val, size_t base, size_t *i, char *arr)
{
	char *s;

	s = "0123456789ABCDEF";
	if (val >= base)
		ft_write_to_arr(val / base, base, i, arr);
	arr[*i] = s[val % base];
	*i += 1;
}

char			*ft_itoa_base(size_t value, size_t base)
{
	char	*res;
	size_t	i;

	i = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (!(res = (char *)malloc(33 * sizeof(char))))
		return (NULL);
	ft_write_to_arr(value, base, &i, res);
	res[i] = '\0';
	return (res);
}
