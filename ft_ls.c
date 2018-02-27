/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:58:05 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 14:24:27 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int				ls_time_cmp(struct stat stat_1, struct stat stat_2, t_ls *f)
{
	if (stat_1.st_mtimespec.tv_sec < stat_2.st_mtimespec.tv_sec)
		return (1);
	else if (stat_1.st_mtimespec.tv_sec == stat_2.st_mtimespec.tv_sec)
	{
		if (stat_1.st_mtimespec.tv_nsec < stat_2.st_mtimespec.tv_nsec)
			return (1);
		else if (stat_1.st_mtimespec.tv_nsec == stat_2.st_mtimespec.tv_nsec &&
				(f->recursion == 1 && f->reverse == 1))
			return (1);
		else if (stat_1.st_mtimespec.tv_nsec == stat_2.st_mtimespec.tv_nsec)
			return (0);
	}
	return (0);
}

void			ft_print_owner_and_group(struct stat s, int usr, int grg, int l)
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

int				ft_ls(char **arg_f, t_ls *flags, void (*func)(char **, t_ls *))
{
	unsigned int i;

	i = 0;
	ft_error_first(arg_f);
	fls_sc(arg_f, flags, func, 0);
	while (arg_f[flags->arg_nb])
		flags->arg_nb++;
	if (flags->recursion == 1)
	{
		while (arg_f[i])
		{
			if (ft_dirwalk(arg_f[i++], func, &flags) == FAIL)
			{
				ft_free_tab((void**)arg_f);
				return (FAIL);
			}
			if (arg_f[i] && arg_f[i][0] && flags->printed == 1)
				write(1, "\n", 1);
		}
	}
	else
		ft_dirs_third(arg_f, func, &flags, 0);
	ft_free_tab((void**)arg_f);
	ft_strdel(&(flags->path_to_dir));
	return (OK);
}

int				main(int argc, char **argv)
{
	t_ls		flags;
	char		**arg_files;
	void		(*func_ptr)(char **, t_ls *);

	if (ft_get_flags(argc, argv, &flags))
		return (FAIL);
	func_ptr = ft_get_print_function(&flags);
	arg_files = ft_get_arg_files(argc, argv, &flags);
	if (!(flags.f))
		ft_ascii_sort(arg_files, flags.reverse);
	if (flags.time_sort == 1 && !(flags.f))
		ft_time_sort(arg_files, &flags, NULL);
	if (ft_ls(arg_files, &flags, func_ptr) == FAIL)
		return (FAIL);
	return (OK);
}
