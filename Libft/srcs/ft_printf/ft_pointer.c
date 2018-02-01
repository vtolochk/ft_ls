/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:13:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/28 13:19:44 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pointer(t_data *data, va_list *ap)
{
	size_t	ptr;

	ptr = va_arg(*ap, size_t);
	if ((data->str = ft_itoa_base(ptr, 16)) == NULL)
		return (-1);
	data->need_free = 1;
	if (ft_strcmp(data->str, "0") == 0 && data->prec.dot == 1)
	{
		ft_exit_printf(data);
		data->need_free = 0;
		data->str = NULL;
	}
	if (ft_strcmp(data->str, "0") == 0 && data->prec.dot == 1 &&
		data->fl.hash == 1)
	{
		ft_exit_printf(data);
		data->need_free = 0;
		data->str = "0";
		data->flag = 1;
	}
	ft_strtolower(&data->str);
	return (0);
}
