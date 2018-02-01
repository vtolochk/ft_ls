/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_and_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:46:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/31 15:23:21 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_characters(t_data data)
{
	int ret;

	ret = 0;
	if (data.symb != 0 || (data.symb == 0 && data.u_symb == 0))
		data.wid.wid = data.wid.wid - 1;
	else if (data.u_symb != 0)
		data.wid.wid = data.wid.wid - ft_get_bytes(data.u_symb);
	if (data.wid.wid > 0 && data.fl.minus == 0)
	{
		if (data.fl.zero == 0)
			ft_put(' ', data.wid.wid);
		else
			ft_put('0', data.wid.wid);
		ret = data.wid.wid;
	}
	if (data.u_symb != 0 && MB_CUR_MAX > 1)
		ret += ft_putchar(data.u_symb);
	else if (data.u_symb != 0)
		ret += write(1, &data.u_symb, 1);
	else
		ret += write(1, &data.symb, 1);
	if (data.wid.wid > 0 && data.fl.minus == 1)
		ret += ft_put(' ', data.wid.wid);
	return (ret);
}

static int		ft_strings(t_data dat, size_t i, int str_len)
{
	int ret;

	ret = 0;
	if (dat.str != NULL)
		dat.wid.wid = dat.wid.wid - str_len;
	else if (dat.u_str != NULL)
	{
		while (dat.u_str[i++] != '\0')
			ret += ft_get_bytes(*dat.u_str);
		dat.wid.wid = dat.wid.wid - ret;
		ret = 0;
	}
	if (dat.wid.wid > 0 && dat.fl.minus == 0)
	{
		dat.fl.zero == 0 ? ft_put(' ', dat.wid.wid) : ft_put('0', dat.wid.wid);
		ret = dat.wid.wid;
	}
	if (dat.u_str != NULL)
		ret += ft_uputstr(dat.u_str);
	else
		ret += write(1, dat.str, str_len);
	if (dat.wid.wid > 0 && dat.fl.minus == 1)
		ret += ft_put(' ', dat.wid.wid);
	return (ret);
}

static int		ft_if_minus(t_data data, int pref_len, int str_len, int *flag)
{
	int ret;

	ret = 0;
	if (data.fl.zero == 1 && data.prec.prec == str_len)
	{
		*flag = 1;
		ret += write(1, data.prefix, pref_len);
		ret += ft_put('0', data.wid.wid - pref_len - data.prec.prec);
	}
	else
		ret += ft_put(' ', data.wid.wid - pref_len - data.prec.prec);
	if (*flag == 0)
		ret += write(1, data.prefix, pref_len);
	while (data.prec.prec != str_len)
	{
		ret += write(1, "0", 1);
		data.prec.prec--;
	}
	ret += write(1, data.str, str_len);
	return (ret);
}

static int		ft_numbers(t_data data, int str_len, int ret)
{
	int pref_len;
	int flag;

	flag = 0;
	pref_len = ft_strlen(data.prefix);
	if (data.prec.prec > 0 && (data.spec.i_sp == 1 || data.spec.d_sp == 1 ||
		data.spec.o_sp == 1 || data.spec.x_sp == 1 || data.spec.big_x_sp == 1))
		data.fl.zero = 0;
	if (data.prec.prec < str_len)
		data.prec.prec = str_len;
	if (data.fl.minus == 0)
		ret += ft_if_minus(data, pref_len, str_len, &flag);
	else
	{
		ret += write(1, data.prefix, pref_len);
		flag = data.prec.prec;
		while (data.prec.prec != str_len)
		{
			ret += write(1, "0", 1);
			data.prec.prec--;
		}
		ret += write(1, data.str, str_len);
		ret += ft_put(' ', data.wid.wid - pref_len - flag);
	}
	return (ret);
}

int				ft_print_format_str(t_data *data)
{
	int ret;
	int str_len;

	ret = 0;
	str_len = (int)ft_strlen(data->str);
	if (data->flag == 1)
		return (ft_numbers(*data, str_len, 0));
	if (ft_found_spec_nb(*data) == 0)
	{
		if (data->spec.c_sp == 1 || data->spec.big_c_sp == 1)
			return (ft_characters(*data));
		else if (data->spec.s_sp == 1 || data->spec.big_s_sp == 1 ||
		data->spec.percent == 1)
			return (ft_strings(*data, 0, str_len));
	}
	if (ft_found_spec_nb(*data) == 1 || data->spec.p_sp == 1)
	{
		ft_check_prefix(data, str_len);
		return (ft_numbers(*data, str_len, 0));
	}
	return (ret);
}
