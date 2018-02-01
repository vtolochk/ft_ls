/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:03:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/28 16:50:34 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_exit_printf(t_data *data)
{
	if (data->need_free == 1)
		ft_strdel(&data->str);
	else
		data->str = NULL;
}
