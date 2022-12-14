# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:07:14 by alvgomez          #+#    #+#              #
#    Updated: 2022/12/14 14:23:17 by alvgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a
NAME = push_swap
#BONUS = push_swap_bonus 
SRCS = push_swap.c push_swap_utils.c push_swap_stack.c push_swap_algorithm.c push_swap_utils_algorithm.c push_swap_split.c push_swap_moves.c
#SRCS_BONUS = push_swap_bonus.c 
CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}
#OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all:	${NAME}
		 
${NAME}:	${LIBFT} ${OBJS} 
		${CC}  ${FLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}:
		${MAKE} -C libft all

#${BONUS}:	${LIBFT} ${OBJS_BONUS} 
#		${CC}  ${FLAGS} ${OBJS_BONUS} ${LIBFT} -o ${BONUS}

#bonus:	${BONUS} 

clean:	
		@rm -f ${OBJS}
#		@rm -f ${OBJS_BONUS}
		@${MAKE} -C libft clean

fclean:	clean
		@rm -f ${NAME}
#		@rm -f ${BONUS}
		@${MAKE} -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus