/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:16:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/06 11:00:24 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "Libft/includes/libft.h"
#include <dirent.h>

typedef  struct s_ls_flgs
{
	char list;
	char recursion;
	char all;
	char reverse;
	char lex_sort;
	char time_sort;
}               t_ls_flgs;

int ft_get_flags(int argc, char **argv, t_ls_flgs *flgs);

#endif
