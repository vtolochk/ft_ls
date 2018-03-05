/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:46:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 15:46:55 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_flags_init(t_ls **flg)
{
	(*flg)->list = 0;
	(*flg)->recursion = 0;
	(*flg)->all = 0;
	(*flg)->reverse = 0;
	(*flg)->time_sort = 0;
	(*flg)->one = 0;
	(*flg)->double_minus = 0;
	(*flg)->arg_nb = 0;
	(*flg)->first_dir = 1;
	(*flg)->next_dir = 0;
	(*flg)->path_to_dir = ft_strdup("./");
	(*flg)->one_minus = 0;
	(*flg)->printed = 0;
	(*flg)->third_minus = 0;
	(*flg)->ext_attr = 0;
	(*flg)->b_a = 0;
}

static void		ft_get_flag(t_ls **flgs, char tmp)
{
	if (tmp == 't')
		(*flgs)->time_sort = 1;
	else if (tmp == '1')
	{
		(*flgs)->one = 1;
		(*flgs)->list = 0;
	}
	else if (tmp == '@')
		(*flgs)->ext_attr = 1;
	else if (tmp == 'f')
	{
		(*flgs)->f = 1;
		(*flgs)->all = 1;
	}
	else if (tmp == 'A')
	{
		if (!(*flgs)->all)
		{
			(*flgs)->all = 1;
			(*flgs)->b_a = 1;
		}
	}
}

static int		ft_fill_struct(t_ls **flgs, char *tmp)
{
	while (*tmp != '\0')
	{
		if (*tmp == 'l')
			(*flgs)->list = 1;
		else if (*tmp == 'R')
			(*flgs)->recursion = 1;
		else if (*tmp == 'a')
		{
			(*flgs)->all = 1;
			(*flgs)->b_a = 0;
		}
		else if (*tmp == 'r')
			(*flgs)->reverse = 1;
		else
			ft_get_flag(flgs, *tmp);
		if (*tmp == 'l' || *tmp == 'R' || *tmp == 'a' || *tmp == 'r' ||
			*tmp == 't' || *tmp == '1' || *tmp == 'G' || *tmp == '@' ||
			*tmp == 'f' || *tmp == 'A')
			tmp++;
		else
			return (ft_print_illegal(*tmp));
	}
	return (OK);
}

static int		ft_norma_helper(char **argv, t_ls *flgs)
{
	(*argv)++;
	if (**argv == '-')
	{
		(*argv) -= 2;
		flgs->third_minus = 1;
		return (OK);
	}
	if (**argv)
	{
		(*argv)--;
		return (ft_print_illegal(**argv));
	}
	(*argv) -= 2;
	flgs->double_minus = 1;
	return (OK);
}

int				ft_get_flags(int argc, char **argv, t_ls *flgs)
{
	ft_flags_init(&flgs);
	while (argc-- != 1)
	{
		argv++;
		if (**argv == '-')
		{
			(*argv)++;
			if (**argv == '-')
				return (ft_norma_helper(argv, flgs));
			if (!(**argv))
				flgs->one_minus = 1;
			if (ft_fill_struct(&flgs, *argv) == FAIL)
				return (FAIL);
			(*argv)--;
		}
	}
	return (OK);
}
