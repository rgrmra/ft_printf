/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_config_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:58:32 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/06 17:40:24 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_build_config(t_format **conf, int nb)
{
	(*conf)-> c = ' ';
	if ((*conf)-> flags & LEFT)
		(*conf)-> flags &= ~ZERO;
	if ((*conf)-> precision >= 0)
		(*conf)-> flags &= ~ZERO;
	if ((*conf)-> flags & ZERO)
		(*conf)-> c = '0';
	(*conf)-> sign = 0;
	if (nb < 0)
		(*conf)-> sign = '-';
	else if ((*conf) && (*conf)-> flags & PLUS && nb > -1)
		(*conf)-> sign = '+';
	else if ((*conf)-> flags & SPACE)
		(*conf)-> sign = ' ';
	if ((*conf)-> sign)
		(*conf)-> width--;
}
