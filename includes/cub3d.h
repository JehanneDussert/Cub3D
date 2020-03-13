/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/13 01:43:38 by jdussert         ###   ########.fr       */
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
	int			map_len;
}				t_map;

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
}				t_vec;

typedef struct s_pov
{
	t_map		*info;
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
	t_map		*info;
	/* vecteur de direction */
	int			rot;
	double		angle;
	int			dir[2];
	double		plane[2];
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
	t_map		*info;
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
double			ft_def_angle(char ori, t_player *player);
void			ft_ray_dir(t_map *info, t_vec *vec, t_player *player, int i);
void			ft_raycasting(t_map *info, t_image *image);
void			ft_ray(t_map *info, t_image *image, t_player *player, t_wdw *wdw);
void			ft_hit(char **map, t_vec *vec);
void			ft_draw_ray(int i, int start, int end, t_map *info, t_wdw *wdw, t_vec *vec);

#endif
