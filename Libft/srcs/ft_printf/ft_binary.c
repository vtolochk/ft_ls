/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 11:24:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/31 15:03:56 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_bin_specif(const char **format, va_list *ap)
{
	char	*str;
	size_t	val;
	size_t	str_len;

	val = 0;
	if (**format == 'b')
	{
		(*format)++;
		val = va_arg(*ap, size_t);
		str = ft_itoa_base(val, 2);
		str_len = ft_strlen(str);
		write(1, str, str_len);
		free(str);
		return (str_len);
	}
	return (-1);
}
