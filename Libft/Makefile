# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 16:48:11 by vtolochk          #+#    #+#              #
#    Updated: 2018/01/31 15:36:53 by vtolochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

HEADER = libft.h

VPATH = srcs

vpath % srcs/ft_printf

ORIGINAL_LIST = ft_atoi.c ft_bzero.c ft_free_tab.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_itoa_base.c \
		ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memdel.c ft_memmove.c ft_memset.c ft_power.c ft_strcat.c \
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
		ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtolower.c \
		ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c ft_get_bytes.c \
		check_for_additional_arg.c check_for_specifiers.c colors.c  \
		format_and_print.c ft_binary.c ft_check_prefix.c ft_end_printf.c \
		ft_float.c ft_get_act_bits.c ft_pointer.c ft_printf.c \
		ft_putchar.c ft_snumbers.c ft_unumbers.c ft_uputstr.c \
		ft_ustrlen.c ft_ustrsub.c handling_strings.c helpers.c if_functions.c \
		initialization.c

OBJ_LIST = $(patsubst %.c, %.o, $(ORIGINAL_LIST))

CFLAGS = -Wall -Werror -Wextra -Iincludes

CC = gcc

all: $(NAME) $(OBJ_LIST)

$(NAME): $(OBJ_LIST)
	@$(AR) rc $(NAME) $(OBJ_LIST)
	@echo "Libft.a created"

clean:
	@$(RM) $(OBJ_LIST)
	@echo "Object files were deleted"

fclean: clean
	@$(RM) $(NAME) 
	@echo "Libft.a was deleted"

re: fclean all
