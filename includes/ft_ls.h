/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:16:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/08 15:21:30 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "../Libft/includes/libft.h"
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

#define ERROR 1
#define SUCCESS 0

typedef  struct s_ls_flgs
{
	char list;
	char recursion;
	char all;
	char reverse;
	char time_sort;
}               t_ls_flgs;

int ft_print_error(char **argv, char *file_name);
char **ft_get_arg_files(int argc, char **argv);
unsigned int ft_files_nb(char *file_name);
int ft_get_flags(int argc, char **argv, t_ls_flgs *flgs);
char ft_get_file_type(char *file_name);
int ft_ls_print(char *file_name, char **argv, char file_type);
void ft_ascii_sort(char **arr);
void ft_error_first(char **argv, char **arg_files);
void ft_files_second (char **argv, char **arg_files);
void ft_dirs_third(char **argv, char **arg_files);

#endif
