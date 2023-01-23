# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:07:14 by alvgomez          #+#    #+#              #
#    Updated: 2023/01/23 19:16:00 by alvgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF = fdf.a
LIBFT = ./libft/libft.a
GNL = ./get_next_line/get_next_line.a
LIBMLX = ./MLX42/libmlx42.a

NAME = fdf
#BONUS = 

SRCS = fdf.c \
	fdf_utils.c \

#SRCS_BONUS = 

CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

#OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all:	${NAME}
		 
${NAME}:	${OBJS} ${FDF} ${LIBMLX} ${LIBFT} ${GNL}
		${CC} ${FLAGS} ${OBJS} ${FDF} ${LIBMLX} ${LIBFT} ${GNL} -I include -lglfw -L "/Users/alvgomez/.brew/opt/glfw/lib/" -o ${NAME}

#${NAME}:	${LIBFT} ${LIBMLX} ${GNL} ${OBJS} 
#		${CC} ${FLAGS} ${OBJS} ${LIBMLX} ${LIBFT} ${GNL} -I include -lglfw -L "/Users/alvgomez/.brew/opt/glfw/lib/" -o ${NAME}

${LIBFT}:
		${MAKE} -C libft all

${LIBMLX}:
		${MAKE} -C MLX42 all

${GNL}:
		${MAKE} -C get_next_line all

${FDF}:
		${CC} ${FLAGS} -c ${SRCS}
		ar rc ${FDF} ${OBJS}

#${BONUS}:	${LIBFT} ${OBJS_BONUS} 
#		${CC}  ${FLAGS} ${OBJS_BONUS} ${LIBFT} -o ${BONUS}

#bonus:	${BONUS} 

clean:	
		@rm -f ${OBJS}
#		@rm -f ${OBJS_BONUS}
		@${MAKE} -C libft clean
		@${MAKE} -C MLX42 clean
		@${MAKE} -C get_next_line clean

fclean:	clean
		@rm -f ${NAME} ${FDF}
#		@rm -f ${BONUS}
		@${MAKE} -C libft fclean
		@${MAKE} -C MLX42 fclean
		@${MAKE} -C get_next_line fclean

re: fclean all

.PHONY: all clean fclean re #bonus