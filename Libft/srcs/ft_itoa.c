/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:19:37 by vtolochk          #+#    #+#             */
/*   Updated: 2017/11/24 12:59:33 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_alloc(long int n, size_t *i)
{
	char	*s;
	size_t	size;

	s = NULL;
	size = 0;
	if (n < 0)
	{
		n = n * -1;
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	*i = size;
	if (!(s = ft_strnew(size)))
		return (NULL);
	return (s);
}

char			*ft_itoa(int n)
{
	char		*s;
	size_t		i;
	long int	num;

	num = (long int)n;
	i = 0;
	if (num == 0)
		return (s = ft_strdup("0"));
	if (!(s = ft_alloc(num, &i)))
		return (NULL);
	if (num < 0)
	{
		s[0] = '-';
		num = num * (-1);
	}
	while (num > 0)
	{
		s[--i] = (num % 10) + '0';
		num = num / 10;
	}
	return (s);
}
