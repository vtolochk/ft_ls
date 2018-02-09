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
		if (*tmp == 'l' || *tmp == 'R' || *tmp == 'a' || *tmp == 'r' || *tmp == 't')
		   tmp++;
		else
		{
			ft_printf("ft_ls: illegal option -- %c\nusage"
            ": ft_ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", *tmp);
			return (1);
		}
	}
	return (0);
}

int ft_get_flags(int argc, char **argv, t_ls_flgs *flgs)
{
	char *tmp;

	ft_flags_init(&flgs);
	if (argc == 1)
		return (0);
	while (argc != 1)
	{
		argv++;
		if ((tmp = ft_strchr(*argv, '-')) != NULL)
		{
			tmp++;
			if (*tmp == '-')
				break ;
			if (ft_fill_struct(&flgs, tmp) == 1)
				return (1);
		}
		argc--;
	}
	return (0);
}
