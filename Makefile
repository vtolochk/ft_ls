# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 10:21:26 by vtolochk          #+#    #+#              #
#    Updated: 2018/03/04 09:56:32 by vtolochk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = ft_ls

SRCS = ft_ls.c recursion.c ft_get_flags.c perm_and_ext_attr.c \
	   ft_get_arg_files.c helpers.c ft_ascii_sort.c one_print.c \
	   dirs_from_arguments.c ft_write_to_arr.c long_print.c time_sort.c \
	   ft_files_second.c ft_is_dir.c ft_print_file_mode.c get_identation.c \

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -Iincludes

CC = gcc

all: $(NAME)

$(NAME): $(OBJ) 	
	@make -C ./Libft/
	@gcc -L Libft/ -lft $(OBJ) -o $(NAME)
	@echo "Finished."

clean: 
	@make -C Libft/ clean
	@$(RM) -f $(OBJ)

fclean: clean
	@make -C Libft/ fclean
	@$(RM) $(NAME)
	@echo "ft_ls was deleted"

re: fclean all
