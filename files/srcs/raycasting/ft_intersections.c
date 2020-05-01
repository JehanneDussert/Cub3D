/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:47:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/03 12:09:39 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_ray_dir(t_vec *vec, t_map *map, int i)
{
	/*
	** On calcule la position du ray et sa direction
	*/
	/*
	** Coordonnée x sur l'écran
	*/
	vec->camera_x = 2 * i / (double)map->reso[0] - 1;
	vec->raydir_x = vec->dir_x + vec->plane_x * vec->camera_x;
	vec->raydir_y = vec->dir_y + vec->plane_y * vec->camera_x;
}

void	ft_init_sidedist(t_vec *vec, t_map *map)
{
	if (vec->raydir_x < 0)
	{
		vec->step_x = -1;
		vec->sidedist_x = (map->pos_x - vec->map_x) * vec->deltadist_x;
	}
	else
	{
		vec->step_x = 1;
		vec->sidedist_x = (vec->map_x + 1.0 - map->pos_x) * vec->deltadist_x;
	}
	if (vec->raydir_y < 0)
	{
		vec->step_y = -1;
		vec->sidedist_y = (map->pos_y - vec->map_y) * vec->deltadist_y;
	}
	else
	{
		vec->step_y = 1;
		vec->sidedist_y = (vec->map_y + 1.0 - map->pos_y) * vec->deltadist_y;
	}
}

void	ft_hit(t_map *map, t_vec *vec)
{
	/*
	** On va incrementer x ou y d'un carre jusqu'a hit un wall
	*/
	while (vec->hit == 0)
	{
		if (vec->sidedist_x < vec->sidedist_y)
		{
			vec->sidedist_x += vec->deltadist_x;
			vec->map_x += vec->step_x;
			vec->side = 0;
		}
		else
		{
			vec->sidedist_y += vec->deltadist_y;
			vec->map_y += vec->step_y;
			vec->side = 1;
		}
	/*
	** On regarde si on a frappe un wall
	*/
		if (map->map[vec->map_y][vec->map_x] == '1')
			vec->hit = 1;
		if (vec->side == 0)
			vec->dist = (vec->map_x - map->pos_x +
			(1 - vec->step_x) / 2) / vec->raydir_x;
		else
			vec->dist = (vec->map_y - map->pos_y +
			(1 - vec->step_y) / 2) / vec->raydir_y;
	}
}

void	ft_init_draw(t_vec *vec, int height)
{
	/*
	** On calcule la hauteur de la ligne a dessiner sur l'ecran
	*/
	vec->line_height = (int)(height / vec->dist);
	/*
	** On calcule le premier et le dernier pixel a colorier dans la colonne
	*/
	vec->draw_start = -(vec->line_height) / 2 + height / 2;
	if (vec->draw_start < 0)
		vec->draw_start = 0;
	vec->draw_end = vec->line_height / 2 + height / 2;
	if (vec->draw_end >= height)
		vec->draw_end = height - 1;
}

t_all	*ft_delta_dist(t_vec *vec, t_map *map, t_all *all)
{
	int i;

	i = -1;
	while (++i < map->reso[0])
	{
		/*
		** On calcule la position du ray et la direction
		*/
		ft_ray_dir(vec, map, i);
		vec->map_x = (int)map->pos_x;
		vec->map_y = (int)map->pos_y;
		/*
		** Distance pour aller d'un cote x a un autre et d'un cote y a un autre
		*/
		vec->deltadist_x = fabs(1 / vec->raydir_x);
		vec->deltadist_y = fabs(1 / vec->raydir_y);
		ft_init_sidedist(vec, map);
		/*
		** DDA : on va avancer dans les x / y jusqu'a frapper un mur
		*/
		ft_hit(map, vec);
		/*
		** On va calculer la longueur du rayon-mur afin de calculer
		** la taille du mur a dessiner
		*/
		ft_init_draw(vec, map->reso[1]);
		/*
		** if (side == 1)
		**		color = color / 2;
		*/
		ft_draw_ray(i, all);
		vec->hit = 0;
	}
	return (all);
}
