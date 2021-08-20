# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 21:16:21 by bahn              #+#    #+#              #
#    Updated: 2021/08/20 22:53:38 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

PUSH_SWAP		= push_swap
CHECKER			= checker

INCFLAGS		= -I./includes -I./libft

LIB_DIR			= ./libft
LINK_LIBFT		= -Llibft -lft

SRCS_DIR		= ./srcs/
SRCS_NAME		= push_swap.c a_to_b.c b_to_a.c \
					frame.c stack.c command.c check.c \
					length.c element.c case.c pivot.c \
					swap.c push.c rotate.c reverse_rotate.c
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS			= $(SRCS:.c=.o)

BONUS_SRCS		= ./bonus/checker.c

all				: $(PUSH_SWAP)

bonus			: $(CHECKER)

$(PUSH_SWAP) 	: $(OBJS)
				$(MAKE) all -C $(LIB_DIR)
				$(CC) $(CFLAGS) $(INCFLAGS) $^ $(LINK_LIBFT) -o $@

$(CHECKER)		: $(BONUS_SRCS) 
				$(CC) $(CFLAGS) $(INCFLAGS) $^ $(LINK_LIBFT) -o $@

.c.o			:
				$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean			:
				$(MAKE) -C $(LIB_DIR) clean
				rm -fv $(OBJS) 

fclean			: clean
				$(MAKE) -C $(LIB_DIR) fclean
				rm -fv $(PUSH_SWAP)

re				: fclean all

.PHONY			: all clean fclean re
