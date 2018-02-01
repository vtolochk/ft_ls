/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:44:43 by vtolochk          #+#    #+#             */
/*   Updated: 2017/11/23 11:16:58 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*little_start;
	size_t		i;
	size_t		a;

	little_start = little;
	a = 0;
	i = len;
	if (*little == '\0')
		return ((char *)big);
	while (len-- > 0 && *big != '\0')
	{
		little = little_start;
		while (*little == *big && i-- > 0 && big++ != '\0')
		{
			a++;
			little++;
			if (*little == '\0')
				return ((char *)big - a);
		}
		big = big - a;
		i = len;
		a = 0;
		big++;
	}
	return (NULL);
}
