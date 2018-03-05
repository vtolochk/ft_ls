/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perm_and_ext_attr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:20:11 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 15:46:06 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_print_illegal(char c)
{
	write(2, "ls: illegal option -- ", 22);
	write(2, &c, 1);
	write(2, "\nusage: ls [-AR@alfrt1] [file ...]\n", 35);
	return (FAIL);
}

int				ft_check_for_perm(char *file)
{
	struct stat st;

	lstat(file, &st);
	if (!(st.st_mode & S_IXUSR) && !(st.st_mode & S_IXGRP) &&
		!(st.st_mode & S_IXOTH) && (!(st.st_mode & S_IWUSR) &&
		!(st.st_mode & S_IWGRP) && !(st.st_mode & S_IWOTH)) &&
		(!(st.st_mode & S_IRUSR) && !(st.st_mode & S_IRGRP) &&
		!(st.st_mode & S_IROTH)))
		return (1);
	return (0);
}

void			ft_print_no_perm(int len, char **arg_files, int i)
{
	if (len > 1)
	{
		write(2, arg_files[i], ft_strlen(arg_files[i]));
		write(2, ":\n", 2);
	}
	write(2, "ls: ", 4);
	write(2, arg_files[i], ft_strlen(arg_files[i]));
	write(2, ": Permission denied", 19);
	if (arg_files[i + 1])
		write(2, "\n\n", 2);
	else
		write(2, "\n", 1);
}

static void		write_buf(char *buf, ssize_t *i, ssize_t *k)
{
	write(1, "\t", 1);
	while (buf[(*i)])
	{
		write(1, &buf[(*i)++], 1);
		(*k)--;
	}
}

void			ft_print_ext_attr(char *f, t_ls *data)
{
	ssize_t		i;
	ssize_t		k;
	u_int32_t	x;
	char		buf[100];
	char		buf1[100];

	i = 0;
	x = 0;
	if (data->ext_attr)
	{
		if ((k = listxattr(f, buf1, sizeof(buf1), XATTR_NOFOLLOW)) > 0)
		{
			while (k-- > 0)
			{
				write_buf(buf1, &i, &k);
				if (!buf1[i++])
				{
					ft_printf("\t  %d \n", \
					getxattr(f, &buf1[x], buf, 100, 0, XATTR_NOFOLLOW));
					x += i;
				}
			}
		}
	}
}
