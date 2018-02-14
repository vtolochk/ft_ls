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

static void ft_stupid_print(char **files_arr, char *dir_name) // delete this function please :)
{
	int i = 0;
	ft_printf("%+blue%%s\n%eoc%", dir_name);
	while (files_arr[i])
		ft_printf("%s\n", files_arr[i++]);
}

long int ft_files_nb(char *file_name)
{
	DIR *dir_stream;
	unsigned int files_nb;

	files_nb = 0;
	if (!(dir_stream = opendir(file_name)))
		return (-1);
	while (readdir(dir_stream))
		files_nb++;
	if ((closedir(dir_stream) == -1))
		return (-1);
	return (files_nb);
}

static char **ft_write_to_arr(char *file_name)
{
	DIR *dir_stream;
	struct dirent *dir;
	char **files_arr;
	unsigned int i;
	long int files_nb;

	i = 0;
	if (((files_nb = ft_files_nb(file_name)) == -1))
		return (NULL);
	if (!(files_arr = (char **)malloc(sizeof(char *) * files_nb)))
		return (NULL);
	if (!(dir_stream = opendir(file_name)))
		return (ft_free_tab((void **)files_arr));
	while ((dir = readdir(dir_stream)) != NULL)
	{
		if (dir->d_name[0] == '.')
			continue ;
		files_arr[i++] = ft_strdup(dir->d_name);
	}
	files_arr[i] = NULL;
	if (closedir(dir_stream) == -1)
		return (ft_free_tab((void **)files_arr));
	return (files_arr);
}

int ft_dirwalk(char *dir_name, char **argv)
{
	char *next_dir;
	char *temp;
	char **files_arr;
	unsigned int i;

	i = 0;
	if (!dir_name)
		return (OK);
	if (!(files_arr = ft_write_to_arr(dir_name)))
		return (FAIL);
	if (*files_arr == NULL) // if dir is empty
	{
		ft_printf("%blue%%s:%eoc%\n\n", dir_name);
		return (OK);
	}
	ft_ascii_sort(files_arr);
	ft_stupid_print(files_arr, dir_name);
	while (files_arr[i])
	{
		if (files_arr[i][0] == '\0')
			return (OK);
		temp = ft_strjoin(dir_name, "/");
		next_dir = ft_strjoin(temp, files_arr[i]);
		free(temp);
		if (ft_isdir(next_dir))
			ft_dirwalk(next_dir, argv);
		i++;
		free(next_dir);
	}
	ft_free_tab((void**)files_arr);
	return (OK);
}
