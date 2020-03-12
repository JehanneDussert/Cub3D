/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:37:41 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/12 12:42:42 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double ft_north(t_player *player)
{
	player->dir[0] = 0;
	player->dir[1] = -1;
	player->plane[0] = 0.66;
	player->plane[1] = 0;
	return (90);
}

double ft_south(t_player *player)
{
	player->dir[0] = 0;
	player->dir[1] = 1;
	player->plane[0] = -0.66;
	player->plane[1] = 0;
	return (270);
}

double ft_east(t_player *player)
{
	player->dir[0] = 1;
	player->dir[1] = 0;
	player->plane[0] = 0;
	player->plane[1] = 0.66;
	return (0);
}

double ft_west(t_player *player)
{
	player->dir[0] = -1;
	player->dir[1] = 0;
	player->plane[0] = 0;
	player->plane[1] = -0.66;
	return (180);
}

double ft_def_angle(char ori, t_player *player)
{
	if (ori == 'E')
		return (ft_east(player));
	else if (ori == 'N')
		return (ft_north(player));
	else if (ori == 'W')
		return (ft_west(player));
	else if (ori == 'S')
		return (ft_south(player));
	return (-1);
}
