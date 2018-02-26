/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:05:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 13:58:55 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		write_blocks(char **files, t_ls *data, int *link_width)
{
	char		*temp;
	struct stat status;
	int			i;
	int			blocks;
	int			temp_width;

	i = 0;
	blocks = 0;
	while (files[i])
	{
		temp = ft_strjoin(data->path_to_dir, files[i++]);
		lstat(temp, &status);
		ft_strdel(&temp);
		temp = ft_itoa(status.st_nlink);
		temp_width = (unsigned int)ft_strlen(temp);
		if (*link_width <= temp_width)
			*link_width = temp_width;
		blocks += status.st_blocks;
		ft_strdel(&temp);
	}
	if (data->arg_nb > 0)
	{
		write(1, "total ", 6);
		ft_printf("%d\n", blocks);
	}
}

static void		ft_join_dirs(t_ls *f, char **files, struct stat *status)
{
	char *temp;

	temp = f->path_to_dir;
	f->path_to_dir = ft_strjoin(f->path_to_dir, "/");
	ft_strdel(&temp);
	temp = ft_strjoin(f->path_to_dir, files[0]);
	if (lstat(temp, status) == -1)
	{
		if (files[0][0] == '/')
		{
			free(f->path_to_dir);
			f->path_to_dir = ft_strdup("/");
		}
	}
	ft_strdel(&temp);
}

static void		ft_print_info(struct stat *s, char *file, int size_width)
{
	if (S_ISBLK(s->st_mode) || S_ISCHR(s->st_mode))
		ft_printf(" %u,   %u ", s->st_rdev >> 24 & 0xff, s->st_rdev & 0xffffff);
	ft_printf("%*lld ", size_width + 2, s->st_size);
	ft_print_time(*s);
	write(1, file, ft_strlen(file));
}

static void		ft_get_ind(t_ls *d, char **files, struct stat *st, int ind[4])
{
	ft_join_dirs(d, files, st);
	write_blocks(files, d, &(ind[0]));
	ind[1] = ft_get_size_width(files, d);
	ind[2] = ft_get_grg_indent(files, d, 0);
	ind[3] = ft_get_user_indent(files, d, 0);
}

void			ft_long_print(char **f, t_ls *d)
{
	int			i;
	struct stat st;
	char		*t;
	int			indent[4];

	i = 0;
	indent[0] = 0;
	if (f && f[i])
		ft_get_ind(d, f, &st, indent);
	while (f && f[i])
	{
		if (d->b_a && (!ft_strncmp(f[i], ".", 2) || !ft_strncmp(f[i], "..", 3)))
		{
			i++;
			continue;
		}
		t = ft_strjoin(d->path_to_dir, f[i]);
		lstat(t, &st);
		print_file_mode(t, st.st_mode);
		ft_print_owner_and_group(st, indent[3], indent[2], indent[0]);
		ft_print_info(&st, f[i++], indent[1]);
		S_ISLNK(st.st_mode) ? ft_printf(" -> %s\n", l_v(t)) : write(1, "\n", 1);
		ft_print_ext_attr(t, d);
		free(t);
	}
}
