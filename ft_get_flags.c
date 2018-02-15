/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:46:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/07 13:46:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void ft_flags_init(t_ls_flgs **flg)
{
	(*flg)->list = 0;
	(*flg)->recursion = 0;
	(*flg)->all = 0;
	(*flg)->reverse = 0;
	(*flg)->time_sort = 0;
	(*flg)->one = 0;
	(*flg)->flag_special = 0;
}

static int ft_fill_struct(t_ls_flgs **flgs, char *tmp)
{
	while (*tmp != '\0')
	{
		if (*tmp == 'l')
			(*flgs)->list = 1;
		else if (*tmp == 'R')
			(*flgs)->recursion = 1;
		else if (*tmp == 'a')
			(*flgs)->all = 1;
		else if (*tmp == 'r')
			(*flgs)->reverse = 1;
		else if (*tmp == 't')
			(*flgs)->time_sort = 1;
		else if (*tmp == '1')
			(*flgs)->one = 1;
		if (*tmp == 'l' || *tmp == 'R' || *tmp == 'a' || *tmp == 'r' || *tmp == 't' ||
			*tmp == '1')
		   tmp++;
		else
		{
			ft_printf("./ft_ls: illegal option -- %c\nusage"
            ": ./ft_ls [-Ralrt1] [file ...]\n", *tmp);
			return (FAIL);
		}
	}
	return (OK);
}

int ft_get_flags(int argc, char **argv, t_ls_flgs *flgs)
{
	ft_flags_init(&flgs);
	while (argc-- != 1)
	{
		argv++;
		if (**argv == '-')
		{
			(*argv)++;
			if (**argv == '-')
			{
				(*argv)--;
				flgs->flag_special = 1;
				break;
			}
			if (ft_fill_struct(&flgs, *argv) == FAIL)
				return (FAIL);
			(*argv)--;
		}
	}
	return (OK);
}