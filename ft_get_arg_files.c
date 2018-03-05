/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:19:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 17:59:23 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_while_flags(int *argc, char **argv, unsigned int *j, t_ls *f)
{
	if (f->one_minus == 1)
	{
		(*j)++;
		return ;
	}
	while (*argc != 1 && (argv[(*j)][0] == '-'))
	{
		if (argv[(*j)++][1] == '-')
		{
			(*j)++;
			if (f->double_minus == 1)
				(*j)--;
			if (f->third_minus == 1)
				(*j) -= 2;
			break ;
		}
		(*argc)--;
	}
}

char			**ft_get_arg_files(int argc, char **argv, t_ls *f)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;
	char			**files_names;

	i = 0;
	j = 1;
	tmp = argc;
	if (!(files_names = (char **)malloc((argc + 1) * sizeof(char *))))
		return (NULL);
	if (argc == 1)
		files_names[i++] = ft_strdup(".");
	ft_while_flags(&argc, argv, &j, f);
	if (argc == 1 && tmp != 1)
		files_names[i++] = ft_strdup(".");
	while (argc != 1)
	{
		files_names[i++] = ft_strdup(argv[j++]);
		argc--;
	}
	if (files_names[0] == NULL && !f->one_minus)
		files_names[0] = ft_strdup(".");
	files_names[i] = NULL;
	return (files_names);
}
