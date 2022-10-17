# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:07:14 by alvgomez          #+#    #+#              #
#    Updated: 2022/10/17 17:57:23 by alvgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a
NAME_1 = client 
NAME_2 = server
SRCS_1 = client.c 
SRCS_2 = server.c 
CC = gcc

OBJS_1 = ${SRCS_1:.c=.o}
OBJS_2 = ${SRCS_2:.c=.o}

FLAGS = -Wall -Wextra -Werror

all:	make ${NAME_1} ${NAME_2}
		 
${NAME_1}:	${OBJS_1} ${LIBFT}
		${CC} ${FLAGS} ${OBJS_1} ${LIBFT} -o ${NAME_1}
		
${NAME_2}:	${OBJS_2} ${LIBFT}
		${CC} ${FLAGS} ${OBJS_2} ${LIBFT} -o ${NAME_2}

make: 
		cd libft && make

clean:	
		@rm -f ${OBJS_1} ${OBJS_2}
		@cd libft && make clean

fclean:	clean
		@rm -f ${NAME_1} ${NAME_2}
		@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re make