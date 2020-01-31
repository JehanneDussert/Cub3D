# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdussert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 08:57:55 by jdussert          #+#    #+#              #
#    Updated: 2020/01/30 17:31:26 by jdussert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS	= Cub3D.c main.c map.cub

NAME = cub3D

OBJS	= ${SRCS:.c=.o}

$(NAME) : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -lmlx -framework OpenGL -framework AppKit

all : ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
