/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 08:24:11 by vtolochk          #+#    #+#             */
/*   Updated: 2017/11/24 12:56:07 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	ptr = NULL;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
	{
		if (!(ptr = (char *)malloc(sizeof(char))))
			return (NULL);
		ft_bzero(ptr, 1);
		return (ptr);
	}
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (!(ptr = ft_strsub(s, i, (j - i) + 1)))
		return (NULL);
	return (ptr);
}
