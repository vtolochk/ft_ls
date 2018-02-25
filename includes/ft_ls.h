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
	char third_minus;
	char first_dir;
	char files_second;
	unsigned int arg_nb;
	char next_dir;
	char *path_to_dir;
	char one_minus;
	char printed;
}               t_ls;

unsigned int ft_arr_len(char **arr);
void ft_one_print(char **file, t_ls *data);
void ft_long_print(char **file, t_ls *data);
int ft_ls(char **arg_files, t_ls *flags, void (*func)(char **, t_ls *));
char ft_isdir(char *dir, t_ls *f, char **files_arr);
int ft_dirwalk(char *dir_name, void (*print)(char **, t_ls *), t_ls **f);
int ft_print_errno(char *file_name);
char **ft_get_arg_files(int argc, char **argv, t_ls *f);
long int ft_files_nb(char *file_name, t_ls *f);
int ft_get_flags(int argc, char **argv, t_ls *flgs);
char ft_get_file_type(char *file_name);
void ft_ascii_sort(char **arr, char reverse);
void ft_error_first(char **arg_files, t_ls *f);
void ft_files_second (char **arg, t_ls *f, void (*print)(char **, t_ls *), int k);
void ft_dirs_third(char **arg_f, void (*print)(char **, t_ls *), t_ls **f, int i);
char **ft_write_to_arr(char *file_name, t_ls **f);
void ft_time_sort(char **arr, t_ls *f, char *arg_path);
int ft_is_link(char *dir);
void print_file_mode(char *file, mode_t st_mode);
char *l_v(char *file);
unsigned int ft_get_user_indent(char **files, t_ls *data, unsigned int temp);
unsigned int ft_get_grg_indent(char **files, t_ls *data, unsigned int temp);
unsigned int ft_get_size_width(char **files, t_ls *data);
void ft_print_owner_and_group(struct stat s, int usr, int grg, int lnk);
int ls_time_cmp(struct stat stat_1, struct stat stat_2, t_ls *f);

#endif
