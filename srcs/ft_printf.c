/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:30:27 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/05 22:06:58 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_args(t_node **list, const char *fmt, va_list args)
{
	while (*fmt)
	{
		if (*fmt == '%' && fmt++)
		{
			if (*fmt == 'c')
				lstadd_back(list, lstnew(va_arg(args, int)));
			else if (*fmt == 's')
				ft_build_string(list, va_arg(args, char *));
			else if (*fmt == 'p')
				ft_build_pointer(list, va_arg(args, unsigned long), HEX_LOWER);
			else if (*fmt == 'd' || *fmt == 'i')
				ft_build_number(list, va_arg(args, int));
			else if (*fmt == 'u')
				ft_build_unsigned(list, va_arg(args, unsigned int));
			else if (*fmt == 'x')
				ft_build_hexadecimal(list, va_arg(args, int), HEX_LOWER);
			else if (*fmt == 'X')
				ft_build_hexadecimal(list, va_arg(args, int), HEX_UPPER);
			else if (*fmt == '%')
				lstadd_back(list, lstnew('%'));
			fmt++;
		}
		else
			lstadd_back(list, lstnew(*fmt++));
	}
}

int	ft_printf(const char *fmt, ...)
{
	size_t			size;
	va_list			args;
	static t_node	*list;
	t_node			*tmp;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	check_args(&list, fmt, args);
	va_end(args);
	size = lstsize(list);
	while (list)
	{
		tmp = list;
		write(1, &(list -> character), 1);
		list = list -> next;
		free(tmp);
	}
	return (size);
}
