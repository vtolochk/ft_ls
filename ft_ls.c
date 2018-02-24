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

static void (*ft_get_print_function(t_ls *flags))(char **f_arr, t_ls *flg)
{
	if (flags->list == 1)
		return (ft_long_print);
	return (ft_one_print);
}

int ft_ls(char **argv, char **arg_files, t_ls *flags, void (*func)(char **, t_ls *))
{
	unsigned int i;

	i = 0;
	ft_error_first(argv, arg_files, flags);
	ft_files_second(arg_files, flags, func);
	while (arg_files[flags->arg_nb])
		flags->arg_nb++;
	if (flags->recursion == 1)
	{
		while (arg_files[i])
		{
			if (ft_dirwalk(arg_files[i++], func, &flags) == FAIL)
				return (FAIL);
			if (arg_files[i] && arg_files[i][0] && flags->printed == 1)
				write(1, "\n", 1);
		}
	}
	else
		ft_dirs_third(arg_files, func, &flags);
	ft_free_tab((void**)arg_files);
	return (OK);
}

int main(int argc, char **argv)
{
	t_ls flags;
	char **arg_files;
	void (*func_ptr)(char **, t_ls *);

	flags.argv_temp = argv;
	if (ft_get_flags(argc, argv, &flags))
		return (FAIL);
	func_ptr = ft_get_print_function(&flags);
	arg_files = ft_get_arg_files(argc, argv, &flags);
	ft_ascii_sort(arg_files, flags.reverse);
	if (flags.time_sort == 1)
		ft_time_sort(arg_files, &flags, NULL);
	if (ft_ls(argv, arg_files, &flags, func_ptr) == FAIL)
		return (FAIL);
	return (OK);
}
