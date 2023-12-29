/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:54:21 by rde-mour          #+#    #+#             */
/*   Updated: 2023/12/28 21:48:49 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(unsigned long nbr, const char *base, t_node **list)
{
	if (nbr < 16)
		lstadd_back(list, lstnew(*(base + nbr)));
	if (nbr >= 16)
	{
		ft_putnbr(nbr / 16, base, list);
		ft_putnbr(nbr % 16, base, list);
	}
}

void	ft_build_pointer(t_node **list, unsigned long nb, const char *base)
{
	if (!nb)
	{
		ft_build_string(list, "(nil)");
		return ;
	}
	ft_build_string(list, "0x");
	ft_putnbr(nb, base, list);
}
