/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 10:38:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/28 14:13:18 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_rounding(t_data *data, double tmp_x)
{
	int i;

	i = 0;
	while (data->str[i++] != '.')
		continue;
	if (data->str[i] >= '5')
	{
		ft_exit_printf(data);
		if ((data->str = ft_itoa_base((size_t)tmp_x + 1, 10)) == NULL)
			return (-1);
	}
	else
	{
		ft_exit_printf(data);
		if ((data->str = ft_strndup(data->str, i - 1)) == NULL)
			return (-1);
	}
	data->prec.prec = 0;
	return (0);
}

static void		ft_check_neg_and_zero_prec(t_data *data, double *x, char *flag)
{
	if (*x < 0)
	{
		data->negative_nb = 1;
		*x = *x * (-1);
	}
	if (data->prec.prec == 0)
	{
		*flag = 1;
		data->prec.prec = 6;
	}
}

static double	ft_get_value(t_data *data, double *x, char *flag, va_list *ap)
{
	*flag = 0;
	*x = va_arg(*ap, double);
	ft_check_neg_and_zero_prec(data, x, flag);
	return (*x);
}

static int		ft_make_str(t_data *data, size_t tmp, char **tmp_ptr, int i)
{
	tmp_ptr[0] = data->str;
	if ((tmp_ptr[1] = ft_itoa_base(tmp, 10)) == NULL)
		return (-1);
	if ((data->str = ft_strjoin(data->str, tmp_ptr[1])) == NULL)
		return (-1);
	ft_strdel(&tmp_ptr[1]);
	free(tmp_ptr[0]);
	if (i == 0)
	{
		tmp_ptr[0] = data->str;
		data->str = ft_strjoin(data->str, ".");
		free(tmp_ptr[0]);
	}
	return (0);
}

int				ft_fl_point_nb(t_data *d, va_list *ap, int i, size_t tmp)
{
	char		flag;
	char		*tmp_ptr[2];
	double		x;
	double		tmp_x;

	tmp_x = ft_get_value(d, &x, &flag, ap);
	if ((d->str = ft_memalloc(1)) == NULL)
		return (-1);
	d->need_free = 1;
	x += 1.0 / ft_power(10, d->prec.prec + 1);
	while (i <= d->prec.prec)
	{
		tmp = (size_t)x;
		if (ft_make_str(d, tmp, tmp_ptr, i) == -1)
			return (-1);
		x = (x - tmp) * 10;
		i++;
	}
	if (d->prec.dot == 1 && flag == 1)
		if (ft_rounding(d, tmp_x) == -1)
			return (-1);
	return (0);
}
