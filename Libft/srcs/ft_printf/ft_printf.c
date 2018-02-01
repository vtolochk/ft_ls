/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:06:36 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/29 12:57:43 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_format_str(t_data *data, va_list *ap)
{
	if (data->spec.percent == 1)
		data->str = "%";
	else if (data->spec.p_sp == 1)
	{
		if (ft_pointer(data, ap) == -1)
			return (-1);
	}
	else if (data->spec.c_sp == 1 && data->len.l_len == 0)
		data->symb = (char)va_arg(*ap, int);
	else if (data->spec.big_c_sp == 1 ||
		(data->spec.c_sp == 1 && data->len.l_len == 1))
		data->u_symb = va_arg(*ap, unsigned int);
	else if (data->spec.s_sp == 1 || data->spec.big_s_sp == 1 ||
			(data->spec.s_sp == 1 && data->len.l_len == 1))
	{
		if (ft_str_spec(data, ap) == -1)
			return (-1);
	}
	if (ft_else_if_helper(data, ap) == -1)
		return (-1);
	else if (data->spec.fl_point_nb == 1)
		if (ft_fl_point_nb(data, ap, 0, 0) == -1)
			return (-1);
	return (ft_print_format_str(data));
}

static void		ft_search_spec(t_data *data, const char **format, int *ret)
{
	*ret = 0;
	if (ft_found_spec(*data) == 0)
		ft_check_for_spec_nb(&data->spec, format);
	if (ft_found_spec(*data) == 0)
		ft_check_for_spec_oth(&data->spec, format);
}

int				ft_get_data(va_list *ap, const char **fmt, int i, int ret)
{
	t_data d;

	ft_init_all(&d);
	while (**fmt)
	{
		if ((ret = ft_check_all(ap, &d, fmt)) >= 0)
			return (ret);
		else
			ft_search_spec(&d, fmt, &ret);
		if (ft_found_spec(d) == 1)
			break ;
		if (ft_isvalid(*fmt) == 1)
		{
			if (ft_if_zero(&d, fmt) == -1)
				return (-1);
			ft_len_init(&d.len);
			ret = ft_format_str(&d, ap);
			ft_exit_printf(&d);
			return (ret);
		}
		*fmt += i++;
	}
	ret = ft_found_spec(d) == 0 ? no_spec(fmt, i) : ft_format_str(&d, ap);
	ft_exit_printf(&d);
	return (ret);
}

int				ft_print_string(va_list *ap, const char *format)
{
	int			ret;
	int			bytes;

	bytes = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (0);
			if ((ret = ft_get_data(*(&ap), &format, 0, 0)) == -1)
				return (-1);
			bytes += ret;
			continue ;
		}
		else
			bytes += write(1, &(*format), 1);
		format++;
	}
	return (bytes);
}

int				ft_printf(const char *format, ...)
{
	int		bytes;
	va_list arg_list;

	if (format == NULL)
		return (0);
	va_start(arg_list, format);
	bytes = ft_print_string(&arg_list, format);
	va_end(arg_list);
	return (bytes);
}
