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
	vec->rayDirX = vec->dirX + vec->planeX * vec->camera_x;
	vec->rayDirY = vec->dirY + vec->planeY * vec->camera_x;
}

void ft_init_sideDist(t_vec *vec, t_map *map)
{
	if (vec->rayDirX < 0)
	{
		vec->step_x = -1;
		vec->sideDistX = (map->pos_x - vec->map_x) * vec->deltaDistX;
	}
	else
	{
		vec->step_x = 1;
		vec->sideDistX = (vec->map_x + 1.0 - map->pos_x) * vec->deltaDistX;
	}
	if (vec->rayDirY < 0)
	{
		vec->step_y = -1;
		vec->sideDistY = (map->pos_y - vec->map_y) * vec->deltaDistY;
	}
	else
	{
		vec->step_y = 1;
		vec->sideDistY = (vec->map_y + 1.0 - map->pos_y) * vec->deltaDistY;
	}
}

void ft_hit(t_map *map, t_vec *vec)
{
	/* 
	** On va incrementer x ou y d'un carre jusqu'a hit un wall
	*/
	while (vec->hit == 0)
	{
		if (vec->sideDistX < vec->sideDistY)
		{
			vec->sideDistX += vec->deltaDistX;
			vec->map_x += vec->step_x;
			vec->side = 0;
		}
		else
		{
			vec->sideDistY += vec->deltaDistY;
			vec->map_y += vec->step_y;
			vec->side = 1;
		}
	/*
	** On regarde si on a frappe un wall
	*/
		if (map->map[vec->map_y][vec->map_x] == '1')
			vec->hit = 1;
		if (vec->side == 0)
			vec->dist = (vec->map_x - map->pos_x + (1 - vec->step_x) / 2) / vec->rayDirX;
		else
			vec->dist = (vec->map_y - map->pos_y + (1 - vec->step_y) / 2) / vec->rayDirY;
	}
}
/*
int ft_vec_side(t_vec *vec, t_map *map)
{
	printf("vec side :%d\n", vec->side);
	printf("map x :%d\n", vec->map_x);
	printf("map y :%d\n", vec->map_y);
	printf("step x :%d\n", vec->step_x);
	printf("step y :%d\n", vec->step_y);
	printf("ray dir x :%f\n", vec->rayDirX);
	printf("ray dir y :%f\n", vec->rayDirY);
	printf("dir x :%f\n", vec->dirX);
	printf("dir y :%f\n", vec->dirY);
	printf("plane x :%f\n", vec->planeX);
	printf("plane y :%f\n", vec->planeY);
	if (vec->side == 0)
		vec->dist = (vec->map_x - map->pos_x + (1 - vec->step_x) / 2) / vec->rayDirX;
	else
		vec->dist = (vec->map_y - map->pos_y + (1 - vec->step_y) / 2) / vec->rayDirY;
	return (vec->side);
}*/

void ft_init_draw(t_vec *vec, int height)
{
	/*
	** On calcule la hauteur de la ligne a dessiner sur l'ecran
	*/
	vec->lineHeight = (int)(height / vec->dist);
	// à quoi ça sert ça ??
	vec->lineHeight *= 1;
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
		/*
		** Distance pour aller d'un cote x a un autre et d'un cote y a un autre
		*/
		vec->deltaDistX = fabs(1 / vec->rayDirX);
		vec->deltaDistY = fabs(1 / vec->rayDirY);
		ft_init_sideDist(vec, map);
		/*
		** DDA : on va avancer dans les x / y jusqu'a frapper un mur
		*/
		ft_hit(map, vec);
		/*
		** On va calculer la longueur du rayon-mur afin de calculer la taille du mur a dessiner
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
