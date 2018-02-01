/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:13:52 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/28 14:14:01 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_found_spec(t_data data)
{
	if (data.spec.s_sp == 1 || data.spec.big_s_sp == 1 || data.spec.c_sp == 1 ||
		data.spec.big_c_sp == 1 || data.spec.d_sp == 1 || data.spec.i_sp == 1 ||
		data.spec.big_d_sp == 1 || data.spec.o_sp == 1 ||
		data.spec.big_o_sp == 1 || data.spec.u_sp == 1 ||
		data.spec.big_u_sp == 1 || data.spec.x_sp == 1 ||
		data.spec.big_x_sp == 1 || data.spec.p_sp == 1 ||
		data.spec.percent == 1 || data.spec.fl_point_nb == 1)
		return (1);
	return (0);
}

int		ft_isvalid(const char *format)
{
	if (*format != '#' && *format != '0' && *format != '-' &&
		*format != '+' && *format != ' ' && ft_isdigit(*format) == 0 &&
		*format != 's' && *format != 'S' && *format != 'p' && *format != 'd' &&
		*format != 'D' && *format != 'i' && *format != 'o' && *format != 'O' &&
		*format != 'u' && *format != 'U' && *format != 'x' && *format != 'X' &&
		*format != 'c' && *format != 'C' && *format != '.' && *format != '%' &&
		*format != 'f' && *format != 'F')
		return (1);
	return (0);
}

int		ft_found_spec_nb(t_data data)
{
	if (data.spec.d_sp == 1 || data.spec.i_sp == 1 || data.spec.big_d_sp == 1 ||
		data.spec.o_sp == 1 || data.spec.big_o_sp == 1 || data.spec.u_sp == 1 ||
		data.spec.big_u_sp == 1 || data.spec.x_sp == 1 ||
		data.spec.big_x_sp == 1 || data.spec.fl_point_nb == 1)
		return (1);
	return (0);
}
