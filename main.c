/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:58:05 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/02 15:43:51 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/xattr.h>

void ft_print_type(unsigned char d_type)
{
	if (d_type == DT_UNKNOWN)
		ft_printf("unkown file\t");
	else if (d_type == DT_FIFO)
		ft_printf("FIFO file\t");
	else if (d_type == DT_CHR)
		ft_printf("Charater device file\t");
	else if (d_type == DT_DIR)
		ft_printf("Directory file\t");
	else if (d_type == DT_BLK)
		ft_printf("Block device file\t");
	else if (d_type == DT_REG)
		ft_printf("Regular file\t");
	else if (d_type == DT_LNK)
		ft_printf("Symbolic link\t");
	else if (d_type == DT_SOCK)
		ft_printf("A local-domain socket\t");
	else if (d_type == DT_WHT)
		ft_printf("without inode\t");
	else
		ft_printf("I cant understand what it is\t");
}
int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *s_dir;
	struct stat	 s_stat;
	struct passwd *s_pass;
	struct group *s_grg;
	
	if (argc == 1)
		dir = opendir(".");
	else
		dir = opendir(argv[1]);
	
	while ((s_dir = readdir(dir)) != NULL)
	{
		if (s_dir->d_name[0] == '.')
			continue;
		lstat(s_dir->d_name, &s_stat);
		ft_print_type(s_dir->d_type);	
		ft_printf("%lld ", s_stat.st_nlink);
		
		//get user and group name
		s_pass = getpwuid(s_stat.st_uid);
		ft_printf("%s  ", s_pass->pw_name);
		s_grg = getgrgid(s_stat.st_gid);
		ft_printf("%s  ", s_grg->gr_name);
		//	end of this shit	

		ft_printf("%lld  ", s_stat.st_size);
		ft_printf("%s\n", s_dir->d_name);
	}
	closedir(dir);
	return (0);	
}
