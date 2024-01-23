# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 11:43:32 by skorbai           #+#    #+#              #
#    Updated: 2024/01/23 13:41:19 by skorbai          ###   ########.fr        #
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
	sort_large.c \
	sort_large_utils.c \
	sort_large_utils_pt_2.c \
	sort_large_a_to_b.c \
	sort_large_sort_last_3.c \
	sort_large_b_to_a.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = main_bonus.c \
	input_bonus.c \
	commands_doubles_bonus.c \
	commands_stack_a_bonus.c \
	commands_stack_b_bonus.c \
	error_bonus.c \
	check_for_errors_bonus.c \
	test_commands_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = libft/libft.a

NAME = push_swap

BONUS_NAME = checker

all: $(NAME)

$(LIBFT) :
	make -C ./libft

%.o: %.c
	cc $(C_FLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(LIBFT)
	cc $(C_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	@rm -f .bonus
	make clean -C ./libft

fclean: clean 
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	make fclean -C ./libft

re: fclean all

bonus: .bonus

.bonus: $(BONUS_OBJS) $(LIBFT)
	cc $(C_FLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@touch .bonus

my_make: all
	make clean

fsanitize: $(OBJS) $(LIBFT)
	cc $(C_FLAGS) -g -fsanitize=address $(OBJS) $(LIBFT) -o $(NAME)
	make clean

.PHONY: all clean fclean re
	