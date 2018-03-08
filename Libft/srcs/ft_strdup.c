/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:19:55 by vtolochk          #+#    #+#             */
/*   Updated: 2018/03/08 13:56:35 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*temp;

	if ((len = ft_strlen(s1)) == 0)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * len + 1);
	if (temp == NULL)
		return (NULL);
	while (*s1 != '\0')
		*temp++ = *s1++;
	*temp = '\0';
	return (temp - len);
}
