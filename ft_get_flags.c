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

static void ft_flags_init(t_ls **flg)
{
	(*flg)->list = 0;
	(*flg)->recursion = 0;
	(*flg)->all = 0;
	(*flg)->reverse = 0;
	(*flg)->time_sort = 0;
	(*flg)->one = 0;
	(*flg)->double_minus = 0;
	(*flg)->arg_nb = 0;
	(*flg)->big_g = 0;
	(*flg)->first_dir = 1;
	(*flg)->files_second = 0;
	(*flg)->next_dir = 0;
	(*flg)->path_to_dir = ft_strdup("./");
	(*flg)->one_minus = 0;
	(*flg)->go_via_link = 0;
}

static int ft_fill_struct(t_ls **flgs, char *tmp)
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
		else if (*tmp == 'G')
			(*flgs)->big_g = 1;
		if (*tmp == 'l' || *tmp == 'R' || *tmp == 'a' || *tmp == 'r' || *tmp == 't' ||
			*tmp == '1' || *tmp == 'G')
		   tmp++;
		else
		{
			ft_printf("./ft_ls: illegal option -- %c\nusage"
            ": ./ft_ls [-GRalrt1] [file ...]\n", *tmp);
			return (FAIL);
		}
	}
	return (OK);
}

int ft_get_flags(int argc, char **argv, t_ls *flgs)
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
				flgs->double_minus = 1;
				break ;
			}
			if (!(**argv))
				flgs->one_minus = 1;
			if (ft_fill_struct(&flgs, *argv) == FAIL)
				return (FAIL);
			(*argv)--;
		}
	}
	return (OK);
}