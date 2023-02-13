# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:07:14 by alvgomez          #+#    #+#              #
#    Updated: 2023/02/13 18:07:26 by alvgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF = fdf.a
LIBFT = ./libft/libft.a
GNL = ./get_next_line/get_next_line.a
LIBMLX = ./MLX42/libmlx42.a

NAME = fdf

#LIBRARY ARCHIVE
#LIBFT = $(LIBFT_DIRECTORY)libft.a
#LIBFT_DIRECTORY = ./libft/
#LIBFT_HEADERS = $(LIBFT_DIRECTORY)
#INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(LIBMLX_HEADERS)

#LIBMLX = $(LIBMLX_DIRECTORY)libmlx42.a
#LIBMLX_DIRECTORY = ./MLX42
#LIBMLX_HEADERS = $(LIBMLX_DIRECTORY)

##HEADERS
#HEADERS_LIST = fdf.h
#HEADERS_DIRECTORY = ./incl/
#HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

#SOURCES
SRC_DIRECTORY = ./
SRCS = $(addprefix $(SOURCES_DIRECTORY), $(wildcard *.c))

# OBJECTS
#OBJECTS_DIRECTORY = objs/
#OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
#OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST)

CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

all:	${NAME}
		 
${NAME}:	${OBJS} ${FDF} ${LIBMLX} ${LIBFT} ${GNL}
		${CC} ${FLAGS} ${OBJS} ${FDF} ${LIBMLX} ${LIBFT} ${GNL} -I include -lglfw -L "/Users/alvgomez/.brew/opt/glfw/lib/" -o ${NAME}
#		${CC} ${FLAGS} ${OBJS} ${FDF} ${LIBMLX} ${LIBFT} ${GNL} -I include -lglfw -L "/usr/local/Cellar/glfw/3.3.8/lib" -o ${NAME}

${LIBFT}:
		${MAKE} -C libft all

${LIBMLX}:
		${MAKE} -C MLX42 all

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

${GNL}:
		${MAKE} -C get_next_line all

${FDF}:
		${CC} ${FLAGS} -c ${SRCS}
		ar rc ${FDF} ${OBJS}

clean:	
		@rm -f ${OBJS}
		@${MAKE} -C libft clean
		@${MAKE} -C MLX42 clean
		@${MAKE} -C get_next_line clean

fclean:	clean
		@rm -f ${NAME} ${FDF}
		@${MAKE} -C libft fclean
		@${MAKE} -C MLX42 fclean
		@${MAKE} -C get_next_line fclean

re: fclean all

.PHONY: all clean fclean re