/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_additional_arg.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 13:39:30 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/28 15:59:45 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_check_for_prec(t_prec *p, const char **f, va_list *ap)
{
	if (**f == '.')
	{
		p->prec = 1;
		p->dot = 1;
		(*f)++;
	}
	if (**f == '*')
		p->star = 1;
	while (**f && **f == '*')
		(*f)++;
	if (p->star == 1)
		p->prec = va_arg(*ap, int);
	else if (p->prec == 1)
	{
		p->prec = ft_atoi(*f);
		while (ft_isdigit(**f))
			(*f)++;
	}
}

void			ft_check_for_width(t_data *d, const char **f, va_list *ap)
{
	while (ft_isdigit(**f) || **f == '*')
	{
		if (ft_isdigit(**f))
			d->wid.wid = ft_atoi(*f);
		while (ft_isdigit(**f))
			(*f)++;
		if (**f == '*')
			d->wid.wid = va_arg(*ap, int);
		if (d->wid.wid < 0)
		{
			d->fl.minus = 1;
			d->wid.wid = -d->wid.wid;
		}
		if (**f == '*')
			(*f)++;
	}
}

void			ft_check_for_flags(t_flags *flags, const char **format)
{
	while (**format && (**format == '-' || **format == '+' ||
		**format == ' ' || **format == '#' || **format == '0'))
	{
		if (**format == '-')
			flags->minus = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '#')
			flags->hash = 1;
		else if (**format == '0')
			flags->zero = 1;
		(*format)++;
	}
}

static void		ft_any_order(t_length *len)
{
	if (len->z_len == 1)
	{
		ft_len_init(len);
		len->z_len = 1;
	}
	else if (len->j_len == 1)
	{
		ft_len_init(len);
		len->j_len = 1;
	}
	else if (len->ll_len == 1)
	{
		ft_len_init(len);
		len->ll_len = 1;
	}
	else if (len->l_len == 1)
	{
		ft_len_init(len);
		len->l_len = 1;
	}
	else if (len->h_len == 1)
	{
		ft_len_init(len);
		len->h_len = 1;
	}
}

void			ft_check_for_len(t_length *len, const char **format)
{
	while (**format && (**format == 'h' || **format == 'l' ||
		**format == 'j' || **format == 'z'))
	{
		if (**format == 'z')
			len->z_len = 1;
		else if (**format == 'j')
			len->j_len = 1;
		else if (**format == 'l' && *(*format + 1) == 'l')
			len->ll_len = 1;
		else if (**format == 'l')
			len->l_len = 1;
		else if (**format == 'h' && *(*format + 1) == 'h')
			len->hh_len = 1;
		else if (**format == 'h')
			len->h_len = 1;
		(*format)++;
		if (len->hh_len == 1 || len->ll_len == 1)
		{
			len->h_len = 0;
			len->l_len = 0;
			(*format)++;
		}
	}
	ft_any_order(len);
}
