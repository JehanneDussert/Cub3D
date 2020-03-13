/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:37:41 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/13 02:35:30 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_north(t_player *player)
{
	player->dir[0] = 0;
	player->dir[1] = -1;
	player->plane[0] = 0.66;
	player->plane[1] = 0;
}

void ft_south(t_player *player)
{
	player->dir[0] = 0;
	player->dir[1] = 1;
	player->plane[0] = -0.66;
	player->plane[1] = 0;
}

void ft_east(t_player *player)
{
	player->dir[0] = 1;
	player->dir[1] = 0;
	player->plane[0] = 0;
	player->plane[1] = 0.66;
}

void ft_west(t_player *player)
{
	player->dir[0] = -1;
	player->dir[1] = 0;
	player->plane[0] = 0;
	player->plane[1] = -0.66;
}

void ft_def_dir_plane(char ori, t_player *player)
{
	if (ori == 'E')
		ft_east(player);
	else if (ori == 'N')
		ft_north(player);
	else if (ori == 'W')
		ft_west(player);
	else if (ori == 'S')
		ft_south(player);
}
