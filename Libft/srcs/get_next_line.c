/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:52:08 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/08 13:54:36 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t		ft_read_line(char **line, char *ptr[128], int fd)
{
	char		*temp;
	char		*find;
	ssize_t		ret;
	char		buf[BUFF_SIZE + 1];

	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	temp = ptr[fd];
	ptr[fd] = ft_strjoin(ptr[fd], buf);
	ft_strdel(&temp);
	if ((find = ft_strchr(ptr[fd], '\n')))
	{
		*line = ft_strsub(ptr[fd], 0, find - ptr[fd]);
		temp = ptr[fd];
		ptr[fd] = ft_strdup(find + 1);
		ft_strdel(&temp);
	}
	else if (!ret && ft_strlen(ptr[fd]))
	{
		*line = ft_strdup(ptr[fd]);
		ft_strdel(&ptr[fd]);
	}
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	ssize_t			ret;
	static char		*ptr[128];

	ret = 1;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	ptr[fd] = ptr[fd] ? ptr[fd] : ft_strnew(0);
	while (ret > 0)
	{
		ret = ft_read_line(line, ptr, fd);
		if (*line)
			return (1);
	}
	ft_strdel(&ptr[fd]);
	return ((int)ret);
}
