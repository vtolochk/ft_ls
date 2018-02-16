/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:55:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/10 16:55:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_one_print(char *file, t_ls data)
{
	ft_printf("%s\n", file);
	data.big_g = 0;
}

void ft_long_print(char *file, t_ls data)
{
	file++;
	data.big_g = 0;
	ft_printf("long print func\n");
	ft_printf("later:D\n");
}