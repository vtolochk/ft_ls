/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:37:02 by vtolochk          #+#    #+#             */
/*   Updated: 2017/11/24 12:42:15 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*temp_ptr;
	char			*ptr;
	size_t			i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (!(temp_ptr = (char *)malloc(i + 1)))
		return (NULL);
	ptr = temp_ptr;
	while (i-- > 0)
	{
		*temp_ptr = f(*s);
		temp_ptr++;
		s++;
	}
	*temp_ptr = '\0';
	return (ptr);
}
