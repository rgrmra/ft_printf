/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:54:21 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/05 20:01:20 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_build_hexadecimal(t_node **list, int nb, const char *base)
{
	long	nbr;

	nbr = (long) nb;
	if (nbr < 0)
		nbr = 4294967295 + nbr + 1;
	if (nbr < 16)
		lstadd_back(list, lstnew(*(base + nbr)));
	if (nbr >= 16)
	{
		ft_build_hexadecimal(list, nbr / 16, base);
		ft_build_hexadecimal(list, nbr % 16, base);
	}
}
