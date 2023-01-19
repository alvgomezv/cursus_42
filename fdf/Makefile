# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:07:14 by alvgomez          #+#    #+#              #
#    Updated: 2023/01/17 16:12:40 by alvgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a
LIBMLX = ./MLX42/libmlx42.a
NAME = fdf
#BONUS = 
SRCS = fdf.c
	
#SRCS_BONUS = 

CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

#OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all:	${NAME}
		 
${NAME}:	${LIBFT} ${LIBMLX} ${OBJS} 
		${CC} ${FLAGS} ${OBJS} ${LIBMLX} ${LIBFT} -I include -lglfw -L "/Users/alvgomez/.brew/opt/glfw/lib/" -o ${NAME}

${LIBFT}:
		${MAKE} -C libft all

${LIBMLX}:
		${MAKE} -C MLX42 all

#${BONUS}:	${LIBFT} ${OBJS_BONUS} 
#		${CC}  ${FLAGS} ${OBJS_BONUS} ${LIBFT} -o ${BONUS}

#bonus:	${BONUS} 

clean:	
		@rm -f ${OBJS}
#		@rm -f ${OBJS_BONUS}
		@${MAKE} -C libft clean
		@${MAKE} -C MLX42 clean

fclean:	clean
		@rm -f ${NAME}
#		@rm -f ${BONUS}
		@${MAKE} -C libft fclean
		@${MAKE} -C MLX42 fclean

re: fclean all

.PHONY: all clean fclean re #bonus