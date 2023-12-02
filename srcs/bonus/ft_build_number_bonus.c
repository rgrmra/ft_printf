/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_number_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:51:46 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/11 18:22:33 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_putnbr(t_node **list, int nb)
{
	long	nbr;

	nbr = (long) nb;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr < 10)
		lstadd_back(list, lstnew(nbr + 48));
	if (nbr >= 10)
	{
		ft_putnbr(list, nbr / 10);
		ft_putnbr(list, nbr % 10);
	}
}

void	ft_build_number(t_node **list, int nb, t_format *conf)
{
	ft_build_config(&conf, nb);
	conf -> characters = 0;
	if (conf -> precision != 0 || nb != 0)
		ft_putnbr(&(conf -> characters), nb);
	ft_build(list, conf);
}
