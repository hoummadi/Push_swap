# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 20:00:52 by hhoummad          #+#    #+#              #
#    Updated: 2021/10/16 11:32:55 by hhoummad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

HEADER = common/common.h push_swapfiles/pushswaplib.h

HEADERB = common_bonus/common_bonus.h checkerfiles/pushlib_bonus.h

FLAG = -Wall -Wextra -Werror -c

SRCS =	push_swapfiles/five_numbers.c		\
		push_swapfiles/hundred_numbers.c	\
		push_swapfiles/other_numbers.c		\
		push_swapfiles/push_swap.c			\
		push_swapfiles/push_utils.c			\
		push_swapfiles/push_utils2.c		\
		push_swapfiles/stack_b_helper.c		\
		push_swapfiles/three_numbers.c		\
		push_swapfiles/utils2.c				\
		common/argv_cheker.c				\
		common/errors.c						\
		common/init_stack.c					\
		common/lib_utils.c					\
		common/r_instruction.c				\
		common/s_instruction.c				\
		common/utils.c

SRCSB = checkerfiles/checker_bonus.c			\
		checkerfiles/read_instru_bonus.c		\
		checkerfiles/stack_exec_bonus.c			\
		checkerfiles/utils_ck_bonus.c			\
		common_bonus/argv_cheker_bonus.c		\
		common_bonus/errors_bonus.c				\
		common_bonus/init_stack_bonus.c			\
		common_bonus/lib_utils_bonus.c			\
		common_bonus/r_instruction_bonus.c		\
		common_bonus/s_instruction_bonus.c		\
		common_bonus/utils_bonus.c

OBJ =	five_numbers.o		\
		hundred_numbers.o	\
		other_numbers.o		\
		push_swap.o			\
		push_utils.o		\
		push_utils2.o		\
		stack_b_helper.o	\
		three_numbers.o		\
		utils2.o			\
		argv_cheker.o		\
		errors.o			\
		init_stack.o		\
		lib_utils.o			\
		r_instruction.o		\
		s_instruction.o		\
		utils.o

OBJB =	checker_bonus.o				\
		read_instru_bonus.o			\
		stack_exec_bonus.o			\
		utils_ck_bonus.o			\
		argv_cheker_bonus.o			\
		errors_bonus.o				\
		init_stack_bonus.o			\
		lib_utils_bonus.o			\
		r_instruction_bonus.o		\
		s_instruction_bonus.o		\
		utils_bonus.o

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
		@gcc $(FLAG) $(SRCS)
		@gcc $(OBJ) -o $(NAME)
		@echo "make push_swap"

bonus: $(NAME_B)

$(NAME_B): $(SRCSB) $(HEADERB)
		@gcc $(FLAG) $(SRCSB)
		@gcc $(OBJB) -o $(NAME_B)
		@echo "make checker"

clean:
	@rm -f *.o

fclean:	clean
	@rm -rf checker
	@rm -rf push_swap

re:		fclean all

.PHONY: all clean fclean re bonus
