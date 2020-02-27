/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:41:31 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/27 18:56:13 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define PAS 0.001
# define GRID 64 // hauteur de chaque case (sol) et du mur
# define PLAYER_HEIGHT 32 // hauteur du perso
# define FOV 60 // champ de vision
# include "../cub3d.h"
# include <math.h>

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
	int			angle;
}				t_pov;


#endif