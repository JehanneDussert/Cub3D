/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:20:43 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/14 16:02:13 by user42           ###   ########.fr       */
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

void	ft_cp_txt(char *path, char *line, int len, int *i)
{
	ft_jump(line, i);
	ft_strlcpy(path, &line[*i], (len - *i + 1));
}

int		ft_check_new_txt(char *line, int len, int i)
{
	if (ft_ref_parse(&line[i], "NO", len, &i) ||
			ft_ref_parse(&line[i], "SO", len, &i) ||
			ft_ref_parse(&line[i], "EA", len, &i) ||
			ft_ref_parse(&line[i], "WE", len, &i) ||
			ft_ref_parse(&line[i], "S", len, &i))
		return (-1);
	return (0);
}

int		ft_text(char *line, t_map *map, int i)
{
	size_t	len;

	len = ft_strlen(line);
	while (len > 0 && line[len - 1] == ' ')
		len--;
	ft_jump(line, &i);
	if (map->north_t[0] == '\0'
			&& ft_ref_parse(&line[i], "NO", len, &i))
		ft_cp_txt(map->north_t, line, len, &i);
	else if (map->south_t[0] == '\0' &&
			ft_ref_parse(&line[i], "SO", len, &i))
		ft_cp_txt(map->south_t, line, len, &i);
	else if (map->west_t[0] == '\0' &&
			ft_ref_parse(&line[i], "WE", len, &i))
		ft_cp_txt(map->west_t, line, len, &i);
	else if (map->east_t[0] == '\0' &&
			ft_ref_parse(&line[i], "EA", len, &i))
		ft_cp_txt(map->east_t, line, len, &i);
	else if (map->sprite_t[0] == '\0' &&
			ft_ref_parse(&line[i], "S", len, &i))
		ft_cp_txt(map->sprite_t, line, len, &i);
	else if (ft_check_new_txt(line, len, i) != 0)
		return (-1);
	return (0);
}

int		ft_find_textures(char *line, t_map *map)
{
	if (ft_text(line, map, 0) == -1)
		return (ft_text(line, map, 0));
	else if (ft_open_text(map) == -1)
		return (ft_simple_error("Error\nCan't open textures files.\n"));
	return (0);
}
