/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 12:28:35 by vtolochk          #+#    #+#             */
/*   Updated: 2017/11/23 13:42:31 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_items(char const *s, char c)
{
	size_t sum;
	size_t j;
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	j = ft_strlen(s) - 1;
	sum = 1;
	if (j + 1 == 0)
		return (0);
	while (*(s + i) == c)
		i++;
	if (*(s + i) == '\0')
		return (0);
	while (*(s + j) == c)
		j--;
	while (i++ < j)
	{
		if (*(s + i) == c)
			sum++;
		while (*(s + i) == c)
			i++;
	}
	return (sum);
}
