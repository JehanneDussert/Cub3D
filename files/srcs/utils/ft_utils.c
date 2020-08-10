/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:27:33 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/04 12:01:25 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_len(char *line, t_map *map)
{
	int	map_len;

	map_len = ft_map_len(line, &map->ori, &map->map_l);
	if (map_len > map->map_l)
		map->map_l = map_len;
	if (map_len < 3 && line == NULL)
		return (-1);
	return (map_len);
}

void	ft_replace_space(char *str, int *i, int *j)
{
	str[*i] = '1';
	(*i)++;
	(*j)++;
}

void	ft_jump(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
}

int		ft_l_atoi(const char *str, int *i)
{
	unsigned int	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = (result * 10) + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}
void		ft_pos_spr(t_map *map, t_all *all)
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
	printf("map :%p\n", map->map);
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
