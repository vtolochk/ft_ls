/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:58:05 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/31 19:54:57 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>

int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *sd;

	argc--;
	dir = opendir(argv[1]);
	if (dir == NULL)
	{
		ft_printf("error\n");
		return (-1);
	}
	while ((sd = readdir(dir)) != NULL)
	{
		ft_printf(sd->d_name);	
		write(1, "\n", 1);
	}
	closedir(dir);
	return (0);	
}
