/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:29:28 by jehannedu         #+#    #+#             */
/*   Updated: 2020/08/04 15:08:53 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_check_map_errors(char *line, int mode)
{
	int	i;

	i = 0;
	if (mode == 0)
	{
		while (line[i])
		{
			if (line[i] != '1' && line[i] != ' ')
				return (0);
			i++;
		}
	}
	else if (mode == 1)
	{
		if ((line[0] != '1' && line[0] != ' ') ||
			line[ft_strlen(line) - 1] != '1')
			return (0);
	}
	return (1);
}

int		ft_map_len(char *line, char *ori, int *map_l)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (ft_check_map_char(line, i) != 0)
		{
			if (*ori != '1' && ft_check_map_char(line, i) == 2)
				return (-1);
			i++;
		}
		else
			return (-1);
	}
	if (i > *map_l)
		*map_l = i;
	return (i);
}

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

int		ft_check_len(char *str, char *tmp)
{
	int i;

	if (ft_strlen(str) > ft_strlen(tmp))
	{
		i = ft_strlen(tmp);
		while (str && str[i] != '\0')
		{
			if (str[i] != '1')
				return (-1);
			i++;
		}
	}
	else if (ft_strlen(str) < ft_strlen(tmp))
	{
		i = ft_strlen(str);
		while (tmp && tmp[i] != '\0')
		{
			if (tmp[i] != '1')
				return (-1);
			i++;
		}
	}
	return (1);
}

int		ft_check_map_char(char *line, int i)
{
	if (line[i] == '1' || line[i] == '2' || line[i] == '0' || line[i] == ' ')
		return (1);
	else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
	|| line[i] == 'E')
		return (2);
	else if (line[i] == ' ')
		return (3);
	return (0);
}

int		ft_check_char(char *line)
{
	if (line[0] == 'R' || line[0] == 'C' || line[0] == 'S' || line[0] == 'F'
		|| (ft_first(line, "NO") == 1) || (ft_first(line, "SO") == 1)
		|| (ft_first(line, "WE") == 1) || (ft_first(line, "EA") == 1)
		|| line[0] == '\0' || line[0] == ' ')
		return (1);
	return (0);
}
