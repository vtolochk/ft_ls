/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:02:20 by vtolochk          #+#    #+#             */
/*   Updated: 2018/02/26 14:03:45 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned int	ft_get_user_indent(char **files, t_ls *data, unsigned int temp)
{
	unsigned int	i;
	unsigned int	indent;
	struct passwd	*user_id;
	struct stat		status;
	char			*str;

	i = 0;
	indent = 0;
	while (files[i++])
	{
		str = ft_strjoin(data->path_to_dir, files[i]);
		lstat(str, &status);
		user_id = getpwuid(status.st_uid);
		if (str && user_id)
			if (indent <= (temp = (unsigned int)ft_strlen(user_id->pw_name)))
				indent = temp;
		ft_strdel(&str);
	}
	return (indent);
}

unsigned int	ft_get_grg_indent(char **files, t_ls *data, unsigned int temp)
{
	unsigned int	i;
	unsigned int	indent;
	struct group	*group_id;
	struct stat		status;
	char			*str;

	i = 0;
	indent = 0;
	while (files[i])
	{
		str = ft_strjoin(data->path_to_dir, files[i++]);
		lstat(str, &status);
		group_id = getgrgid(status.st_gid);
		if (str && group_id)
			if (indent <= (temp = (unsigned int)ft_strlen(group_id->gr_name)))
				indent = temp;
		ft_strdel(&str);
	}
	return (indent);
}

unsigned int	ft_get_size_width(char **files, t_ls *data)
{
	char			*temp;
	unsigned int	i;
	struct stat		status;
	unsigned int	size_width;
	unsigned int	temp_width;

	i = 0;
	size_width = 0;
	while (files[i])
	{
		temp = ft_strjoin(data->path_to_dir, files[i++]);
		lstat(temp, &status);
		ft_strdel(&temp);
		temp = ft_itoa((int)status.st_size);
		temp_width = (unsigned int)ft_strlen(temp);
		if (size_width <= temp_width)
			size_width = temp_width;
		ft_strdel(&temp);
	}
	return (size_width);
}
