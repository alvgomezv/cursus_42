# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:07:14 by alvgomez          #+#    #+#              #
#    Updated: 2022/10/04 16:56:33 by alvgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
ft_putnbr.c \
ft_putnbr.c \

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

all:	${NAME}	

${NAME}:	${OBJS}
			@gcc ${FLAGS} -c ${SRCS}
			@ar rc ${NAME} ${OBJS}

clean:	
		@rm -f ${OBJS}

fclean:	clean
		@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re