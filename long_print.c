/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:05:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/18 15:05:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void write_blocks(char **files, t_ls *data, unsigned int *link_width)
{
	char *temp;
	unsigned int i;
	struct stat status;
	unsigned int blocks;
	unsigned int temp_width;

	i = 0;
	blocks = 0;
	while (files[i])
	{
		temp = ft_strjoin(data->path_to_dir, files[i++]);
		lstat(temp, &status);
		temp_width = (unsigned int)ft_strlen(ft_itoa(status.st_nlink));
		if (*link_width <= temp_width)
			*link_width = temp_width;
		blocks += status.st_blocks;
		free(temp);
	}
	ft_printf("total %d\n", blocks);
}

static void write_file_type(char *file)
{
	char c;
	struct stat status;

	c = 0;
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

static void print_file_mode(char *file, mode_t st_mode, unsigned int k, unsigned int i)
{
	char *temp;

	temp = ft_itoa_base(st_mode, 8);
	i = (unsigned int)ft_strlen(temp) - 4;
	write_file_type(file);
	while (k++ != 3)
	{
		if (temp[++i] == '0')
			write(1, NO_ACCESS, 3);
		else if (temp[i] == '1')
			write(1, X_ACCESS, 3);
		else if (temp[i] == '2')
			write(1, W_ACCESS, 3);
		else if (temp[i] == '3')
			write(1, WX_ACCESS, 3);
		else if (temp[i] == '4')
			write(1, R_ACCESS, 3);
		else if (temp[i] == '5')
			write(1, RX_ACCESS, 3);
		else if (temp[i] == '6')
			write(1, RW_ACCESS, 3);
		else if (temp[i] == '7')
			write(1, RWX_ACCESS, 3);
	}
	free(temp);
}

void ft_long_print(char **files, t_ls *data)
{
	unsigned int i;
	unsigned int link_width;
	struct stat status;
	char *temp;

	i = 0;
	link_width = 0;
	if (files[i])
	{
		temp = data->path_to_dir;
		data->path_to_dir = ft_strjoin(data->path_to_dir, "/");
		free(temp);
		write_blocks(files, data, &link_width);
	}
	while (files[i])
	{
		temp = ft_strjoin(data->path_to_dir, files[i]);
		lstat(temp, &status);
		print_file_mode(temp, status.st_mode, 0, 0);
		ft_printf(" %*u ", link_width + 1, status.st_nlink);
		ft_printf("%s\n", files[i++]);// file name
		free(temp);
	}
	free(data->path_to_dir);
}