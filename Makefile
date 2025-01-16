# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 20:45:33 by mcauchy-          #+#    #+#              #
#    Updated: 2025/01/16 13:00:26 by mcauchy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS_FILES	=	init.c move_p.c move_r.c move_rr.c move_s.c parsing.c	\
				push_swap.c radix_sort.c simple_sort_utils.c 			\
				simple_sort.c split.c utils_init_lst.c utils_list.c		\
				utils_parse.c index.c

SRC_DIR		=	srcs

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES))

OBJS		=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES:.c=.o))

HEADER		=	-I includes/push_swap.h

CC			=	cc 

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

GREEN		=	\033[1;32m

YELLOW		=	\033[1;33m

RED			=	\033[1;31m

RESET		=	\033[0m

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			@echo "$(GREEN)Compilation done !$(RESET)"

%.o		:	%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@
			@echo "Compilation of $< done !"

clean	:
			/bin/rm -rf $(OBJS)
			@echo "$(RED)Objects deleted !$(RESET)"

fclean	:	clean
			/bin/rm -rf $(NAME)
			@echo "$(YELLOW)Executable deleted !$(RESET)"

re		:	fclean all

.PHONY:		all clean fclean re%
