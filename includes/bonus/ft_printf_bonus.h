/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:58:54 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/19 14:34:13 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"

# define ZERO	0b000001
# define PLUS	0b000010
# define SPACE	0b000100
# define LEFT	0b001000
# define HASH	0b010000

typedef struct s_node
{
	int				character;
	struct s_node	*next;
}					t_node;

typedef struct s_format
{
	char			c;
	t_node			*characters;
	int				flags;
	int				len;
	int				precision;
	t_node			*space;
	unsigned char	sign;
	int				width;
}		t_format;

void	ft_add_extra(t_node **characters, char c, t_format *conf);
void	ft_build(t_node **list, t_format *conf);
void	ft_build_character(t_node **list, int character, t_format *conf);
void	ft_build_config(t_format **conf, int nb);
void	ft_build_hexadecimal(t_node **list, int nb, char *base, t_format *conf);
void	ft_build_number(t_node **list, int nb, t_format *conf);
void	ft_build_pointer(t_node **list, unsigned long long nb, t_format *conf);
void	ft_build_string(t_node **list, const char *str, t_format *conf);
void	ft_build_unsigned(t_node **list, unsigned int nb, t_format *conf);
char	*ft_find_characters(const char *s, int c);
void	lstcat(t_node **list, t_node **src, int size);
t_node	*lstnew(int character);
void	lstadd_back(t_node **list, t_node *node);
void	lstadd_front(t_node **list, t_node *node);
size_t	lstsize(t_node *list);
int		ft_printf(const char *fmt, ...);

#endif
