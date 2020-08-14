/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:35:53 by user42            #+#    #+#             */
/*   Updated: 2020/08/14 10:24:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_pos_spr(t_map *map, t_all *all)
{
	int	i;
	int	j;
	int	nb;

	j = 0;
	nb = 0;
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

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		ft_free((void **)&map->map[i]);
		i++;
	}
	ft_free((void **)&map->map);
}

int		ft_duplicate_args(char **line)
{
	ft_simple_error("Error\nDuplicate arguments.\n");
	ft_free((void **)line);
	return (-1);
}

int		ft_correct_map(t_map *map, char *line, int n, int *fd)
{
	if ((ft_check_info_map(map) == 1 && (line[0] == '1' || line[0] == ' ')) &&
			(ft_map(map, &line, n, fd) == NULL))
		return (-1);
	return (0);
}
