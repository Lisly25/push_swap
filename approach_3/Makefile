# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 11:43:32 by skorbai           #+#    #+#              #
#    Updated: 2024/01/19 14:01:33 by skorbai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	input.c \
	commands_doubles.c \
	commands_stack_a.c \
	commands_stack_b.c \
	error.c \
	check_for_errors.c \
	get_sort_commands.c \
	sort_3.c \
	sort_5.c \
	sort_small_utils.c \
	sort_large.c \
	sort_large_utils.c \
	sort_large_utils_pt_2.c \
	sort_large_a_to_b.c \
	sort_large_sort_last_3.c \
	sort_large_b_to_a.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

NAME = push_swap

all: $(NAME)

$(LIBFT) :
	make -C ./libft

$(NAME) : $(OBJS) $(LIBFT)
	cc $(C_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean 
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

my_make: all
	make clean

fsanitize: $(OBJS) $(LIBFT)
	cc $(C_FLAGS) -g -fsanitize=address $(OBJS) $(LIBFT) -o $(NAME)
	make clean

.PHONY: all clean fclean re
	