/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:08:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/31 15:02:41 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_check_for_unb(t_data *data, va_list *ap, size_t *u_num)
{
	if (data->len.hh_len == 1 && data->spec.big_u_sp == 0
		&& data->spec.big_o_sp == 0)
	{
		*u_num = va_arg(*ap, unsigned int);
		*u_num = (unsigned char)*u_num;
	}
	else if (data->len.h_len == 1 && data->spec.big_u_sp == 0 &&
			data->spec.big_o_sp == 0)
	{
		*u_num = va_arg(*ap, unsigned int);
		*u_num = (unsigned short int)*u_num;
	}
	else if (data->len.l_len == 1 || data->spec.big_d_sp == 1 ||
			data->spec.big_o_sp == 1 || data->spec.big_u_sp == 1)
		*u_num = va_arg(*ap, unsigned long int);
	else if (data->len.ll_len == 1)
		*u_num = va_arg(*ap, unsigned long long int);
	else if (data->len.j_len == 1)
		*u_num = va_arg(*ap, uintmax_t);
	else if (data->len.z_len == 1)
		*u_num = va_arg(*ap, size_t);
	else
		*u_num = va_arg(*ap, unsigned int);
}

static int		ft_if_null(t_data *data, size_t unsigned_num)
{
	if (unsigned_num == 0 && data->prec.dot == 1)
	{
		ft_exit_printf(data);
		data->need_free = 0;
		data->str = NULL;
		data->flag = 1;
	}
	if (unsigned_num == 0 && data->prec.dot == 1 && data->fl.hash == 1 &&
		(data->spec.o_sp == 1 || data->spec.big_o_sp == 1))
	{
		ft_exit_printf(data);
		data->need_free = 0;
		data->str = "0";
	}
	return (0);
}

static int		ft_x_specif(t_data *data, size_t unsigned_num)
{
	if ((data->str = ft_itoa_base(unsigned_num, 16)) == NULL)
		return (-1);
	data->need_free = 1;
	ft_strtolower(&data->str);
	return (0);
}

static int		ft_big_x_specif(t_data *data, size_t unsigned_num)
{
	if ((data->str = ft_itoa_base(unsigned_num, 16)) == NULL)
		return (-1);
	data->need_free = 1;
	return (0);
}

int				ft_unumbers(t_data *d, va_list *ap, size_t unsigned_num)
{
	ft_check_for_unb(d, ap, &unsigned_num);
	if ((d->spec.u_sp == 1 || d->spec.big_u_sp == 1 || d->len.z_len == 1)
		&& (d->spec.o_sp == 0 && d->spec.big_o_sp == 0 &&
		d->spec.x_sp == 0 && d->spec.big_x_sp == 0))
	{
		if ((d->str = ft_itoa_base(unsigned_num, 10)) == NULL)
			return (-1);
		d->need_free = 1;
	}
	else if (d->spec.o_sp == 1 || d->spec.big_o_sp == 1)
	{
		if ((d->str = ft_itoa_base(unsigned_num, 8)) == NULL)
			return (-1);
		d->need_free = 1;
	}
	else if (d->spec.x_sp == 1)
	{
		if (ft_x_specif(d, unsigned_num) == -1)
			return (-1);
	}
	else if (d->spec.big_x_sp == 1)
		if (ft_big_x_specif(d, unsigned_num) == -1)
			return (-1);
	return (ft_if_null(d, unsigned_num));
}
