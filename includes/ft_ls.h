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

#define FAIL 1
#define OK 0

typedef  struct s_ls_flgs
{
	char list;
	char recursion;
	char all;
	char reverse;
	char time_sort;
	char one;
	char flag_special;
}               t_ls_flgs;


unsigned int ft_arr_len(char **arr);
void ft_one_print(char *files);
void ft_simple_print(char *files);
void ft_long_print(char *files);
int ft_ls(char **argv, char **arg_files, t_ls_flgs flags, void (*func)(char *));
char ft_isdir(char *dir);
int ft_dirwalk(char *dir_name, char **argv);
int ft_print_errno(char **argv, char *file_name);
char **ft_get_arg_files(int argc, char **argv, char flag_special);
long int ft_files_nb(char *file_name);
int ft_get_flags(int argc, char **argv, t_ls_flgs *flgs);
char ft_get_file_type(char *file_name);
void ft_ascii_sort(char **arr);
void ft_error_first(char **argv, char **arg_files);
void ft_files_second (char **arg_files, void (*print)(char *));
void ft_dirs_third(char **arg_files, void (*print)(char *));
char **ft_write_to_arr(char *file_name);

#endif
