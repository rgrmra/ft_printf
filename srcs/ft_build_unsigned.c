/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:29:48 by rde-mour          #+#    #+#             */
/*   Updated: 2023/10/29 17:33:32 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_build_unsigned(t_node **list, unsigned int nbr)
{
	if (nbr < 10)
		lstadd_back(list, lstnew(nbr + 48));
	if (nbr >= 10)
	{
		ft_build_unsigned(list, nbr / 10);
		ft_build_unsigned(list, nbr % 10);
	}
}
