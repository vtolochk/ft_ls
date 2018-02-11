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

static void ft_stupid_print(char **files_arr) // delete this function please :)
{
	int i = 0;
	ft_printf("%green%NEXT DIR\n%eoc%");
	while (files_arr[i])
		ft_printf("%s\n", files_arr[i++]);
}

unsigned int ft_files_nb(char *file_name)
{
	DIR *dir_stream;
	unsigned int files_nb;

	files_nb = 0;
	dir_stream = opendir(file_name);
	while (readdir(dir_stream) != NULL)
		files_nb++;
	closedir(dir_stream);
	return (files_nb);
}

static char **ft_write_to_arr(char *file_name)
{
	DIR *dir_stream;
	struct dirent *dir;
	char **files_arr;
	unsigned int i;

	i = 0;
	files_arr = (char **)malloc(sizeof(char*) * ft_files_nb(file_name));
	dir_stream = opendir(file_name);
	while ((dir = readdir(dir_stream)) != NULL)
	{
		if (dir->d_name[0] == '.' || (dir->d_name[0] == '0' && dir->d_name[1] == '.'))
			continue;
		files_arr[i] = ft_strjoin("/", dir->d_name);
		i++;
	}
	files_arr[i] = NULL;
	closedir(dir_stream);
	return (files_arr);
}

char *ft_check_for_dir(char **files_arr, char **root, unsigned int *i)
{
	char file_type;
	char *temp;

	while (files_arr[*i])
	{
		temp = ft_strjoin(*root, files_arr[*i]);
		file_type = ft_get_file_type(temp);
		if (file_type == 'd')
		{

		// start here u need to join strings into recursion
			return (files_arr[(*i)++]);
		}
		free(temp);
		i++;
	}
	char *tmp = ft_strrchr(*root, '/'); // maybe stupid thing
	*tmp = '\0';
	*root = ft_strdup(tmp);
	return (NULL);
}

int ft_ls_recursion(char *dir_name, char *root)
{
	char *next_dir;
	char **files_arr;
	unsigned int i;

	i = 0;
	if (dir_name == NULL)
		return (OK);
	next_dir = NULL;
	files_arr = ft_write_to_arr(root);
	if (*files_arr == NULL) // if directory empty
		return (OK);
	ft_ascii_sort(files_arr);
	ft_stupid_print(files_arr);
	if ((next_dir = ft_check_for_dir(files_arr, &root, &i)) != NULL)
		ft_ls_recursion(next_dir, root);
	return (OK);
}