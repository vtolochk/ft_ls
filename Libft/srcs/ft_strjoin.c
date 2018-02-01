/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:18:09 by vtolochk          #+#    #+#             */
/*   Updated: 2017/11/24 12:54:08 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *temp_ptr;
	char *ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(temp_ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ptr = temp_ptr;
	while (*s1 != '\0')
	{
		*temp_ptr = *s1;
		temp_ptr++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*temp_ptr = *s2;
		temp_ptr++;
		s2++;
	}
	return (ptr);
}
