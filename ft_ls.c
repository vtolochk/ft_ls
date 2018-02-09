/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:58:05 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/07 10:55:35 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

//int ft_simple_print(char *dir_name)
//{
//
//
//}
// START FROM THIS FUNCTION PLEASE :D ILY
const char *ft_get_start_dir_name(int argc, char **argv)
{
	while (argc-- != 1)
	{
		if (**argv == '-')
		{
			(*argv)++;
			continue ;
		}
		else
		{
			return (*argv);
		}
		(*argv)++;
	}
	return (".");
}

int ft_ls(int argc, char **argv)
{
	t_ls_flgs flags;
	DIR *dir_stream;
	struct dirent *dir;

	if (ft_get_flags(argc, argv, &flags))
		return (1);

	ft_printf("argc is %d\n", argc);
	ft_printf("start directory is: %s\n", ft_get_start_dir_name(argc, argv));

	dir_stream = opendir(ft_get_start_dir_name(argc, argv));

	while ((dir = readdir(dir_stream)) != NULL)
		ft_printf("%s\n", dir->d_name);
	closedir(dir_stream);
	return (0);
}

int main(int argc, char **argv)
{
	return (ft_ls(argc, argv));
}
