/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 12:59:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/31 16:28:01 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_check_for_snumbers(t_data *data, va_list *ap, ssize_t *s_num)
{
	if (data->len.hh_len == 1 && data->spec.big_d_sp == 0)
	{
		*s_num = va_arg(*ap, int);
		*s_num = (char)*s_num;
	}
	else if (data->len.h_len == 1 && data->spec.big_d_sp == 0)
	{
		*s_num = va_arg(*ap, int);
		*s_num = (short int)*s_num;
	}
	else if (data->len.l_len == 1 || data->spec.big_d_sp == 1)
		*s_num = va_arg(*ap, long int);
	else if (data->len.ll_len == 1)
		*s_num = va_arg(*ap, long long int);
	else if (data->len.j_len == 1)
		*s_num = va_arg(*ap, intmax_t);
	else if (data->len.z_len == 1)
		*s_num = va_arg(*ap, ssize_t);
	else
		*s_num = va_arg(*ap, int);
}

int				ft_snumbers(t_data *data, va_list *ap)
{
	ssize_t signed_num;

	signed_num = 0;
	ft_check_for_snumbers(data, ap, &signed_num);
	if (signed_num < 0)
	{
		data->negative_nb = 1;
		signed_num = -signed_num;
	}
	if ((data->str = ft_itoa_base(signed_num, 10)) == NULL)
		return (-1);
	data->need_free = 1;
	if (signed_num == 0 && data->prec.dot == 1)
	{
		ft_exit_printf(data);
		data->str = NULL;
		data->need_free = 0;
		data->flag = 1;
	}
	return (0);
}
