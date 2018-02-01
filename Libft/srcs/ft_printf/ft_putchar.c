/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:46:55 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/31 15:14:25 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_if_3_bytes(unsigned char *b, unsigned int t, unsigned char o)
{
	b[2] = (t << 26) >> 26;
	b[1] = ((t >> 6) << 26) >> 26;
	b[0] = ((t >> 12) << 28) >> 28;
	o = ((unsigned int)MASK_2 >> 16) | b[0];
	write(1, &o, 1);
	o = (((unsigned int)MASK_2 << 16) >> 24) | b[1];
	write(1, &o, 1);
	o = (((unsigned int)MASK_2 << 24) >> 24) | b[2];
	write(1, &o, 1);
	return (3);
}

static int	ft_if_4_bytes(unsigned char *b, unsigned int t, unsigned char o)
{
	b[3] = (t << 26) >> 26;
	b[2] = ((t >> 6) << 26) >> 26;
	b[1] = ((t >> 12) << 26) >> 26;
	b[0] = ((t >> 18) << 29) >> 29;
	o = ((unsigned int)MASK_3 >> 24) | b[0];
	write(1, &o, 1);
	o = (((unsigned int)MASK_3 << 8) >> 24) | b[1];
	write(1, &o, 1);
	o = (((unsigned int)MASK_3 << 16) >> 24) | b[2];
	write(1, &o, 1);
	o = (((unsigned int)MASK_3 << 24) >> 24) | b[3];
	write(1, &o, 1);
	return (4);
}

static int	ft_if_2_bytes(unsigned char *b, unsigned int t, unsigned char o)
{
	b[1] = (t << 26) >> 26;
	b[0] = ((t >> 6) << 27) >> 27;
	o = ((unsigned int)MASK_1 >> 8) | b[0];
	write(1, &o, 1);
	o = (((unsigned int)MASK_1 << 24) >> 24) | b[1];
	write(1, &o, 1);
	return (2);
}

int			ft_putchar(unsigned int c)
{
	unsigned int	temp;
	unsigned int	size;
	unsigned char	octet;
	unsigned char	byte[4];

	octet = 0;
	while (octet != 4)
		byte[octet++] = '0';
	temp = c;
	size = ft_get_act_bits(c);
	if (size <= 7)
		return (write(1, &c, 1));
	else if (size <= 11)
		return (ft_if_2_bytes(byte, temp, octet));
	else if (size <= 16)
		return (ft_if_3_bytes(byte, temp, octet));
	else
		return (ft_if_4_bytes(byte, temp, octet));
}
