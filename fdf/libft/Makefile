# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 15:07:14 by alvgomez          #+#    #+#              #
#    Updated: 2023/02/06 18:04:17 by alvgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memset.c \
ft_memchr.c \
ft_bzero.c \
ft_strlen.c \
ft_atoi.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_toupper.c \
ft_tolower.c \
ft_calloc.c \
ft_strdup.c \
ft_strjoin.c \
ft_memmove.c \
ft_memcmp.c \
ft_strlcpy.c \
ft_strchr.c \
ft_strncmp.c \
ft_substr.c \
ft_strtrim.c \
ft_memcpy.c \
ft_strrchr.c \
ft_strnstr.c \
ft_strlcat.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_printf.c \
ft_hexadecimal_printf.c \
ft_putchar_printf.c \
ft_putnbr_printf.c \
ft_putstr_printf.c \
ft_unsigned_putnbr_printf.c \
ft_void_hexadecimal_printf.c \

BONUS_SRCS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all:	${NAME}	

${NAME}:	${OBJS}
			@gcc ${FLAGS} -c ${SRCS}
			@ar rc ${NAME} ${OBJS}

bonus:		${NAME}	
			@gcc $(FLAGS) -c $(BONUS_SRCS)
			@ar rc $(NAME) $(BONUS_OBJS)

clean:	
		@rm -f ${OBJS}
		@rm -f ${BONUS_OBJS}

fclean:	clean
		@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re