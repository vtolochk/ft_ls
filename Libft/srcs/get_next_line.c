/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:52:08 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/30 13:40:38 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

t_lst		*ft_init_node(int fd)
{
	t_lst *list;

	if (!(list = (t_lst *)malloc(sizeof(t_lst) * 1)))
		return (NULL);
	list->fd = fd;
	list->ret = 1;
	list->flag = 0;
	if (!(list->buff = ft_memalloc(1)))
		return (NULL);
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_lst		*ft_find_fd(int fd, t_lst *list)
{
	t_lst	*temp;

	if (list == NULL)
		return (!(list = ft_init_node(fd)) ? NULL : list);
	while (list->next != NULL)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	if (list->fd == fd)
		return (list);
	while (list->prev != NULL)
	{
		if (list->fd == fd)
			return (list);
		list = list->prev;
	}
	if (list->fd == fd)
		return (list);
	if (!(temp = ft_init_node(fd)))
		return (NULL);
	list->prev = temp;
	temp->next = list;
	return (temp);
}

ssize_t		ft_read_line(t_lst *list, int i, char **line, ssize_t ret)
{
	char	*ptr;
	char	*temp;

	temp = ft_strnew(BUFF_SIZE);
	if ((ret = read(list->fd, temp, BUFF_SIZE)) > 0)
	{
		ptr = list->buff;
		list->buff = ft_strjoin(list->buff, temp);
		free(ptr);
	}
	temp == NULL ? ret = -1 : free(temp);
	if (ret == -1)
		return (-1);
	while (list->buff != NULL && list->buff[i] != '\0')
	{
		if (list->buff[i++] == '\n')
		{
			ptr = list->buff;
			*line = ft_strsub(list->buff, 0, i - 1);
			list->buff = ft_strsub(list->buff, i, ft_strlen(list->buff) - i);
			free(ptr);
			return (list->flag = 1);
		}
	}
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static t_lst *list;

	if (fd < 0 || !line || BUFF_SIZE < 0 || !(list = ft_find_fd(fd, list)))
		return (-1);
	list->ret = 1;
	while (list->ret > 0)
	{
		list->ret = ft_read_line(list, 0, line, 0);
		if (list->ret == -1)
			return (-1);
		if (list->flag == 1)
		{
			list->flag = 0;
			return (1);
		}
	}
	if (list->buff == NULL || list->buff[0] == '\0')
		return (0);
	*line = ft_strdup(list->buff);
	free(list->buff);
	list->buff = NULL;
	return (1);
}
