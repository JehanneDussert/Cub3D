# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 14:34:59 by jdussert          #+#    #+#              #
#    Updated: 2020/07/31 17:44:27 by jdussert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

LIBFT_PATH = libft/
LIBFT = libft.a

GNL_PATH = get_next_line/
GNL_FILES = get_next_line.c
GNL_SRCS = ${addprefix ${GNL_PATH}, ${GNL_FILES}}

MINILIBX_PATH = minilibx/
MINILIBX = libmlx.a

SRCS = files/srcs/parsing/ft_check_map.c files/srcs/parsing/ft_colors.c files/srcs/parsing/ft_resolution.c \
		files/srcs/parsing/ft_textures.c files/srcs/utils/ft_utils.c files/srcs/parsing/ft_map.c files/main.c \
		files/srcs/utils/ft_r_utils.c files/srcs/utils/ft_init2.c \
		files/srcs/raycasting/ft_raycasting.c files/srcs/raycasting/ft_draw.c files/srcs/utils/ft_map_utils.c \
		files/srcs/raycasting/ft_move.c files/srcs/raycasting/ft_rot.c \
		files/srcs/raycasting/ft_keys.c files/srcs/utils/ft_error.c files/srcs/utils/ft_init.c \
		files/srcs/raycasting/ft_look.c files/srcs/raycasting/ft_draw_textures.c files/srcs/sprites/ft_sprites.c \
		files/srcs/save/ft_save.c files/srcs/utils/ft_free_mem.c \
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
			ft_ref_parse.c ft_free.c ft_memalloc.c

SRCS_MINILIBX = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c

OBJS	= ${SRCS:.c=.o}

$(NAME)	:	${OBJS} ${LIBFT_PATH}${LIBFT} ${MINILIBX_PATH}${MINILIBX}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ${MINILIBX_PATH} -lmlx -framework OpenGL -framework AppKit -L ${LIBFT_PATH} -lft

$(LIBFT_PATH)$(LIBFT): ${LIBFT_FILES}
	make all -C ${LIBFT_PATH}

${MINILIBX_PATH}${MINILIBX} : ${MINILIBX_FILES}
	make -C ${MINILIBX_PATH}

all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}
		make -C ${LIBFT_PATH} fclean
		make -C ${MINILIBX_PATH} clean

re : fclean all

work : all clean