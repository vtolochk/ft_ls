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

static void ft_while_flags(int *argc, char **argv, unsigned int *j, char flag)
{
	while (*argc != 1 && (argv[(*j)][0] == '-'))
	{
		if (argv[(*j)++][1] == '-')
		{
			(*j)++;
			if (flag)
				(*j)--;
			break;
		}
		(*argc)--;
	}
}

char **ft_get_arg_files(int argc, char **argv, char flag_special)
{
	unsigned int i;
	unsigned int j;
	int tmp;
	char **files_names;

	i = 0;
	j = 1;
	tmp = argc;
	if (!(files_names = (char **)malloc((argc - 1) * sizeof(char *))))
		return (NULL);
	if (argc == 1)
		files_names[i++] = ft_strdup(".");
	ft_while_flags(&argc, argv, &j, flag_special);
	if (argc == 1 && tmp != 1)
		files_names[i++] = ft_strdup(".");
	while (argc != 1)
	{
		files_names[i++] = ft_strdup(argv[j++]);
		argc--;
	}
	files_names[i] = NULL;
	return (files_names);
}