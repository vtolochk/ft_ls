/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:58:05 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/07 10:55:35 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void (*ft_get_print_function(t_ls_flgs flags))(char *f_arr)
{
	if (flags.list == 1)
		return (ft_long_print);
	else if (flags.one == 1)
		return (ft_one_print);
	return (ft_simple_print);
}

int ft_ls(char **argv, char **arg_files, t_ls_flgs flags, void (*func)(char *))
{
	unsigned int i;

	i = 0;
	ft_error_first(argv, arg_files);
	ft_files_second(arg_files, func); // you need to play with printing if u have -R or dont
	if (flags.recursion == 1)
	{
		while (arg_files[i])
			if (ft_dirwalk(arg_files[i++], argv) == FAIL)
				return (FAIL);
	}
	else
		ft_dirs_third(arg_files, func);
	ft_free_tab((void**)arg_files);
	return (OK);
}

int main(int argc, char **argv)
{
	t_ls_flgs flags;
	char **arg_files;
	void (*func_ptr)(char *);

	if (ft_get_flags(argc, argv, &flags))
		return (FAIL);
	func_ptr = ft_get_print_function(flags);
	arg_files = ft_get_arg_files(argc, argv, flags.flag_special);
	ft_ascii_sort(arg_files);
	if (ft_ls(argv, arg_files, flags, func_ptr) == FAIL)
		return (FAIL);
	return (OK);
}
