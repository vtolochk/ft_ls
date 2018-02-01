/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_factorial.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:38:25 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/30 13:05:51 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s, size_t n)
{
	char *ptr;

	if (s == NULL || n == 0)
		return (NULL);
	if (!(ptr = ft_strnew(n)))
		return (NULL);
	ft_strncpy(ptr, s, n);
	return (ptr);
}
