/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:39:38 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/11 17:59:55 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_all	*ft_raycasting(t_all *all)
{
	if (!(all->image->mlx_ptr = mlx_init()))
		return (NULL);
	if (!(all->image->win_ptr = mlx_new_window(all->image->mlx_ptr, all->map->reso[0], all->map->reso[1], all->image->title)))
		return (NULL);
	//printf("new wdw ok\n");
	if (!(all = ft_def_dir_plane(all)))
		return (NULL);
	//printf("def dir plane ok\n");
	if (!(all->image->img_ptr = mlx_new_image(all->image->mlx_ptr, all->map->reso[0], all->map->reso[1])))
		return (NULL);
	//printf("new image ok\n");
	if (!(all->image->data = (int *)mlx_get_data_addr(all->image->img_ptr, &all->image->bpp, &all->image->size_l, &all->image->endian)))
		return (NULL);
	//printf("mlx get data addr ok\n");
	if (!(all = ft_delta_dist(all->vec, all->map, all)))
		return (NULL);
	//printf("delta dist ok\n");
	if (!(mlx_put_image_to_window(all->image->mlx_ptr, all->image->win_ptr, all->image->img_ptr, 0, 0)))
		return (NULL);
	// printf("put image ok\n");
	//if (!(mlx_loop(all->image->mlx_ptr)))
	//	return (NULL);
	//printf("loop ok\n");
	return (all);
}