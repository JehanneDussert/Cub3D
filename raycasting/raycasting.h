/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:41:31 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/26 18:26:31 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define PAS 0.001
# define GRID 64
# define FOV 60 // champ de vision
# include "../cub3d.h"

typedef struct 	s_inter
{
	int			wall[2];
	int			floor[2];
	int			ceiling[2];
}				t_inter;

#endif