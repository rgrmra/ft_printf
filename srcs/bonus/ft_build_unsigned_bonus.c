/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:29:48 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/16 21:04:26 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_putnbr(t_node **list, unsigned int nbr)
{
	if (nbr < 10)
		lstadd_back(list, lstnew(nbr + 48));
	if (nbr >= 10)
	{
		ft_putnbr(list, nbr / 10);
		ft_putnbr(list, nbr % 10);
	}
}

void	ft_build_unsigned(t_node **list, unsigned int nb, t_format *conf)
{
	conf -> flags &= ~PLUS;
	conf -> flags &= ~HASH;
	conf -> flags &= ~SPACE;
	ft_build_config(&conf, 0);
	conf -> characters = 0;
	if (conf -> precision != 0 || nb != 0)
		ft_putnbr(&(conf -> characters), nb);
	ft_build(list, conf);
}
