/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:19:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/10 16:19:00 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char **ft_get_arg_files(int argc, char **argv)
{
	unsigned int i;
	unsigned int j;
	char **files_names;

	i = 0;
	j = 1;
	files_names = (char **)malloc(argc * sizeof(char *));
	if (argc == 1)
		files_names[i++] = ft_strdup(".");
	while (argc != 1 && (argv[j][0] == '-'))
	{
		if ( argv[j++][1] == '-')
		{
			j++;
			break;
		}
		argc--;
	}
	while (argc != 1)
	{
		files_names[i++] = ft_strdup(argv[j++]);
		argc--;
	}
	files_names[i] = NULL;
	return (files_names);
}