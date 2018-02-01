/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:03:01 by vtolochk          #+#    #+#             */
/*   Updated: 2017/11/24 12:45:04 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_new;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	if (!(str_new = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i] != '\0')
	{
		str_new[i] = f(i, s[i]);
		i++;
	}
	return (str_new);
}
