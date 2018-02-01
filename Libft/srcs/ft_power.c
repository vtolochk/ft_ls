/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_pow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:37:00 by vtolochk          #+#    #+#             */
/*   Updated: 2017/11/23 11:16:58 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int num, int power)
{
	int res;

	res = num;
	if (num <= 0 || power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (--power > 0)
		res = res * num;
	return (res);
}
