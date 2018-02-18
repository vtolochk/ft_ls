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

unsigned int ft_get_blocks(char **files, t_ls *data, unsigned int *link_width)
{
	char *temp;
	unsigned int i;
	struct stat status;
	unsigned int blocks;
	unsigned int temp_width;

	i = 0;
	blocks = 0;
	temp_width = 0;
	while (files[i])
	{
		temp = ft_strjoin(data->path_to_dir, files[i++]);
		lstat(temp, &status);
		temp_width = ft_strlen(ft_itoa(status.st_nlink));
		if (*link_width <= temp_width)
			*link_width = temp_width;
		blocks += status.st_blocks;
		free(temp);
	}
	return (blocks);
}

void print_file_mode(char *file, mode_t st_mode)
{
	unsigned int i;
	char *file_mode;
	char *temp;

	i = 0;
	file_mode = ft_strnew(10);
	temp = ft_itoa_base(st_mode, 8);
	i = ft_strlen(temp);
	if (temp[--i] == 0)
		file_mode = ft_strjoin(NO_ACCESS, "");

	ft_printf("%s", file_mode);
	ft_printf(" %o ::", st_mode);
	free(file_mode);
}

void ft_long_print(char **files, t_ls *data)
{
	unsigned int i;
	unsigned int blocks;
	unsigned int link_width;
	struct stat status;
	char *temp;

	i = 0;
	blocks = 0;
	link_width = 0;
	if (files[i])
	{
		temp = data->path_to_dir;
		data->path_to_dir = ft_strjoin(data->path_to_dir, "/");
		free(temp);
		blocks = ft_get_blocks(files, data, &link_width);
		ft_printf("total %d\n", blocks);
	}
	while (files[i])
	{
		temp = ft_strjoin(data->path_to_dir, files[i]);
		lstat(temp, &status);
		print_file_mode(temp, status.st_mode);
		ft_printf(" %*u ", link_width + 1, status.st_nlink);
		ft_printf("%s\n", files[i]);
		i++;
		free(temp);
	}
	free(data->path_to_dir);
}