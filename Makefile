# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 10:21:26 by vtolochk          #+#    #+#              #
#    Updated: 2018/02/21 18:40:34 by vtolochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = ft_ls

LIB_NAME = libft.a

SRCS = ft_ls.c recursion.c ft_get_flags.c Libft/libft.a \
	   ft_get_arg_files.c helpers.c ft_ascii_sort.c one_print.c \
	   dirs_from_arguments.c ft_write_to_arr.c long_print.c time_sort.c

CFLAGS = -Wall -Werror -Wextra -Iincludes

CC = gcc

all: $(NAME)

$(NAME): 	
	@make -C Libft/
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

clean: 
	@make -C Libft/ clean

fclean: clean
	@make -C Libft/ fclean
	@$(RM) $(NAME)
	@echo "ft_ls was deleted"

re: fclean all
