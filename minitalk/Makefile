# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:07:14 by alvgomez          #+#    #+#              #
#    Updated: 2022/10/11 21:41:58 by alvgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = -f libft/libft.a

SRCS = client.c \
	server.c \

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

all:	make ${NAME} 

${NAME}:
		@gcc ${FLAGS} -c ${SRCS} ${LIBFT} 

make: 
		cd libft && ${MAKE}

clean:	
		@rm -f ${OBJS}
		@cd libft && ${MAKE} clean

fclean:	clean
		@rm -f ${NAME}
		@cd libft && ${MAKE} fclean

re: fclean all

.PHONY: all clean fclean re