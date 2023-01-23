# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:07:14 by alvgomez          #+#    #+#              #
#    Updated: 2023/01/23 17:27:27 by alvgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRCS = get_next_line.c \
	get_next_line_utils.c
	
OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

all:	${NAME}	

${NAME}:	${OBJS}
			@gcc ${FLAGS} -c ${SRCS}
			@ar rc ${NAME} ${OBJS}

clean:	
		@rm -f ${OBJS}
		@rm -f ${BONUS_OBJS}

fclean:	clean
		@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re