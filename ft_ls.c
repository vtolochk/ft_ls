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
// bug here:
// after function ft_get flags you lost the - sign and now u cant find right directory :D
// be smart :D I love u p.s. your code:)
char *ft_get_start_dir_name(int argc, char **argv)
{
	argv++;
	while (argc-- != 1)
	{
		if (**argv == '-')
			argv++;
		else
			return (*argv);
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

	// just some tests
	//
	ft_printf("%+yellow%\nSTART OF TESTS\n%green%");
	//dir
	ft_printf("\nSTART DIR IS: %s\n\n", ft_get_start_dir_name(argc, argv));

	//flags
	ft_printf("-l %c\n", flags.list == 0 ? '0' : '1');
	ft_printf("-R %c\n", flags.recursion == 0 ? '0' : '1');
	ft_printf("-a %c\n", flags.all == 0 ? '0' : '1');
	ft_printf("-r %c\n", flags.reverse == 0 ? '0' : '1');
	ft_printf("-t %c\n", flags.time_sort == 0 ? '0' : '1');

	ft_printf("\n%+yellow%END OF TESTS\n\n%eoc%");
	ft_printf("%#green%FT_LS OUTPUT:%cyan%\n");
	//
	// end of tests


	dir_stream = opendir(ft_get_start_dir_name(argc, argv));
	while ((dir = readdir(dir_stream)) != NULL)
		ft_printf("%s\n", dir->d_name);
	closedir(dir_stream);
	ft_printf("%eoc%");
	return (0);
}

int main(int argc, char **argv)
{
	return (ft_ls(argc, argv));
}
