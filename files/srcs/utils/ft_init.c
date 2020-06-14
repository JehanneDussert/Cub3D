/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/13 02:36:44 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			ft_init_texture_data(t_text *text)
{
	if((text[0].img = mlx_get_data_addr(text[0].ptr, &text[0].bpp, &text[0].size_l, &text[0].endian)) == NULL)
		return (-1);
	if ((text[1].img = mlx_get_data_addr(text[1].ptr, &text[1].bpp, &text[1].size_l, &text[1].endian)) == NULL)
		return (-1);
	if ((text[2].img = mlx_get_data_addr(text[2].ptr, &text[2].bpp, &text[2].size_l, &text[2].endian)) == NULL)
		return (-1);
	if ((text[3].img = mlx_get_data_addr(text[3].ptr, &text[3].bpp, &text[3].size_l, &text[3].endian)) == NULL)
		return (-1);
	if ((text[4].img = mlx_get_data_addr(text[4].ptr, &text[4].bpp, &text[4].size_l, &text[4].endian)) == NULL)
		return (-1);
	return (0);
}

int			ft_init_texture(t_all *all, t_text *text, int width, int height)
{
	if ((text[0].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->n_path, &width, &height)) == NULL)
		return (ft_error(8, all));
	if ((text[1].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->s_path, &width, &height)) == NULL)
		return (ft_error(8, all));
	if ((text[2].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->w_path, &width, &height)) == NULL)
		return (ft_error(8, all));
	if ((text[3].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->e_path, &width, &height)) == NULL)
		return (ft_error(8, all));
	if ((text[4].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->spr_path, &width, &height)) == NULL)
		return (ft_error(8, all));
	//text[5].ptr = NULL;
	if (ft_init_texture_data(text) != 0)
		return (ft_error(8, all));
	all->text = text;
	return (0);
}

t_keys		*ft_keys_init(t_keys *keys)
{
	keys->keyup = 0;
	keys->keydown = 0;
	keys->keyleft = 0;
	keys->keyright = 0;
	keys->keyturnright = 0;
	keys->keyturnleft = 0;
	keys->move_speed = 0.15;
	keys->rot_speed = 0.15;
	keys->killwindow = 0;
	return (keys);
}

t_vec		*ft_vec_init(t_vec *vec)
{
	vec->map_x = 0;
	vec->map_y = 0;
	vec->sidedist_x = 0.0;
	vec->sidedist_y = 0.0;
	vec->step_x = 0;
	vec->step_y = 0;
	vec->side = 0;
	vec->hit = 0;
	vec->dist = 0.0;
	vec->raydir_x = 0.0;
	vec->raydir_y = 0.0;
	vec->deltadist_x = 0.0;
	vec->deltadist_y = 0.0;
	vec->camera_x = 0.0;
	vec->line_height = 0;
	vec->draw_start = 0;
	vec->draw_end = 0;
	vec->old_dirx = 0.0;
	vec->old_diry = 0.0;
	vec->old_planex = 0.0;
	vec->old_planey = 0.0;
	vec->dir_x = -1;
	vec->dir_y = 0;
	vec->plane_x = 0.66;
	vec->plane_y = 0;
	vec->texNum = 0;
	vec->texX = 0;
	vec->texY = 0;
	vec->wallX = 0.0;
	vec->texWidth = 64;
	vec->texHeight = 64;
	return (vec);
}

t_map		*ft_init_map(t_map *map)
{
	map->reso[0] = -1;
	map->reso[1] = -1;
	map->n_path[0] = '\0';
	map->s_path[0] = '\0';
	map->w_path[0] = '\0';
	map->e_path[0] = '\0';
	map->spr_path[0] = '\0';
	map->f_path = -1;
	map->c_path = -1;
	map->pos_x = 0;
	map->pos_y = 0;
	map->ori = '1';
	map->spr = 0;
	map->map_l = 0;
	return (map);
}

t_player	*ft_player_init(t_player *player)
{
	player->look = 0;
	player->pos = 0;
	return (player);
}

t_all		*ft_init_all(t_all *all)
{
	if (!(all->image = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	if (!(all->map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(all->vec = (t_vec *)malloc(sizeof(t_vec))))
		return (NULL);
	if (!(all->keys = (t_keys *)malloc(sizeof(t_keys))))
		return (NULL);
	if (!(all->player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	if (!(ft_vec_init(all->vec)))
		return (NULL);
	if (!(ft_init_map(all->map)))
		return (NULL);
	if (!(ft_keys_init(all->keys)))
		return (NULL);
	all->player = ft_player_init(all->player);
	return (all);
}
