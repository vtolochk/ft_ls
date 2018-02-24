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
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define NO_ACCESS "---"
#define X_ACCESS "--x"
#define W_ACCESS "-w-"
#define WX_ACCESS "-wx"
#define R_ACCESS "r--"
#define RX_ACCESS "r-x"
#define RW_ACCESS "rw-"
#define RWX_ACCESS "rwx"

#define FAIL 1
#define OK 0

typedef  struct s_ls
{
	char list;
	char recursion;
	char all;
	char reverse;
	char time_sort;
	char one;
	char big_g;
	char double_minus;
	char first_dir;
	char files_second;
	unsigned int arg_nb;
	char **argv_temp;
	char next_dir;
	char *path_to_dir;
	char one_minus;
	char go_via_link;
}               t_ls;

unsigned int ft_arr_len(char **arr);
void ft_one_print(char **file, t_ls *data);
void ft_long_print(char **file, t_ls *data);
int ft_ls(char **argv, char **arg_files, t_ls *flags, void (*func)(char **, t_ls *));
char ft_isdir(char *dir, t_ls *f, char **files_arr);
int ft_dirwalk(char *dir_name, void (*print)(char **, t_ls *), t_ls **f);
int ft_print_errno(char **argv, char *file_name);
char **ft_get_arg_files(int argc, char **argv, t_ls *f);
long int ft_files_nb(char *file_name, t_ls *f);
int ft_get_flags(int argc, char **argv, t_ls *flgs);
char ft_get_file_type(char *file_name);
void ft_ascii_sort(char **arr, char reverse);
void ft_error_first(char **argv, char **arg_files, t_ls *f);
void ft_files_second (char **arg_files, t_ls *f, void (*print)(char **, t_ls *));
void ft_dirs_third(char **arg_files, void (*print)(char **, t_ls *), t_ls **f);
char **ft_write_to_arr(char *file_name, t_ls **f);
void ft_time_sort(char **arr, t_ls *f, char *arg_path);

#endif
