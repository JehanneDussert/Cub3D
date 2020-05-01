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
# define Q_KEY 0
# define S_KEY 1
# define D_KEY 2
# define Z_KEY 13
# define SHIFT_KEY 257
# define C_KEY 8
# define R_KEY 15
# define P_KEY 35
# define SPACE_KEY 49
# define M_KEY 41
# define L_KEY 37
# define I_KEY 34
# define O_KEY 31
# define UP 1
# define DOWN 2

# define NORMAL 0.15
# define SLOW 0.05
# define RUN 0.25

# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"
# include "../../minilibx/mlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_player
{
	int			look;
	int			pos;
}				t_player;

typedef struct	s_text
{
	void		*ptr;
	char		*img;
	int			bpp;
	int			size_l;
	int			endian;
}				t_text;

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

typedef struct	s_vec
{
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	int			step_x;
	int			step_y;
	int			side;
	int			hit;
	double		dist;
	double		raydir_x;
	double		raydir_y;
	double		deltadist_x;
	double		deltadist_y;
	double		camera_x;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		old_dirx;
	double		old_diry;
	double		old_planex;
	double		old_planey;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_vec;

typedef struct	s_keys
{
	int			keyup;
	int			keydown;
	int			keyleft;
	int			keyright;
	int			keyturnright;
	int			keyturnleft;
	double		move_speed;
	double		rot_speed;
	int			killwindow;
}				t_keys;

typedef struct	s_all
{
	t_map		*map;
	t_image		*image;
	t_vec		*vec;
	t_text		*text;
	t_keys		*keys;
	t_player	*player;
}				t_all;

/*
** Parsing
*/
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

/*
** Raycasting
*/
t_all			*ft_raycasting(t_all *all);
void			ft_ray_dir(t_vec *vec, t_map *map, int i);
void			ft_hit(t_map *map, t_vec *vec);

/*
** Draw
*/
void			ft_draw_ray(int i, t_all *all);
int				ft_draw_side(t_vec *vec, int color);
void			ft_draw_mode(t_all *all);

/*
** Keys
*/
int				ft_keyrelease(int keycode, t_all *all);
int				ft_keypress(int keycode, t_all *all);
int				ft_keydeal(t_all *all);
int				ft_killwindow(t_all *all);

/*
** Move
*/
int				ft_move(t_all *all);
void			move_up(t_all *all);
void			move_down(t_all *all);
void			move_right(t_all *all);
void			move_left(t_all *all);
int				ft_rotation(t_all *all);
void			turn_right(t_vec *vec, t_keys *keys);
void			turn_left(t_vec *vec, t_keys *keys);
t_all			*ft_def_dir_plane(t_all *all);
t_all			*ft_delta_dist(t_vec *vec, t_map *map, t_all *all);
int				ft_look_up(t_all *all);
int				ft_look_down(t_all *all);
int				ft_player_jump(t_all *all);
int				ft_player_crawl(t_all *all);

/*
** Utils
*/
int				ft_error(int msg, t_all *all);
void			ft_free_all(t_all **all);
int				ft_l_atoi(const char *str, int *i);

/*
** Init
*/
t_all			*ft_init_all(t_all *all);
t_map			*ft_init_map(t_map *map);
t_vec			*ft_vec_init(t_vec *vec);
t_keys			*ft_keys_init(t_keys *keys);
int				ft_init_texture(t_all *all);

#endif
