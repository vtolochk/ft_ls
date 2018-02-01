/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:53:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/27 11:21:34 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_data_init(t_flags *flags, t_width *width, t_prec *prec)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->zero = 0;
	width->wid = 0;
	width->star = 0;
	prec->prec = 0;
	prec->star = 0;
	prec->dot = 0;
}

void	ft_specifier_init(t_specif *specifier)
{
	specifier->s_sp = 0;
	specifier->big_s_sp = 0;
	specifier->c_sp = 0;
	specifier->big_c_sp = 0;
	specifier->d_sp = 0;
	specifier->i_sp = 0;
	specifier->big_d_sp = 0;
	specifier->o_sp = 0;
	specifier->big_o_sp = 0;
	specifier->u_sp = 0;
	specifier->big_u_sp = 0;
	specifier->x_sp = 0;
	specifier->big_x_sp = 0;
	specifier->p_sp = 0;
	specifier->percent = 0;
	specifier->fl_point_nb = 0;
}

void	ft_len_init(t_length *len)
{
	len->h_len = 0;
	len->hh_len = 0;
	len->l_len = 0;
	len->ll_len = 0;
	len->j_len = 0;
	len->z_len = 0;
}

void	ft_format_init(t_data *data)
{
	data->symb = 0;
	data->u_symb = 0;
	data->str = NULL;
	data->u_str = NULL;
	data->prefix = NULL;
	data->negative_nb = 0;
	data->need_free = 0;
}

void	ft_init_all(t_data *data)
{
	ft_data_init(&data->fl, &data->wid, &data->prec);
	ft_len_init(&data->len);
	ft_specifier_init(&data->spec);
	ft_format_init(data);
}
