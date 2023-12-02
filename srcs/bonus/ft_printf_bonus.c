/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:30:27 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/19 19:29:44 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	config(t_node **list, char **fmt, va_list args, t_format *conf)
{
	if (**fmt == 'c' && (*fmt)++)
		ft_build_character(list, va_arg(args, int), conf);
	else if (**fmt == 's' && (*fmt)++)
		ft_build_string(list, va_arg(args, char *), conf);
	else if ((**fmt == 'd' || **fmt == 'i') && (*fmt)++)
		ft_build_number(list, va_arg(args, int), conf);
	else if (**fmt == 'p' && (*fmt)++)
		ft_build_pointer(list, va_arg(args, unsigned long long), conf);
	else if (**fmt == 'u' && (*fmt)++)
		ft_build_unsigned(list, va_arg(args, unsigned long), conf);
	else if (**fmt == 'x' && (*fmt)++)
		ft_build_hexadecimal(list, va_arg(args, int), HEX_LOWER, conf);
	else if (**fmt == 'X' && (*fmt)++)
		ft_build_hexadecimal(list, va_arg(args, int), HEX_UPPER, conf);
}

static void	check_bonus(t_node **list, char **fmt, va_list args, t_format *conf)
{
	conf -> width = 0;
	while (**fmt >= '0' && **fmt <= '9')
	{
		conf -> width = (conf -> width * 10) + **fmt - 48;
		(*fmt)++;
	}
	if (**fmt == '%' && (*fmt)++)
		lstadd_back(list, lstnew('%'));
	else
	{
		conf -> precision = -1;
		if (**fmt == '.' && (*fmt)++)
		{
			conf -> precision = 0;
			while (**fmt >= '0' && **fmt <= '9')
			{
				conf -> precision = (conf -> precision * 10) + **fmt - 48;
				(*fmt)++;
			}
		}
		config(list, fmt, args, conf);
	}
}

static void	check_args(t_node **list, char *fmt, va_list args)
{
	t_format		conf;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			conf.flags = 0;
			while (*fmt++ && *fmt && ft_find_characters("-+ 0#", *fmt))
			{
				if (*fmt == '-')
					conf.flags |= LEFT;
				if (*fmt == '+')
					conf.flags |= PLUS;
				if (*fmt == ' ')
					conf.flags |= SPACE;
				if (*fmt == '0')
					conf.flags |= ZERO;
				if (*fmt == '#')
					conf.flags |= HASH;
			}
			check_bonus(list, &fmt, args, &conf);
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
	check_args(&list, (char *) fmt, args);
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
