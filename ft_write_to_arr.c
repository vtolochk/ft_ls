/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:52:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/18 13:52:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long int ft_files_nb(char *file_name, t_ls *f)
{
	DIR *dir_stream;
	unsigned int files_nb;
	struct dirent *dir;

	files_nb = 0;
	if (!(dir_stream = opendir(file_name)))
		return (-1);
	while ((dir = readdir(dir_stream)))
	{
		if (f->all == 0 && dir->d_name[0] == '.')
			continue ;
		files_nb++;
	}
	if ((closedir(dir_stream) == -1))
		return (-1);
	return (files_nb);
}

char **ft_write_to_arr(char *file_name, t_ls **f)
{
	DIR *dir_stream;
	struct dirent *dir;
	char **files_arr;
	unsigned int i;
	long int files_nb;

	i = 0;
	if (((files_nb = ft_files_nb(file_name, *f)) == -1))
	{
		if ((*f)->arg_nb > 1)
			ft_printf("%s\n", file_name);
		ft_print_errno(file_name);
		(*f)->next_dir = 1;
		(*f)->first_dir = 0;
		return (NULL);
	}
	if (!(files_arr = (char **)malloc(sizeof(char *) * (files_nb + 1))))
		return (NULL);
	if (!(dir_stream = opendir(file_name)))
		return (ft_free_tab((void **)files_arr));
	while ((dir = readdir(dir_stream)) != NULL)
	{
		if ((*f)->all == 0 && dir->d_name[0] == '.')
			continue ;
		files_arr[i++] = ft_strdup(dir->d_name);
	}
	files_arr[i] = 0;
	if (closedir(dir_stream) == -1)
		return (ft_free_tab((void **)files_arr));
	return (files_arr);
}