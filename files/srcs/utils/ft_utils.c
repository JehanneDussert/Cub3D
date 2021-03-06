/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:27:33 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/14 16:00:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_check_text(char *line, int i)
{
	ft_jump(line, &i);
	if (ft_strncmp(&line[i], "NO", 2) || ft_strncmp(&line[i], "SO", 2) ||
		ft_strncmp(&line[i], "WE", 2) || ft_strncmp(&line[i], "EA", 2) ||
		ft_strncmp(&line[i], "S", 1))
		return (1);
	return (0);
}

int		ft_len(char *line, t_map *map)
{
	int	map_len;

	if ((map_len = ft_map_len(line, &map->ori, &map->map_l)) == -1)
	{
		map->map_l = -1;
		return (map->map_l);
	}
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
