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

//int ft_simple_print(char *path)
//{
//
//
//}
int ft_ls(int argc, char **argv)
{
	int ret;
	t_ls_flgs flags;

	ret = 0;
	if (ft_get_flags(argc, argv, &flags) == 1)
		return (1);

	ft_printf("flags list: %c\n", flags.list == 0 ? '0' : '1');
	ft_printf("flags recursion: %c\n", flags.recursion == 0 ? '0' : '1');
	ft_printf("flags all: %c\n", flags.all == 0 ? '0' : '1');
	ft_printf("flags reverse: %c\n", flags.reverse == 0 ? '0' : '1');
	ft_printf("flags lex_sort: %c\n", flags.lex_sort == 0 ? '0' : '1');
	ft_printf("flags time_sort: %c\n", flags.time_sort == 0 ? '0' : '1');
	return (ret);
}

int main(int argc, char **argv)
{
	return (ft_ls(argc, argv));
}
