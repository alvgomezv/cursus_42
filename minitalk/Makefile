# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:07:14 by alvgomez          #+#    #+#              #
#    Updated: 2022/10/18 13:22:14 by alvgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a
CLIENT = client 
SERVER = server
CLIENT_BONUS = client_bonus 
SERVER_BONUS = server_bonus
SRCS_CLIENT = client.c 
SRCS_SERVER = server.c 
SRCS_CLIENT_BONUS = client_bonus.c 
SRCS_SERVER_BONUS = server_bonus.c 
CC = gcc

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT_BONUS = ${SRCS_CLIENT_BONUS:.c=.o}
OBJS_SERVER_BONUS = ${SRCS_SERVER_BONUS:.c=.o}

FLAGS = -Wall -Wextra -Werror

all:	${CLIENT} ${SERVER}
		 
${CLIENT}:	${LIBFT} ${OBJS_CLIENT} 
		${CC}  ${FLAGS} ${OBJS_CLIENT} ${LIBFT} -o ${CLIENT}
		
${SERVER}: ${LIBFT}	${OBJS_SERVER}
		${CC}  ${FLAGS} ${OBJS_SERVER} ${LIBFT} -o ${SERVER}

${LIBFT}:
		${MAKE} -C libft all

${CLIENT_BONUS}:	${LIBFT} ${OBJS_CLIENT_BONUS} 
		${CC}  ${FLAGS} ${OBJS_CLIENT_BONUS} ${LIBFT} -o ${CLIENT_BONUS}
		
${SERVER_BONUS}: ${LIBFT}	${OBJS_SERVER_BONUS}
		${CC}  ${FLAGS} ${OBJS_SERVER_BONUS} ${LIBFT} -o ${SERVER_BONUS}

bonus:	${CLIENT_BONUS} ${SERVER_BONUS}

clean:	
		@rm -f ${OBJS_CLIENT} ${OBJS_SERVER}
		@rm -f ${OBJS_CLIENT_BONUS} ${OBJS_SERVER_BONUS}
		@${MAKE} -C libft clean

fclean:	clean
		@rm -f ${CLIENT} ${SERVER}
		@rm -f ${CLIENT_BONUS} ${SERVER_BONUS}
		@${MAKE} -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus