/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:06:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 15:48:03 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_time(struct stat status)
{
	char	*time_str;
	time_t	cur_time;

	cur_time = time(NULL);
	time_str = ctime(&status.st_mtimespec.tv_sec);
	if (time_str)
	{
		time_str += 4;
		if ((cur_time - status.st_mtimespec.tv_sec > 15778463) ||
		cur_time < status.st_mtimespec.tv_sec)
		{
			time_str[7] = '\0';
			write(1, time_str, ft_strlen(time_str));
			time_str += 8;
			ft_printf(" %d ", ft_atoi(ft_strrchr(time_str, ' ') + 1));
		}
		else
		{
			time_str[12] = '\0';
			write(1, time_str, ft_strlen(time_str));
			write(1, " ", 1);
		}
	}
}

void		ft_one_print(char **file, t_ls *data)
{
	unsigned int i;

	i = 0;
	if (!file)
		return ;
	while (file[i])
	{
		if (data->b_a && (!ft_strncmp(file[i], ".", 2) ||
		!ft_strncmp(file[i], "..", 3)))
		{
			i++;
			continue;
		}
		ft_printf("%s\n", file[i]);
		i++;
	}
}
