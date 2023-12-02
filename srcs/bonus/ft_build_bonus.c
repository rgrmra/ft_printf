/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:57:10 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/17 18:41:19 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_build(t_node **list, t_format *conf)
{
	conf -> len = lstsize(conf -> characters);
	if (conf -> len > conf -> precision)
		conf -> precision = conf -> len;
	conf -> width -= conf -> precision;
	if (!(conf -> flags & (ZERO + LEFT)))
		while (conf -> width-- > 0)
			lstadd_back(list, lstnew(' '));
	conf -> space = 0;
	if (conf -> sign)
		lstadd_front(&(conf -> space), lstnew(conf -> sign));
	if (!(conf -> flags & LEFT))
		while (conf -> width-- > 0)
			lstadd_back(&(conf -> space), lstnew(conf -> c));
	while (conf -> len < conf -> precision--)
		lstadd_back(&(conf -> space), lstnew('0'));
	lstcat(list, &(conf -> space), lstsize(conf -> space));
	lstcat(list, &(conf -> characters), conf -> len);
	while (conf -> width-- > 0)
		lstadd_back(list, lstnew(' '));
}
