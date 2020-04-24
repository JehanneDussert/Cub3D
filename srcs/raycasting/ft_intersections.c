/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/10 15:310:57 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_ray_dir(t_vec *vec, t_map *map, int i)
{
	// On calcule la position du ray et sa direction
	vec->camera_x = 2 * i / (double)map->reso[0] - 1; // Coordonnee x sur l'ecran
	vec->ray_dir_x = vec->dir[0] + vec->plane[0] * vec->camera_x;
	vec->ray_dir_y = vec->dir[1] + vec->plane[1] * vec->camera_x;
}

void ft_init_sideDist(t_vec *vec, t_map *map)
{
	if (vec->ray_dir_x < 0)
	{
		vec->step_x = -1;
		vec->sideDist_x = (map->pos_x - vec->map_x) * vec->delta_dist_x;
	}
	else
	{
		vec->step_x = 1;
		vec->sideDist_x = (vec->map_x + 1.0 - map->pos_x) * vec->delta_dist_x;
	}
	if (vec->ray_dir_y < 0)
	{
		vec->step_y = -1;
		vec->sideDist_y = (map->pos_y - vec->map_y) * vec->delta_dist_y;
	}
	else
	{
		vec->step_y = 1;
		vec->sideDist_y = (vec->map_y + 1.0 - map->pos_y) * vec->delta_dist_y;
	}
}

void ft_hit(char **map, t_vec *vec)
{
	/* 
	** On va incrementer x ou y d'un carre jusqu'a hit un wall
	*/
	while (vec->hit == 0)
	{
	if (vec->sideDist_x < vec->sideDist_y)
	{
		vec->sideDist_x += vec->delta_dist_x;
		vec->map_x += vec->step_x;
		vec->side = 0;
	}
	else
	{
		vec->sideDist_y += vec->delta_dist_y;
		vec->map_y += vec->step_y;
		vec->side = 1;
	}
	/*
	** On regarde si on a frappe un wall
	*/
	if (map[vec->map_y][vec->map_x] > '0')
		vec->hit = 1;
	}
}

int ft_vec_side(t_vec *vec, t_map *map)
{
	if (vec->side == 0)
		vec->dist = (vec->map_x - map->pos_x + (1 - vec->step_x) / 2) / vec->ray_dir_x;
	else
		vec->dist = (vec->map_y - map->pos_y + (1 - vec->step_y) / 2) / vec->ray_dir_y;
	return (vec->side);
}

void ft_init_draw(t_vec *vec, int height)
{
	/*
	** On calcule la hauteur de la ligne a dessiner sur l'ecran
	*/
	vec->lineHeight = (int)(height / vec->dist);
	/*
	** On calcule le premier et le dernier pixel a colorier dans la colonne
	*/
	vec->drawStart = -(vec->lineHeight) / 2 + height / 2;
	if (vec->drawStart < 0)
		vec->drawStart = 0;
	vec->drawEnd = vec->lineHeight / 2 + height / 2;
	if (vec->drawEnd >= height)
		vec->drawEnd = height - 1;
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
		vec->hit = 0;
		/*
		** Distance pour aller d'un cote x a un autre et d'un cote y a un autre
		*/
		vec->delta_dist_x = (vec->ray_dir_y == 0) ? 0 : ((vec->ray_dir_x == 0) ? 1 : ft_abs(1 / vec->ray_dir_x));
		vec->delta_dist_y = (vec->ray_dir_x == 0) ? 0 : ((vec->ray_dir_y == 0) ? 1 : ft_abs(1 / vec->ray_dir_y));
		ft_init_sideDist(vec, map);
		/*
		** DDA : on va avancer dans les x / y jusqu'a frapper un mur
		*/
		ft_hit(map->map, vec);
		/*
		** On va calculer la longueur du rayon-mur afin de calculer la taille du mur a dessiner
		*/
		vec->side = ft_vec_side(vec, map);
		ft_init_draw(vec, map->reso[1]);
		/*
		** if (side == 1)
		**		color = color / 2;
		*/
		ft_draw_ray(i, all);
	}
	return (all);
}
