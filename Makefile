# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 10:21:26 by vtolochk          #+#    #+#              #
#    Updated: 2018/02/08 15:25:29 by vtolochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = ft_ls

LIB_NAME = libft.a

SRCS = ft_ls.c ft_get_flags.c Libft/libft.a

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
