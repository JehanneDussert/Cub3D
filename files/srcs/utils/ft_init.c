/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/06/25 16:41:39 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			ft_init_texture_data(t_text *text)
{
	if ((text[0].img = mlx_get_data_addr(text[0].ptr, &text[0].bpp,
		&text[0].size_l, &text[0].endian)) == NULL)
		return (-1);
	if ((text[1].img = mlx_get_data_addr(text[1].ptr, &text[1].bpp,
		&text[1].size_l, &text[1].endian)) == NULL)
		return (-1);
	if ((text[2].img = mlx_get_data_addr(text[2].ptr, &text[2].bpp,
		&text[2].size_l, &text[2].endian)) == NULL)
		return (-1);
	if ((text[3].img = mlx_get_data_addr(text[3].ptr, &text[3].bpp,
		&text[3].size_l, &text[3].endian)) == NULL)
		return (-1);
	if ((text[4].img = mlx_get_data_addr(text[4].ptr, &text[4].bpp,
		&text[4].size_l, &text[4].endian)) == NULL)
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
	text[5].ptr = NULL;
	if (ft_init_texture_data(text) != 0)
		return (ft_error(8, all));
	all->text = text;
	return (0);
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
	map->map = NULL;
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
	all->image->mlx_ptr = NULL;
	all->image->win_ptr = NULL;
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
