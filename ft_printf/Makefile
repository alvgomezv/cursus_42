# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:07:14 by alvgomez          #+#    #+#              #
#    Updated: 2022/10/05 18:46:12 by alvgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
ft_putnbr.c \
ft_putnbr.c \
ft_putchar.c \
ft_putstr.c \
ft_hexadecimal.c \
ft_unsigned_putnbr.c \
ft_void_hexadecimal.c \

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