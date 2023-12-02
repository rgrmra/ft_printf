/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_hexadecimal_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:54:21 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/17 20:38:18 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_putnbr(t_node **list, int nb, char *base)
{
	long	nbr;

	nbr = (long) nb;
	if (nbr < 0)
		nbr = 4294967295 + nbr + 1;
	if (nbr < 16)
		lstadd_back(list, lstnew(base[nbr]));
	if (nbr >= 16)
	{
		ft_putnbr(list, nbr / 16, base);
		ft_putnbr(list, nbr % 16, base);
	}
}

void	ft_build_hexadecimal(t_node **list, int nb, char *base, t_format *conf)
{
	int	size;

	conf -> flags &= ~SPACE;
	conf -> flags &= ~PLUS;
	ft_build_config(&conf, 0);
	conf -> characters = 0;
	if (conf -> precision != 0 || nb != 0)
	{
		ft_putnbr(&(conf -> characters), nb, base);
		if (conf -> flags & HASH && nb != 0)
		{
			size = lstsize(conf -> characters);
			if (conf -> precision > size)
			{
				conf -> precision -= size;
				while (conf -> precision--)
					lstadd_front(&(conf -> characters), lstnew('0'));
			}
			lstadd_front(&(conf -> characters), lstnew(*(base + 10) + 23));
			lstadd_front(&(conf -> characters), lstnew('0'));
		}
	}
	ft_build(list, conf);
}
