/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/13 02:36:44 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 10

# define SKYBLUE 0x7fffff
# define GREEN 0xff00
# define D_BLUE 0x555
# define D_RED 0x7f0000
# define RED 0xff0000
# define GREY 0x333333
# define ORANGE 0xFF6900
# define GREY_FLOOR 0x424242
# define YELLOW 0xFFED2D

# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define EXIT_CODE 53
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13
# define SHIFT_KEY 257
# define C_KEY 8
# define R_KEY 15
# define P_KEY 35
# define SPACE_KEY 49
# define M_KEY 46
# define L_KEY 37
# define I_KEY 34
# define O_KEY 31

//# include "../../ft_printf/ft_printf.h"
# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"
# include "../../minilibx/mlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct	s_map
{
	int			reso[2];
	void		*n_path;
	void		*s_path;
	void		*e_path;
	void		*w_path;
	void		*spr_path;
	int			f_path;
	int			c_path;
	char		**map;
	double		pos_x;
	double		pos_y;
	char		ori;
}				t_map;

typedef struct	s_image
{
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	char		*title;
	int			bpp;
	int			size_l;
	int			endian;
	char		**xpm;
	int			*data;
}				t_image;

typedef struct s_vec
{
	int			map_x;
	int			map_y;
	double		sideDist_x;
	double		sideDist_y;
	int			step_x;
	int			step_y;
	int			side;
	int			hit;
	double		dist;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		camera_x;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			keyUp;
	int			keyDown;
	int			keyLeft;
	int			keyRight;
	int			keyTurnRight;
	int			keyTurnLeft;
	double		moveSpeed;
	double		rotSpeed;
	int			killWindow;
	double		oldDir_x;
	double		oldDir_y;
	double		oldPlane_x;
	double		oldPlane_y;
	int			dir[2];
	double		plane[2];
	t_map		*map;
	t_image		*img;
}				t_vec;

typedef struct	s_all
{
	t_map		*map;
	t_image		*image;
	t_vec		*vec;
}				t_all;

/* Parsing */
t_map			*ft_parsing(t_all *all, char *title);
void			ft_jump(char *line, int *i);
int				ft_check_resolution(char *line, t_map *info, int *i);
int				ft_colors(char *line, int *color, int *i);
void			ft_text(char *line, t_map *info);
t_list			*ft_list(char *line, int n, int fd, t_map *info);
char			**ft_map(char *line, int n, int fd, t_map *info);
int				ft_check_char(char *line, int i);
int				ft_check_text(char *line, int i);
void			ft_print(t_all *all);

/* Raycasting */
t_all			*ft_raycasting(t_all *all);
t_all			*ft_def_dir_plane(t_all *all);
t_all			*ft_delta_dist(t_vec *vec, t_map *map, t_all *all);
void			ft_ray_dir(t_vec *vec, t_map *map, int i);
void			ft_hit(char **map, t_vec *vec);
void			ft_draw_ray(int i, t_all *all);
int				keyRelease(int keycode, t_all *all);
int				keyPress(int keycode, t_vec *vec);
int				keyDeal(t_all *all);
int				KillWindow(int key, t_vec *vec);
void			move_up(t_vec *vec, t_map *map);
void			move_down(t_vec *vec, t_map *map);
void			move_right(t_vec *vec, t_map *map);
void			move_left(t_vec *vec, t_map *map);
void			turn_right(t_vec *vec);
void			turn_left(t_vec *vec);
int				KillWindow(int key, t_vec *vec);

/* Utils */
int     		ft_error(int msg, t_all *all);
void    		ft_free_all(t_all **all);
int				ft_l_atoi(const char *str, int *i);

/* Init */
t_all		    *ft_init_all(t_all *all);
t_map			*ft_init_map(t_map *map);
t_vec			*ft_keys_init(t_vec *vec);

#endif
