# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 08:57:55 by jdussert          #+#    #+#              #
#    Updated: 2020/02/13 14:33:20 by jdussert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = parsing/ft_check_map.c parsing/ft_colors.c parsing/ft_resolution.c /
		parsing/ft_textures.c parsing/ft_utils.c

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
