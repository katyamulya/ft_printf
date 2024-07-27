# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 17:31:46 by kdvarako          #+#    #+#              #
#    Updated: 2024/04/04 15:16:10 by kdvarako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar rcs

SRC = ft_printf.c ft_c_printf.c ft_s_printf.c ft_p_printf.c ft_d_printf.c \
	ft_u_printf.c ft_x_printf.c ft_strlen.c ft_countdellong.c

OBJ = ${SRC:.c=.o}

CC = cc

CFlAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h


all:	${NAME}

${OBJ}: ${SRC}
	${CC} ${CFlAGS} -c ${SRC}

${NAME}:	${OBJ}
	${AR} ${NAME} ${OBJ}
	ranlib ${NAME}

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re