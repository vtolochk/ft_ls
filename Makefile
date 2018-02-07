# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 10:21:26 by vtolochk          #+#    #+#              #
#    Updated: 2018/02/07 14:20:03 by vtolochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = ft_ls

LIB_NAME = libft.a

SRCS = ft_ls.c ft_get_flags.c Libft/libft.a

CFLAGS = -Wall -Werror -Wextra -I.

CC = gcc

all: $(NAME)

$(NAME): 	
	make -C Libft/
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
