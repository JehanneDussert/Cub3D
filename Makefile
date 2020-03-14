# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 14:34:59 by jdussert          #+#    #+#              #
#    Updated: 2020/03/11 18:00:11 by jdussert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

LIBFT_PATH = ../libft/
LIBFT = libft.a

FT_PRINTF_PATH = ../ft_printf/
FT_PRINTF_FILES = ft_printf.c ft_flags.c ft_printf_utils.c ft_print_it.c \
			ft_find_my_args.c ft_cs_types.c ft_s_flags.c ft_p_type.c \
			ft_diux_types.c 
FT_PRINTF_SRCS = ${addprefix ${FT_PRINTF_PATH}, ${FT_PRINTF_FILES}}

GNL_PATH = ../get_next_line/
GNL_FILES = get_next_line.c
GNL_SRCS = ${addprefix ${GNL_PATH}, ${GNL_FILES}}

MINILIBX_PATH = ../minilibx/
MINILIBX = libmlx.a

SRCS = srcs/parsing/ft_check_map.c srcs/parsing/ft_colors.c srcs/parsing/ft_resolution.c \
		srcs/parsing/ft_textures.c srcs/parsing/ft_utils.c srcs/parsing/ft_map.c main.c \
		srcs/raycasting/ft_intersections.c srcs/raycasting/ft_r_utils.c \
		srcs/raycasting/ft_raycasting.c srcs/raycasting/ft_draw.c \
		${GNL_SRCS} ${FT_PRINTF_SRCS} ${MINILIBX_SRCS}

SRCS_LIBFT = ft_memset.c ft_bzero.c ft_strlen.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
			ft_strnstr.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c ft_strmapi.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c ft_itoa_base.c ft_last.c ft_int_len.c ft_first.c \
			ft_ref_parse.c

SRCS_MINILIBX = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c

OBJS	= ${SRCS:.c=.o}

$(NAME)	:	${OBJS} ${LIBFT_PATH}${LIBFT} ${MINILIBX_PATH}${MINILIBX}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ${MINILIBX_PATH} -lmlx -framework OpenGL -framework AppKit -L ${LIBFT_PATH} -lft

$(LIBFT_PATH)$(LIBFT): ${LIBFT_FILES}
	make add -C ${LIBFT_PATH}

${MINILIBX_PATH}${MINILIBX} : ${MINILIBX_FILES}
	make -C ${MINILIBX_PATH}

all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}
		make -C ${LIBFT_PATH} ${MINILIBX_PATH} fclean

re : fclean all

work : all clean