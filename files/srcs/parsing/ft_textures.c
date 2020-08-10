/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:20:43 by jdussert          #+#    #+#             */
/*   Updated: 2020/07/27 18:16:29 by jdussert         ###   ########.fr       */
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
	if (ft_strncmp(&line[i], "NO", 2) || ft_strncmp(&line[i], "SO", 2) ||
		ft_strncmp(&line[i], "WE", 2) || ft_strncmp(&line[i], "EA", 2) ||
		ft_strncmp(&line[i], "S", 1))
		return (1);
	return (0);
}

void	ft_text(char *line, t_map *map)
{
	int i;
	int len;

	i = 2;
	len = 0;
	while (i < (int)ft_strlen(line) && line[i] == ' ')
		i++;
	while ((i + len) <= (int)ft_strlen(line) && line[len + i] != ' ')
		len++;
	if (ft_ref_parse(line, "NO", ft_strlen(line)))
		ft_strlcpy(map->north_t, &line[i], len);
	else if (ft_ref_parse(line, "SO", ft_strlen(line)))
		ft_strlcpy(map->south_t, &line[i], len);
	else if (ft_ref_parse(line, "WE", ft_strlen(line)))
		ft_strlcpy(map->west_t, &line[i], len);
	else if (ft_ref_parse(line, "EA", ft_strlen(line)))
		ft_strlcpy(map->east_t, &line[i], len);
	else if (ft_ref_parse(line, "S", ft_strlen(line)))
		ft_strlcpy(map->sprite_t, &line[i], len);
}

void	ft_find_textures(char *line, t_map *map)
{
	ft_text(line, map);
	if (ft_open_text(map) == -1)
		ft_simple_error("[ERROR] Can't open textures files.\n");
}
