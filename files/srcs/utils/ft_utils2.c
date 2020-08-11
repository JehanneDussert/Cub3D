/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:35:53 by user42            #+#    #+#             */
/*   Updated: 2020/08/11 15:38:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_pos_spr(t_map *map, t_all *all)
{
	int	i;
	int	j;
	int	nb;

	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] == '2')
			{
				all->spr[nb].x = (double)i + 0.5;
				all->spr[nb].y = (double)j + 0.5;
				nb++;
			}
			i++;
		}
		j++;
	}
}

int		ft_nb_spr(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] == '2')
				map->spr++;
			i++;
		}
		j++;
	}
	if (map->spr > 49)
		return (-1);
	return (1);
}
