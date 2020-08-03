/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:27:33 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/03 16:21:58 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_len(char *line, t_all *all)
{
	int	map_len;

	map_len = ft_map_len(line, &all->map->ori, &all->map->map_l);
	if (map_len > all->map->map_l)
		all->map->map_l = map_len;
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

int		ft_nb_spr(t_all *all, char *str, int j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '2')
		{
			if (all->map->spr > 49)
				return (ft_error(11, all));
			all->spr[all->map->spr].x = (double)i + 0.5;
			all->spr[all->map->spr].y = (double)j + 0.5;
			all->map->spr++;
		}
		i++;
	}
	if (all->map->spr > 49)
		return (-1);
	return (1);
}
