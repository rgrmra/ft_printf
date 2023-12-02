# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 21:53:04 by rde-mour          #+#    #+#              #
#    Updated: 2023/11/29 20:10:15 by rde-mour         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

RED					= \033[0;91m
GREEN				= \033[0;92m
YELLOW				= \033[0;93m
BLUE				= \033[0;94m
PURPLE				= \033[0;95m
RESET				= \033[0m

NAME				= libftprintf.a

FILES				= ft_printf.c \
					  ft_printf_utils.c \
					  ft_build_string.c \
					  ft_build_number.c \
					  ft_build_unsigned.c \
					  ft_build_hexadecimal.c \
					  ft_build_pointer.c \

FILES_BONUS			:= $(FILES:%.c=%_bonus.c) \
					  ft_build_character_bonus.c \
					  ft_find_characters_bonus.c \
					  ft_build_config_bonus.c \
					  ft_build_bonus.c

SRCSDIR				= srcs
OBJSDIR 			= objs

INCLUDES			= includes
BONUS				= bonus

SRCSDIR_BONUS		= $(SRCSDIR)/$(BONUS)
OBJSDIR_BONUS		= $(OBJSDIR)/$(BONUS)
INCLUDES_BONUS		= $(INCLUDES)/$(BONUS)

SRCS				= $(FILES:%.c=$(SRCSDIR)/%.c)
OBJS				= $(FILES:%.c=$(OBJSDIR)/%.o)
OBJS_BONUS			= $(FILES_BONUS:%.c=%.o)

DELETE_FILES		= $(FILES_BONUS:%.c=$(OBJSDIR_BONUS)/%.o)
DELETE				= $(OBJS_BONUS)

MESSAGE				= mandatory

COMPILER			= cc
CFLAGS				= -Wall -Wextra -Werror

ifdef				WITH_BONUS
					DELETE_FILES = $(FILES:%.c=$(OBJSDIR)/%.o)
					DELETE = $(FILES:%.c=%.o)
					SRCS := $(FILES_BONUS:%.c=$(SRCSDIR_BONUS)/%.c)
					OBJS := $(FILES_BONUS:%.c=$(OBJSDIR_BONUS)/%.o)
					INCLUDES := $(INCLUDES_BONUS)
					MESSAGE = bonus
endif

all:				$(NAME)

$(NAME): 			$(OBJS)
					@rm -Rf $(DELETE_FILES)
					@ar -d $(NAME) $(DELETE)
					@echo "$(BLUE)Compiled $(MESSAGE) successfully"

$(OBJSDIR)/%.o: 	$(SRCSDIR)/%.c
					@mkdir -p $(@D)
					@$(COMPILER) $(CFLAGS) -I $(INCLUDES) -c $< -o $@
					@echo "$(GREEN)Compiled $(RESET)$(notdir $<)"
					@ar rcs $(NAME) $@
					@echo "$(GREEN)Added to $(RESET)$(NAME)"

bonus:
					@make WITH_BONUS=TRUE --no-print-directory

clean:
					@echo "$(RED)Removing$(RESET) objects"
					@rm -Rf $(OBJSDIR)

fclean: 			clean
					@echo "$(RED)Removing$(RESET) $(NAME)"
					@rm -f $(NAME)

re: 				fclean all

.PHONY: 			all clean fclean bonus re
