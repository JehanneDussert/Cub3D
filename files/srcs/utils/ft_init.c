/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/04 15:40:26 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_map(t_map *map)
{
	map->reso[0] = -1;
	map->reso[1] = -1;
	map->north_t[0] = '\0';
	map->south_t[0] = '\0';
	map->west_t[0] = '\0';
	map->east_t[0] = '\0';
	map->sprite_t[0] = '\0';
	map->f_path = -1;
	map->c_path = -1;
	map->pos_x = 0;
	map->pos_y = 0;
	map->ori = '1';
	map->spr = 0;
	map->map_l = 0;
	map->len_y = 0;
	map->map = NULL;
	map = NULL;
}

void	ft_player(t_player *p)
{
	p->p_x = 0;
	p->p_y = 0;
	p->dir_x = 0;
	p->dir_y = 0;
	p->x = 0;
	p->y = 0;
}

void	ft_init(t_all *all, t_vec *vec, t_keys *keys, t_s_txt *s_txt)
{
	all->vec = vec;
	all->keys = keys;
	all->s_txt = s_txt;
}

void	ft_init_all(t_all *all, t_player *p, t_map *map, t_image *img)
{
	all->s = 0;
	all->map = map;
	all->image = img;
	all->player = p;
}

void	ft_check_screen_size(t_image *img, t_map *map)
{
	mlx_get_screen_size(img->mlx_ptr, &img->x, &img->y);
	if (map->reso[0] > img->x)
		map->reso[0] = img->x;
	if (map->reso[1] > img->y)
		map->reso[1] = img->y;
}
