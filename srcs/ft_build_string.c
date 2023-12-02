/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:37:58 by rde-mour          #+#    #+#             */
/*   Updated: 2023/10/29 17:33:21 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_build_string(t_node **list, const char *str)
{
	if (!str)
	{
		ft_build_string(list, "(null)");
		return ;
	}
	while (*str)
		lstadd_back(list, lstnew(*str++));
}
