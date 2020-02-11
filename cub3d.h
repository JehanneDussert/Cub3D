/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/10 14:52:42 by jdussert         ###   ########.fr       */
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
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

typedef struct	s_ori
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
}				t_ori;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_image
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
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
	t_pos		pos;
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

typedef struct	s_all
{
	t_data		*data;
	t_pos		*pos;
	t_image		*image;
	t_ori		*ori;
	t_player	*player;
	t_txt		*txt;
}				t_all;

#endif
