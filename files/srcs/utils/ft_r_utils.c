/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:37:41 by jdussert          #+#    #+#             */
/*   Updated: 2020/06/25 13:57:08 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_north(t_vec *vec)
{
	vec->dir_x = 0;
	vec->dir_y = -1;
	vec->plane_x = 0.66;
	vec->plane_y = 0;
}

void	ft_south(t_vec *vec)
{
	vec->dir_x = 0;
	vec->dir_y = 1;
	vec->plane_x = -0.66;
	vec->plane_y = 0;
}

void	ft_east(t_vec *vec)
{
	vec->dir_x = 1;
	vec->dir_y = 0;
	vec->plane_x = 0;
	vec->plane_y = 0.66;
}

void	ft_west(t_vec *vec)
{
	vec->dir_x = -1;
	vec->dir_y = 0;
	vec->plane_x = 0;
	vec->plane_y = -0.66;
}

void	ft_def_dir_plane(t_map *map, t_vec *vec)
{
	if (map->ori == 'E')
		ft_east(vec);
	else if (map->ori == 'N')
		ft_north(vec);
	else if (map->ori == 'W')
		ft_west(vec);
	else if (map->ori == 'S')
		ft_south(vec);
}
