/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:59:16 by vtolochk          #+#    #+#             */
/*   Updated: 2017/11/24 12:58:59 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fill_array(char **ptr, const char *s, char c, size_t words_sum)
{
	char		*s_tmp;
	size_t		j;

	s_tmp = (char *)s;
	j = 0;
	while (j != words_sum)
	{
		while (*s == c)
			s++;
		s_tmp = (char *)s;
		while (*s != c && *s != '\0')
			s++;
		*(ptr + j) = ft_strsub(s_tmp, 0, s - s_tmp);
		if (*(ptr + j) == NULL)
			return (1);
		j++;
	}
	*(ptr + words_sum) = NULL;
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**ptr;
	size_t		words_sum;

	if (s == NULL)
		return (NULL);
	words_sum = ft_get_items(s, c);
	if (!(ptr = (char **)malloc(sizeof(char *) * (words_sum + 1))))
		return (NULL);
	if (words_sum == 0)
	{
		*ptr = 0;
		return (ptr);
	}
	if (ft_fill_array(ptr, s, c, words_sum) == 1)
		return (NULL);
	return (ptr);
}
