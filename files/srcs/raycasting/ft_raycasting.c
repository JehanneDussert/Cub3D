/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:47:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/03 11:19:54 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_ray_dir(t_vec *vec, t_map *map, int i)
{
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

void	ft_hit(t_all *all, t_vec *vec, int i)
{
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
		if (all->map->map[vec->map_y][vec->map_x] == '1')
			vec->hit = 1;
	}
	if (vec->side == 0)
		vec->dist = (vec->map_x - all->map->pos_x +
		(1 - vec->step_x) / 2) / vec->raydir_x;
	else
		vec->dist = (vec->map_y - all->map->pos_y +
		(1 - vec->step_y) / 2) / vec->raydir_y;
	all->buffer[i] = vec->dist;
}

void	ft_init_draw(t_vec *vec, int height)
{
	vec->line_height = (int)(height / vec->dist);
	vec->draw_start = -(vec->line_height) / 2 + height / 2;
	if (vec->draw_start < 0)
		vec->draw_start = 0;
	vec->draw_end = vec->line_height / 2 + height / 2;
	if (vec->draw_end >= height)
		vec->draw_end = height - 1;
}

t_all	*ft_raycasting(t_vec *vec, t_map *map, t_all *all)
{
	int i;

	i = -1;
	if (!(all->buffer = malloc(sizeof(double) * all->map->reso[0])))
		return (NULL);
	while (++i < map->reso[0])
	{
		ft_ray_dir(vec, map, i);
		vec->map_x = (int)map->pos_x;
		vec->map_y = (int)map->pos_y;
		vec->deltadist_x = fabs(1 / vec->raydir_x);
		vec->deltadist_y = fabs(1 / vec->raydir_y);
		ft_init_sidedist(vec, map);
		ft_hit(all, vec, i);
		ft_init_draw(vec, map->reso[1]);
		if (ft_draw_text(i, all) != 1)
			ft_draw_ray(i, all);
		vec->hit = 0;
	}
	return (all);
}
