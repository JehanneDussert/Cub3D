/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/07/29 18:49:56 by jdussert         ###   ########.fr       */
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
# define BLACK 0x000000

# define S_KEY 1
# define D_KEY 2
# define W_KEY 6
# define C_KEY 8
# define A_KEY 12
# define R_KEY 15
# define O_KEY 31
# define I_KEY 34
# define P_KEY 35
# define L_KEY 37
# define M_KEY 41
# define SPACE_KEY 49
# define EXIT_CODE 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define SHIFT_KEY 257

# define UP 1
# define DOWN 2

# define NORMAL 0.1
# define SLOW 0.05
# define RUN 0.15
# define NBSPR 15
# define W_H 64

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
	char		north_t[256];
	char		south_t[256];
	char		east_t[256];
	char		west_t[256];
	char		sprite_t[256];
	int			f_path;
	int			c_path;
	char		**map;
	double		pos_x;
	double		pos_y;
	char		ori;
	int			spr;
	int			map_l;
	int			len_y;
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
	char		*data;
	int			*mini_data;
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
	int			tex_num;
	int			texx;
	int			texy;
	double		wallx;
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

typedef struct	s_spr_txt
{
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			move_screen;
	int			spr_h;
	int			spr_w;
	int			screen_x;
	int			draw_sx;
	int			draw_ex;
	int			draw_sy;
	int			draw_ey;
	int			text_w;
	int			text_h;
	int			texx;
	int			texy;
	int			d;
	int			texture;
	int			i;
}				t_spr_txt;

typedef struct	s_spr
{
	double		x;
	double		y;
}				t_spr;

typedef struct	s_save
{
	int			fd;
	int			size;
	int			unused;
	int			offset_begin;
	int			header_bytes;
	short int	plane;
	short int	bpp;
}				t_save;

typedef struct	s_all
{
	t_map		*map;
	t_image		*image;
	t_vec		*vec;
	t_text		*text;
	t_keys		*keys;
	t_player	*player;
	t_save		*save;
	t_spr		spr[50];
	t_spr_txt	*spr_txt;
	double		*buffer;
	int			s;
}				t_all;

/*
** Parsing
*/
t_map			*ft_parsing(t_all *all, char *title);
void			ft_jump(char *line, int *i);
int				ft_check_resolution(char *line, t_map *info, int *i);
int				ft_colors(char *line, int *color, int *i);
void			ft_text(char *line, t_map *info);
int				ft_open_text(t_map *map);
t_list			*ft_list(char **line, int n, int fd, t_all *all);
char			**ft_map(char *line, int n, int fd, t_all *all);
int				ft_check_char(char *line, int i);
int				ft_check_text(char *line, int i);
void			ft_print(t_all *all);

/*
** Raycasting
*/
t_all			*ft_raycasting(t_vec *vec, t_map *map, t_all *all);
void			ft_ray_dir(t_vec *vec, t_map *map, int i);
void			ft_hit(t_all *all, t_vec *vec, int i);

/*
** Draw
*/
void			ft_draw_ray(int i, t_all *all);
int				ft_draw_side(t_vec *vec, int color);
void			ft_draw_mode(t_all *all);
int				ft_draw_text(int i, t_all *all);

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
int				ft_look_up(t_all *all);
int				ft_look_down(t_all *all);
int				ft_player_jump(t_all *all);
int				ft_player_crawl(t_all *all);

/*
** Utils
*/
int				ft_error(int msg, t_all *all);
int				ft_l_atoi(const char *str, int *i);
int				ft_check_len(char *str, char *tmp);
t_map			*ft_check_pos(t_map *info, char **map);
int				ft_map_len(char *line, char *ori, int *map_l);
int				ft_check_map_errors(char *line, int mode);
void			ft_replace_space(char *str, int *i, int *j);
int				ft_nb_spr(t_all *all, char *str, int j);
int				ft_len(char *line, t_all *all);

/*
** Init
*/
int				ft_init(t_all *all);
t_all			*ft_init_all(t_all *all);
t_map			*ft_init_map(t_map *map);
t_vec			*ft_vec_init(t_vec *vec);
t_keys			*ft_keys_init(t_keys *keys);
int				ft_init_texture(t_all *all, t_text *text, int width,
				int height);

/*
** Free memory
*/
t_list			*ft_error_map(char *line, char *clean_line);
t_list			*ft_end_map(char **line, char **clean_line, t_list *lst);
t_list			*ft_free_lst(char *line, char *clean_line, t_list *lst);
t_map			*ft_free_line(char *line, int *i);
void			ft_free_all(t_all **all);

/*
** Sprites
*/
void			ft_sprites(t_all *all, t_spr *spr, int nb_spr);

/*
** Save
*/
int				ft_save(t_all *all);

#endif
