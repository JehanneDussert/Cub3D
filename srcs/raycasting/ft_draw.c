/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:44:42 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/11 16:00:30 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw(t_image *image, t_map *info, t_wdw *wdw)
{
	int	i;

	i = 0;
	image->win_ptr = mlx_new_window(image->mlx_ptr, info->reso[0], info->reso[1], image->title);
	image->player->angle = ft_def_angle(info->ori, image->player);
	image->img_ptr = mlx_new_image(image->mlx_ptr, info->reso[0], info->reso[1]);
	wdw->data = (int *)mlx_get_data_addr(image->img_ptr, &wdw->bpp, &wdw->size_l, &wdw->endian);
	while (i++ < info->reso[0])
		wdw->data[500 * (i + 500) + 500] = 0xAC9EF0;
	mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->img_ptr, wdw->x, wdw->y);
	printf("this is my angle :%f\n", image->player->angle);
	ft_printf("This is my dir[0]:%d\nAnd my dir[1]:%d\n", image->player->dir[0], image->player->dir[1]);
	mlx_loop(image->mlx_ptr);
}
