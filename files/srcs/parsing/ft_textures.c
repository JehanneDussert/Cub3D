/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:20:43 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/14 13:57:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_open_text(t_map *map)
{
	if (!(open(map->north_t, O_RDONLY)))
		return (-1);
	if (!(open(map->south_t, O_RDONLY)))
		return (-1);
	if (!(open(map->east_t, O_RDONLY)))
		return (-1);
	if (!(open(map->west_t, O_RDONLY)))
		return (-1);
	return (1);
}

int		ft_check_text(char *line, int i)
{
	ft_jump(line, &i);
	if (ft_strncmp(&line[i], "NO", 2) || ft_strncmp(&line[i], "SO", 2) ||
		ft_strncmp(&line[i], "WE", 2) || ft_strncmp(&line[i], "EA", 2) ||
		ft_strncmp(&line[i], "S", 1))
		return (1);
	return (0);
}

int		ft_text(char *line, t_map *map)
{
	int i;
	size_t len;

	i = 0;
	len = ft_strlen(line);
	ft_jump(line, &i);
	if (map->north_t[0] == '\0'
			&& ft_ref_parse(&line[i], "NO", len, &i))
	{
		ft_jump(line, &i);
		ft_strlcpy(map->north_t, &line[i], len);
	}
	else if (map->south_t[0] == '\0' &&
			ft_ref_parse(&line[i], "SO", len, &i))
	{
		ft_jump(line, &i);
		ft_strlcpy(map->south_t, &line[i], len);
	}
	else if (map->west_t[0] == '\0' &&
			ft_ref_parse(&line[i], "WE", len, &i))
	{
		ft_jump(line, &i);
		ft_strlcpy(map->west_t, &line[i], len);
	}
	else if (map->east_t[0] == '\0' &&
			ft_ref_parse(&line[i], "EA", len, &i))
	{
		ft_jump(line, &i);
		ft_strlcpy(map->east_t, &line[i], len);
	}
	else if (map->sprite_t[0] == '\0' &&
			ft_ref_parse(&line[i], "S", len, &i))
	{
		ft_jump(line, &i);
		ft_strlcpy(map->sprite_t, &line[i], len);
	}
	else if (ft_ref_parse(&line[i], "NO", len, &i) ||
			ft_ref_parse(&line[i], "SO", len, &i) ||
			ft_ref_parse(&line[i], "EA", len, &i) ||
			ft_ref_parse(&line[i], "WE", len, &i) ||
			ft_ref_parse(&line[i], "S", len, &i))
		return (-1);
	return (0);
}

int		ft_find_textures(char *line, t_map *map)
{
	if (ft_text(line, map) == -1)
		return (ft_text(line, map));
	else if (ft_open_text(map) == -1)
		return (ft_simple_error("Error\nCan't open textures files.\n"));
	return (0);
}
