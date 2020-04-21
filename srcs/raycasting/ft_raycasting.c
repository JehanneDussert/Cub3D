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

void	ft_raycasting(t_map *info, t_image *image)
{
	t_wdw	*wdw;

	if (!(image->mlx_ptr = mlx_init()))
		return ;
	if (!(image->player = (t_player *)malloc(sizeof(t_player))))
		return;
	if (!(wdw = (t_wdw *)malloc(sizeof(t_wdw))))
		return;
	ft_ray(info, image, image->player, wdw);
}