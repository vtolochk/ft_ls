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

int ft_ls_print(char *file_name, char **argv, char file_type)
{
	DIR *dir_stream;
	struct dirent *dir;

	if (file_type == '-')
		ft_printf("%s\n", file_name);
	if (file_type == 'd' && !(dir_stream = opendir(file_name)))
		return (ft_print_errno(argv, file_name));
	while (file_type == 'd' && (dir = readdir(dir_stream)) != NULL)
		ft_printf("%s\n", dir->d_name);
	if (file_type == 'd' && closedir(dir_stream) == -1)
		return (ft_print_errno(argv, file_name));
	return (OK);
}