/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehannedussert <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:44:39 by jehannedu         #+#    #+#             */
/*   Updated: 2020/06/26 17:44:43 by jehannedu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_right(t_vec *vec, t_keys *keys)
{
	vec->old_dirx = vec->dir_x;
	vec->dir_x = vec->dir_x * cos(-keys->rot_speed) - vec->dir_y
	* sin(-keys->rot_speed);
	vec->dir_y = vec->old_dirx * sin(-keys->rot_speed) + vec->dir_y
	* cos(-keys->rot_speed);
	vec->old_planex = vec->plane_x;
	vec->plane_x = vec->plane_x * cos(-keys->rot_speed) - vec->plane_y
	* sin(-keys->rot_speed);
	vec->plane_y = vec->old_planex * sin(-keys->rot_speed) + vec->plane_y
	* cos(-keys->rot_speed);
}

void	turn_left(t_vec *vec, t_keys *keys)
{
	vec->old_dirx = vec->dir_x;
	vec->dir_x = vec->dir_x * cos(keys->rot_speed) - vec->dir_y
	* sin(keys->rot_speed);
	vec->dir_y = vec->old_dirx * sin(keys->rot_speed) + vec->dir_y
	* cos(keys->rot_speed);
	vec->old_planex = vec->plane_x;
	vec->plane_x = vec->plane_x * cos(keys->rot_speed) - vec->plane_y
	* sin(keys->rot_speed);
	vec->plane_y = vec->old_planex * sin(keys->rot_speed) + vec->plane_y
	* cos(keys->rot_speed);
}

int		ft_rotation(t_all *all)
{
	if (all->keys->keyturnleft == 1)
		turn_right(all->vec, all->keys);
	if (all->keys->keyturnright == 1)
		turn_left(all->vec, all->keys);
	return (0);
}
