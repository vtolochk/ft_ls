/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <vtolochk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:51:00 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/27 11:40:02 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	*ft_ustrsub(unsigned int *s, unsigned int st, size_t len)
{
	size_t			i;
	unsigned int	*temp_ptr;
	unsigned int	*ptr;

	i = 0;
	if (s == NULL || st > ft_ustrlen(s))
		return (NULL);
	if (!(temp_ptr = (unsigned int *)malloc(sizeof(unsigned int) * (len + 1))))
		return (NULL);
	ptr = temp_ptr;
	while (s[st] != '\0')
	{
		i += ft_get_bytes(s[st]);
		if (i > len)
			break ;
		*temp_ptr = s[st];
		st++;
		temp_ptr++;
	}
	*temp_ptr = '\0';
	return (ptr);
}
