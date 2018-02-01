/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:09:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/27 12:19:20 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_prefix(t_data *d, int len)
{
	if (d->fl.hash == 1)
	{
		if (d->spec.o_sp == 1 || d->spec.big_o_sp == 1)
			d->prefix = d->prec.prec >= len + 1 ? 0 : "0";
		else if (d->spec.x_sp == 1)
			d->prefix = "0x";
		else if (d->spec.big_x_sp == 1)
			d->prefix = "0X";
	}
	if (d->spec.big_d_sp == 1 || d->spec.d_sp == 1 || d->spec.i_sp == 1 ||
		d->spec.u_sp == 1 || d->spec.fl_point_nb == 1)
	{
		d->prefix = d->negative_nb == 1 ? "-" : 0;
		if (d->fl.plus == 1)
			d->prefix = d->negative_nb == 1 ? "-" : "+";
	}
	if ((ft_strcmp(d->str, "0") == 0 && d->fl.plus == 0) ||
		(d->spec.u_sp == 1 && d->fl.plus == 1))
		d->prefix = 0;
	if ((d->spec.d_sp == 1 || d->spec.i_sp == 1 || d->spec.fl_point_nb == 1) &&
		d->fl.space == 1 && d->prefix == 0 && d->negative_nb == 0)
		d->prefix = " ";
	if (d->spec.p_sp == 1)
		d->prefix = "0x";
}
