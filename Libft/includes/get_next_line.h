/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:42:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/30 14:16:08 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 1

typedef struct		s_lst
{
	int				fd;
	ssize_t			flag;
	ssize_t			ret;
	char			*buff;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

int					get_next_line(const int fd, char **line);

#endif
