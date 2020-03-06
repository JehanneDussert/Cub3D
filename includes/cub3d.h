/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/06 10:52:58 by jdussert         ###   ########.fr       */
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
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../ft_printf/ft_printf.h"
# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"

# define BUFFER_SIZE 10

typedef struct	s_ori
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
}				t_ori;

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_image
{
	void		*mlx_ptr;
	void		*img_ptr;
	int			width;
	int			height;
	char		*title;
}				t_image;

typedef struct	s_data
{
	t_image		image;
	int			bpp;
	int			*m_data;
	int			size_l;
	int			endian;
}				t_data;

typedef struct	s_player
{
	t_pos		pos;;
	/* vecteur de direction */
	int			rot;
	int			angle;
	int			speed;
	int			speed_rot;
}				t_player;

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

/* Point of view of the player : coordinate x, y and angle */
/* Angle =/= FOV mais jsais ap pq */

typedef struct s_pov
{
	t_pos		coor;
	double		angle;
	double		plane_X;
	double		plane_Y;
}				t_pov;

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
	void		*win_ptr;
	int			bpp;
	int			size_l;
	int			endian;
	int			x;
	int			y;
	int			color;
	char		**xpm;
	char		*data;
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
double			ft_def_angle(char ori);
int				ft_ray(t_pos *pos, double angle);
void			ft_loop(t_map *info, t_image *image);

#endif
