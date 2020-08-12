/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehannedussert <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:23:28 by jehannedu         #+#    #+#             */
/*   Updated: 2020/08/12 14:17:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_keys	*ft_keys_init(t_keys *keys)
{
	keys->keyup = 0;
	keys->keydown = 0;
	keys->keyleft = 0;
	keys->keyright = 0;
	keys->keyturnright = 0;
	keys->keyturnleft = 0;
	keys->move_speed = NORMAL;
	keys->rot_speed = NORMAL;
	keys->killwindow = 0;
	return (keys);
}

void	ft_init_r(t_vec *vec)
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
}

t_vec	*ft_vec_init(t_vec *vec)
{
	ft_init_r(vec);
	vec->tex_num = 0;
	vec->texx = 0;
	vec->texy = 0;
	vec->wallx = 0.0;
	return (vec);
}
