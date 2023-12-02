/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:00 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/06 14:25:27 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}

static void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;

	src = (unsigned char *) s;
	while (n--)
	{
		if (*src == (unsigned char) c)
			return ((void *) src);
		src++;
	}
	return (0);
}

char	*ft_find_characters(const char *s, int c)
{
	size_t	size;
	char	*src;

	size = ft_strlen(s);
	src = ft_memchr(s, c, size + 1);
	return (src);
}
