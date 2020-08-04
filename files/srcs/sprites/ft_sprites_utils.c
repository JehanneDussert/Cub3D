/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:25:35 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/04 16:28:04 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map	*ft_check_pos(t_map *info, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_check_map_char(map[i], j) == 2)
			{
				info->pos_x = (double)j + 0.5;
				info->pos_y = (double)i + 0.5;
				return (info);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
