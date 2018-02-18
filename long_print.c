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
		temp_width = (unsigned int)ft_strlen(ft_itoa(status.st_nlink));
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
	unsigned int k;
	char c;
	char *temp;

	k = 0;
	temp = ft_itoa_base(st_mode, 8);
	i = (unsigned int)ft_strlen(temp) - 4;
	//c = ft_get_file_type(file); // it doesnt work:( need to create another function :(
	file++;
	c = 'd';
	write(1, &c, 1);
	//
	while (k != 3)
	{
		i++;
		if (temp[i] == '0')
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
		k++;
	}
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