/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 13:30:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/27 12:34:18 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_for_spec_symb(t_specif *spec, const char **format)
{
	if (**format == 's')
		spec->s_sp = 1;
	else if (**format == 'S')
		spec->big_s_sp = 1;
	else if (**format == 'c')
		spec->c_sp = 1;
	else if (**format == 'C')
		spec->big_c_sp = 1;
	if (spec->s_sp == 1 || spec->big_s_sp == 1 || spec->c_sp == 1 ||
		spec->big_c_sp == 1)
		(*format)++;
}

void	ft_check_for_spec_nb(t_specif *spec, const char **format)
{
	if (**format == 'd')
		spec->d_sp = 1;
	else if (**format == 'i')
		spec->i_sp = 1;
	else if (**format == 'D')
		spec->big_d_sp = 1;
	else if (**format == 'o')
		spec->o_sp = 1;
	else if (**format == 'O')
		spec->big_o_sp = 1;
	else if (**format == 'u')
		spec->u_sp = 1;
	else if (**format == 'U')
		spec->big_u_sp = 1;
	else if (**format == 'x')
		spec->x_sp = 1;
	else if (**format == 'X')
		spec->big_x_sp = 1;
	if (spec->d_sp == 1 || spec->i_sp == 1 || spec->big_d_sp == 1 ||
		spec->o_sp == 1 || spec->big_o_sp == 1 || spec->u_sp == 1 ||
		spec->big_u_sp == 1 || spec->x_sp == 1 || spec->big_x_sp == 1)
		(*format)++;
}

void	ft_check_for_spec_oth(t_specif *spec, const char **format)
{
	if (**format == 'p')
		spec->p_sp = 1;
	else if (**format == '%')
		spec->percent = 1;
	else if (**format == 'f' || **format == 'F')
		spec->fl_point_nb = 1;
	if (spec->p_sp == 1 || spec->percent == 1 || spec->fl_point_nb == 1)
		(*format)++;
}
