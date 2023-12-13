# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 20:11:59 by ytapano           #+#    #+#              #
#    Updated: 2023/11/27 11:16:53 by ytapano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MFILES = \
	ft_hex_print.c ft_printf.c ft_printf_deps.c \
	ft_printf_extra.c ft_ptr_print.c ft_uns_print.c

OBJS = ${MFILES:.c=.o}

LIBC = ar rcs
CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}


clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all


.PHONY : all bonus clean fclean re