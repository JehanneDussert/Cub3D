/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/11 11:41:39 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* # define SPEED 1
*** # define ANGLE 1
*** # define ROT_SP 1
*** # define HAUTEUR_REGARD 1
*** # define HAUTEUR_MUR 1
*** # define DISTANCE_MUR 1*/
# define PAS 0.001
# define GRID 64 // hauteur de chaque case (sol) et du mur
# define PLAYER_HEIGHT 32 // hauteur du perso
# define FOV 60 // champ de vision
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
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../ft_printf/ft_printf.h"
# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"

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
	double		camera_y;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
}				t_vec;

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct s_pov
{
	t_pos		coor;
	double		angle;
	double		plane_x;
	double		plane_y;
}				t_pov;

typedef struct	s_ori
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
}				t_ori;

typedef struct	s_player
{
	t_pos		pos;
	/* vecteur de direction */
	int			rot;
	double		angle;
	int			dir[2];
	int			speed;
	int			speed_rot;
}				t_player;

typedef struct	s_image
{
	void		*mlx_ptr;
	void		*img_ptr;
	int			width;
	int			height;
	char		*title;
	t_pov		*pov;
	t_player	*player;
	void		*win_ptr;
}				t_image;

typedef struct	s_data
{
	t_image		image;
	int			bpp;
	int			*m_data;
	int			size_l;
	int			endian;
}				t_data;

typedef struct	s_txt
{
	int			res[2];
	int			n_txt;
	int			s_txt;
	int			we_txt;
	int			ea_txt;
	int			sp_txt;
	int			fl[3];
	int			cl[3];
	char		**map;
}				t_txt;

/* Intervalles des walls, du floor et ceiling a colorier */

typedef struct 	s_inter
{
	int			wall[2];
	int			floor[2];
	int			ceiling[2];
}				t_inter;

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
	t_pos		*pos;
	char		ori;
	int			map_len;
}				t_map;

typedef struct	s_wdw
{
	t_image		*image;
	int			bpp;
	int			size_l;
	int			endian;
	int			x;
	int			y;
	int			color;
	char		**xpm;
	int			*data;
}				t_wdw;

typedef struct	s_all
{
	t_data		*data;
	t_pos		*pos;
	t_image		*image;
	t_ori		*ori;
	t_pov		*pov;
	t_player	*player;
	t_txt		*txt;
	t_inter		*inter;
	t_map		*map;
}				t_all;

t_map			*ft_check(char *map, char *title);
int				ft_error(char **map, char **line, t_map **info, char *message);
void			ft_jump(char *line, int *i);
t_map			*ft_init(void);
void			ft_check_resolution(char *line, t_map *info, char *map, int *i);
int				ft_colors(char *line, int *color, int *i);
void			ft_text(char *line, t_map *info);
t_list			*ft_list(char *line, int n, int fd, t_map *info);
char			**ft_map(char *line, int n, int fd, t_map *info);
int				ft_check_char(char *line, int i);
int				ft_check_text(char *line, int i);
void			ft_print(t_map *info);
void			ft_raycasting(t_map *info);
int				ft_degre_to_rad(int deg);
int				ft_rounded_down(float f);
int				ft_sqrt(int nb);
int				ft_tan(int angle);
double			ft_def_angle(char ori, t_player *player);
void			ft_ray_dir(t_map *info, t_vec *vec, t_player *player);
void			ft_loop(t_map *info, t_image *image);
int				ft_abs(double nb);
int				ft_hit(char **map, t_vec *vec);

#endif
