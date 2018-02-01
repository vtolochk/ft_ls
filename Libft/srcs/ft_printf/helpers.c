/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:28:43 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/31 15:22:54 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		no_spec(const char **format, int i)
{
	*format = *format - i;
	return (0);
}

int		ft_put(char sign, ssize_t len)
{
	int		ret;
	char	*str;

	ret = 0;
	if (len <= 0)
		return (0);
	str = (char *)malloc(sizeof(char) * len);
	ft_memset(str, sign, len);
	ret = write(1, str, len);
	free(str);
	return (ret);
}

int		ft_check_all(va_list *ap, t_data *data, const char **form)
{
	int ret;

	ret = 0;
	ft_check_for_flags(&data->fl, form);
	ft_check_for_width(data, form, ap);
	ft_check_for_prec(&data->prec, form, ap);
	ft_check_for_len(&data->len, form);
	if (ft_check_for_color(*data, form) == 0)
		return (0);
	if ((ret = ft_bin_specif(form, ap)) > 0)
		return (ret);
	ft_check_for_spec_symb(&data->spec, form);
	return (-1);
}

int		ft_if_zero(t_data *data, const char **format)
{
	data->flag = 1;
	if ((data->str = ft_memalloc(2)) == NULL)
		return (-1);
	data->need_free = 1;
	data->str[0] = **format;
	(*format)++;
	return (1);
}

int		ft_else_if_helper(t_data *data, va_list *ap)
{
	if (((data->spec.d_sp == 1 || data->spec.i_sp == 1 ||
			data->spec.big_d_sp == 1) && data->len.z_len == 0) ||
			(data->len.z_len == 1 && (data->spec.d_sp == 1 ||
			data->spec.i_sp == 1)))
	{
		if (ft_snumbers(data, ap) == -1)
			return (-1);
		return (1);
	}
	else if (data->spec.o_sp == 1 || data->spec.big_o_sp == 1 ||
			data->spec.u_sp == 1 || data->spec.big_u_sp == 1 ||
			data->spec.x_sp == 1 || data->spec.big_x_sp == 1 ||
			data->len.z_len == 1)
	{
		if (ft_unumbers(data, ap, 0) == -1)
			return (-1);
		return (1);
	}
	return (0);
}
