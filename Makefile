# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 11:43:32 by skorbai           #+#    #+#              #
#    Updated: 2024/01/04 11:36:14 by skorbai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	input.c \
	error.c \
	get_sort_commands.c \
	sort_3.c \
	sort_5.c \
	sort_large.c \
	check_for_errors.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

NAME = push_swap

all: $(NAME)

$(LIBFT) :
	make -C ./libft

$(NAME) : $(OBJS) $(LIBFT)
	cc $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean 
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
	