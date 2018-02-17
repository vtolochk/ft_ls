/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:55:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/10 16:55:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_one_print(char **file, t_ls *data)
{
	unsigned int i;

	i = 0;
	while (file[i])
	{
		ft_printf("%s\n", file[i]);
		i++;
	}
	data->big_g = 0;
}

void ft_long_print(char **files, t_ls *data)
{
	struct stat status;
	unsigned int i;

	i = 0;
	lstat(files[i], &status);
	data->big_g = 0;

	while (files[i])
	{
		ft_printf("total: %d\n", status.st_blocks);
		ft_printf("%s\n", files[i]);
		i++;
	}
}