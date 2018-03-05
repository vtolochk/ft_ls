/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:58:05 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/04 10:15:21 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ls_time_cmp(struct stat stat_1, struct stat stat_2, t_ls *f)
{
	if (stat_1.st_mtimespec.tv_sec < stat_2.st_mtimespec.tv_sec)
		return (1);
	else if (stat_1.st_mtimespec.tv_sec == stat_2.st_mtimespec.tv_sec)
	{
		if ((f->recursion == 1 && f->reverse == 1) || f->reverse)
			return (1);
	}
	return (0);
}

void			print_owner_and_group(struct stat s, int usr, int grg, int l)
{
	struct passwd		*user_id;
	struct group		*group_id;

	ft_printf("%*u ", l + 1, s.st_nlink);
	user_id = getpwuid(s.st_uid);
	group_id = getgrgid(s.st_gid);
	ft_printf("%-*s", usr, user_id->pw_name);
	ft_printf("  %-*s", grg, group_id->gr_name);
}

static void		(*ft_get_print_function(t_ls *flags))(char **f_arr, t_ls *flg)
{
	if (flags->list == 1)
		return (ft_long_print);
	return (ft_one_print);
}

int				ft_ls(char **arg, t_ls *f, void (*ft)(char **, t_ls *), int i)
{
	ft_error_first(arg, f);
	fls_sc(arg, f, ft, 0);
	while (arg[f->arg_nb])
		f->arg_nb++;
	if (f->recursion == 1)
	{
		while (arg[i])
		{
			if (ft_dirwalk(arg[i++], ft, &f) == FAIL)
			{
				ft_free_tab((void**)arg);
				ft_strdel(&(f->path_to_dir));
				return (FAIL);
			}
			if (arg[i] && arg[i][0] && f->printed == 1)
				write(1, "\n", 1);
		}
	}
	else
		drs_thrd(arg, ft, &f, 0);
	ft_free_tab((void**)arg);
	ft_strdel(&(f->path_to_dir));
	return (OK);
}

int				main(int argc, char **argv)
{
	t_ls		flags;
	char		**arg_files;
	void		(*func_ptr)(char **, t_ls *);

	if (ft_get_flags(argc, argv, &flags))
	{
		free(flags.path_to_dir);
		return (FAIL);
	}
	func_ptr = ft_get_print_function(&flags);
	arg_files = ft_get_arg_files(argc, argv, &flags);
	if (!(flags.f))
		ft_ascii_sort(arg_files, flags.reverse);
	if (flags.time_sort == 1 && !(flags.f))
		ft_time_sort(arg_files, &flags, NULL);
	if (ft_ls(arg_files, &flags, func_ptr, 0) == FAIL)
		return (FAIL);
	return (OK);
}
