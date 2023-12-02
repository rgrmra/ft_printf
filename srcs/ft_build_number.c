/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:51:46 by rde-mour          #+#    #+#             */
/*   Updated: 2023/10/29 17:32:53 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_build_number(t_node **list, int nb)
{
	long	nbr;

	nbr = (long) nb;
	if (nbr < 0)
	{
		nbr = -nbr;
		lstadd_back(list, lstnew('-'));
	}
	if (nbr < 10)
		lstadd_back(list, lstnew(nbr + 48));
	if (nbr >= 10)
	{
		ft_build_number(list, nbr / 10);
		ft_build_number(list, nbr % 10);
	}
}
