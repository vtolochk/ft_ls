/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:02:27 by vtolochk          #+#    #+#             */
/*   Updated: 2017/11/24 12:52:16 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *temp_ptr;
	char *ptr;

	if (s == NULL || start > ft_strlen(s))
		return (NULL);
	if (!(temp_ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr = temp_ptr;
	while (len-- > 0 && s[start] != '\0')
	{
		*temp_ptr = s[start];
		start++;
		temp_ptr++;
	}
	*temp_ptr = '\0';
	return (ptr);
}
