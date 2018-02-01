/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 13:59:33 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/31 15:03:26 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_if_null(t_data *data)
{
	data->str = "(null)";
	if (data->prec.prec > 0 || data->prec.dot == 1)
	{
		if ((data->str = ft_strsub(data->str, 0, data->prec.prec)) == NULL)
			return (-1);
		data->need_free = 1;
	}
	return (0);
}

static int		ft_get_ustr(t_data *data, va_list *ap)
{
	data->u_str = va_arg(*ap, unsigned int*);
	if (data->prec.prec > 0 || data->prec.dot == 1)
	{
		if ((data->u_str = ft_ustrsub(data->u_str, 0, data->prec.prec)) == NULL)
			return (-1);
		data->need_free = 1;
	}
	return (0);
}

int				ft_str_spec(t_data *d, va_list *ap)
{
	if (d->spec.s_sp == 1 && d->len.l_len != 1)
	{
		d->str = va_arg(*ap, char *);
		if (d->prec.prec > 0 || d->prec.dot == 1)
		{
			if (d->prec.prec < 0)
				d->prec.prec = -d->prec.prec;
			if (d->str != NULL)
				if ((d->str = ft_strsub(d->str, 0, d->prec.prec)) == NULL)
					return (-1);
			d->need_free = 1;
		}
	}
	else if (d->spec.big_s_sp == 1 ||
			(d->spec.s_sp == 1 && d->len.l_len == 1))
	{
		if (ft_get_ustr(d, ap) == -1)
			return (-1);
	}
	if (d->str == NULL && d->u_str == NULL)
		if (ft_if_null(d) == -1)
			return (-1);
	return (0);
}
