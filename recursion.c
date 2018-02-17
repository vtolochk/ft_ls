/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:01:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/11 15:01:00 by vtolochk         ###   ########.fr       */
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

char **ft_write_to_arr(char *file_name, t_ls *f)
{
	DIR *dir_stream;
	struct dirent *dir;
	char **files_arr;
	unsigned int i;
	long int files_nb;

	i = 0;
	if (((files_nb = ft_files_nb(file_name, f)) == -1))
	{
		ft_printf("%cyan%%s:%eoc%\n", file_name);
		ft_print_errno(f->argv_temp, file_name); // some bug is here it isnt right errno value
		return (NULL);
	}
	if (!(files_arr = (char **)malloc(sizeof(char *) * (files_nb + 1))))
		return (NULL);
	if (!(dir_stream = opendir(file_name)))
		return (ft_free_tab((void **)files_arr));
	while ((dir = readdir(dir_stream)) != NULL)
	{
		if (f->all == 0 && dir->d_name[0] == '.')
			continue ;
		files_arr[i++] = ft_strdup(dir->d_name);
	}
	files_arr[i] = 0;
	if (closedir(dir_stream) == -1)
		return (ft_free_tab((void **)files_arr));
	return (files_arr);
}

static int join_dirs(char **files_arr, unsigned int *i, char **next_dir, char *dir_name)
{
	char *temp;

	if (ft_strncmp(files_arr[(*i)], ".", 2) == 0)
		(*i)++;
	if (ft_strncmp(files_arr[(*i)], "..", 3) == 0)
		(*i)++;
	if (!(files_arr[(*i)]))
		return (1);
	temp = ft_strjoin(dir_name, "/");
	*next_dir = ft_strjoin(temp, files_arr[(*i)]);
	free(temp);
	(*i) += 1;
	return (OK);
}

int ft_dirwalk(char *dir_name, char **argv, void (*print)(char **, t_ls *), t_ls *f)
{
	char *next_dir;
	char **files_arr;
	unsigned int i;

	i = 0;
	if (!dir_name || !dir_name[0])
		return (OK);
	if (!(files_arr = ft_write_to_arr(dir_name, f)))
		return (FAIL);
	if (*files_arr == NULL)
	{
		ft_printf("%cyan%%s:%eoc%\n", dir_name);
		return (OK);
	}
	if ((f->arg_nb > 2 || ft_arr_len(files_arr) > 0) && f->first_dir == 0)
		ft_printf("%cyan%%s:%eoc%\n", dir_name);
	ft_ascii_sort(files_arr);
	print(files_arr, f);
	while (files_arr[i])
	{
		if (join_dirs(files_arr, &i, &next_dir, dir_name) == 1)
			return (OK);
		if (ft_isdir(next_dir))
		{
			write(1, "\n", 1);
			f->first_dir = 0;
			ft_dirwalk(next_dir, argv, print, f);
		}
		free(next_dir);
	}
	ft_free_tab((void**)files_arr);
	return (OK);
}


