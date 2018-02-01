/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:51:26 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/31 15:40:08 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_write_color(char *color, char *plus, char *minus, char *hash)
{
	char esc;

	esc = 27;
	write(1, &esc, 1);
	write(1, "[", 1);
	write(1, plus, 1);
	write(1, ";", 1);
	write(1, minus, 1);
	write(1, ";", 1);
	write(1, hash, 1);
	write(1, ";", 1);
	write(1, color, 2);
	write(1, "m", 1);
}

static int		ft_check_flags(t_data data, char *color)
{
	char	*plus;
	char	*minus;
	char	*hash;

	plus = 0;
	minus = 0;
	hash = 0;
	if (color != 0)
		if (ft_strcmp(color, "no_color") == 0)
			return (-1);
	if (data.fl.plus == 1 && color != 0)
		plus = "1";
	if (data.fl.minus == 1 && color != 0)
		minus = "4";
	if (data.fl.hash == 1 && color != 0)
		hash = "7";
	ft_write_color(color, plus, minus, hash);
	return (0);
}

static void		ft_if_else(const char **format, char **color)
{
	if (ft_strncmp("yellow%", *format, 7) == 0)
	{
		*color = "33";
		*format = *format + 7;
	}
	else if (ft_strncmp("blue%", *format, 5) == 0)
	{
		*color = "34";
		*format = *format + 5;
	}
	else if (ft_strncmp("magenta%", *format, 8) == 0)
	{
		*color = "35";
		*format = *format + 8;
	}
	else if (ft_strncmp("cyan%", *format, 5) == 0)
	{
		*color = "36";
		*format = *format + 5;
	}
	else if (ft_strncmp("grey%", *format, 5) == 0)
	{
		*color = "37";
		*format = *format + 5;
	}
}

int				ft_check_for_color(t_data data, const char **format)
{
	char *color;

	color = "no_color";
	if (ft_strncmp("eoc%", *format, 4) == 0)
	{
		color = 0;
		*format = *format + 4;
	}
	else if (ft_strncmp("white%", *format, 6) == 0)
	{
		color = "30";
		*format = *format + 6;
	}
	else if (ft_strncmp("red%", *format, 4) == 0)
	{
		color = "31";
		*format = *format + 4;
	}
	else if (ft_strncmp("green%", *format, 6) == 0)
	{
		color = "32";
		*format = *format + 6;
	}
	ft_if_else(format, &color);
	return (ft_check_flags(data, color));
}
