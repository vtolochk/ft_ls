/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:37:20 by vtolochk          #+#    #+#             */
/*   Updated: 2017/12/08 16:48:04 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void    ft_free_tab(void **tab)
{
    size_t i;

    i = 0;
	if (tab == 0)
		return ;
    while ((char *)tab[i] != 0)
    {
        free((char *)tab[i]);
        i++;
    }
    free(tab);
    tab = 0;
}
