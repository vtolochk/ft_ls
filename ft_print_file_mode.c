/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:06:09 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 14:10:39 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		write_file_type(char *file)
{
	char			c;
	struct stat		status;

	c = '-';
	lstat(file, &status);
	if (S_ISBLK(status.st_mode))
		c = 'b';
	else if (S_ISCHR(status.st_mode))
		c = 'c';
	else if (S_ISDIR(status.st_mode))
		c = 'd';
	else if (S_ISFIFO(status.st_mode))
		c = 'f';
	else if (S_ISREG(status.st_mode))
		c = '-';
	else if (S_ISLNK(status.st_mode))
		c = 'l';
	else if (S_ISSOCK(status.st_mode))
		c = 's';
	write(1, &c, 1);
}

static void		ft_fill_user_field(char **str, mode_t st_mode)
{
	if (st_mode & S_IRWXU && st_mode & S_ISUID)
	{
		(*str)[0] = 'r';
		if (st_mode & S_IWUSR)
			(*str)[1] = 'w';
		if (st_mode & S_ISUID && st_mode & S_IXUSR)
			(*str)[2] = 's';
		else if (st_mode & S_ISUID && !(st_mode & S_IXUSR))
			(*str)[2] = 'S';
		else
			(*str)[2] = 'x';
	}
	else
	{
		if (st_mode & S_IRUSR)
			(*str)[0] = 'r';
		if (st_mode & S_IWUSR)
			(*str)[1] = 'w';
		if (st_mode & S_IXUSR)
			(*str)[2] = 'x';
		else if (st_mode & S_ISUID && st_mode & S_IXUSR)
			(*str)[2] = 's';
		else if (st_mode & S_ISUID && !(st_mode & S_IXUSR))
			(*str)[2] = 'S';
	}
}

static void		ft_fill_grp_field(char **str, mode_t st_mode)
{
	if (st_mode & S_IRWXG && st_mode & S_ISGID)
	{
		(*str)[3] = 'r';
		if (st_mode & S_IWGRP)
			(*str)[4] = 'w';
		if (st_mode & S_ISGID && st_mode & S_IXGRP)
			(*str)[5] = 's';
		else if (st_mode & S_ISGID && !(st_mode & S_IXGRP))
			(*str)[5] = 'S';
		else
			(*str)[5] = 'x';
	}
	else
	{
		if (st_mode & S_IRGRP)
			(*str)[3] = 'r';
		if (st_mode & S_IWGRP)
			(*str)[4] = 'w';
		if (st_mode & S_IXGRP)
			(*str)[5] = 'x';
		else if (st_mode & S_ISGID && st_mode & S_IXGRP)
			(*str)[5] = 's';
		else if (st_mode & S_ISGID && !(st_mode & S_IXGRP))
			(*str)[5] = 'S';
	}
}

static void		ft_fill_oth_field(char **str, mode_t st_mode)
{
	if (st_mode & S_IRWXO && st_mode & S_ISVTX)
	{
		(*str)[6] = 'r';
		if (st_mode & S_IWOTH)
			(*str)[7] = 'w';
		if (st_mode & S_ISVTX && st_mode & S_IXOTH)
			(*str)[8] = 't';
		else if (st_mode & S_ISVTX && !(st_mode & S_IXOTH))
			(*str)[8] = 'T';
		else
			(*str)[8] = 'x';
	}
	else
	{
		if (st_mode & S_IROTH)
			(*str)[6] = 'r';
		if (st_mode & S_IWOTH)
			(*str)[7] = 'w';
		if (st_mode & S_IXOTH)
			(*str)[8] = 'x';
		else if (st_mode & S_ISVTX && st_mode & S_IXOTH)
			(*str)[8] = 't';
		else if (st_mode & S_ISVTX && !(st_mode & S_IXOTH))
			(*str)[8] = 'T';
	}
}

void			print_file_mode(char *file, mode_t st_mode)
{
	char		*str;
	char		buf[128];

	str = ft_strnew(9);
	ft_memset(str, '-', 9);
	write_file_type(file);
	ft_fill_user_field(&str, st_mode);
	ft_fill_grp_field(&str, st_mode);
	ft_fill_oth_field(&str, st_mode);
	if ((listxattr(file, buf, sizeof(buf), XATTR_NOFOLLOW)) > 0)
	{
		str[9] = '@';
		write(1, str, 10);
	}
	else
	{
		write(1, str, 9);
		write(1, " ", 1);
	}
	free(str);
}
