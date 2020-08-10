/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:00:44 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/05 12:15:22 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_check_existence(t_map *map, char *line)
{
	if ((line[0] == 'R' && (map->reso[0] != -1 || map->reso[1] != -1)) ||
	(line[0] == 'F' && map->f_path != -1) || (line[0] == 'C'
	&& map->c_path != -1) || (ft_first(line, "NO") == 1 && map->north_t[0]
	!= '\0') || (ft_first(line, "SO") == 1 && map->south_t[0] != '\0') ||
	(ft_first(line, "WE") == 1 && map->west_t[0] != '\0') ||
	(ft_first(line, "EA") == 1 && map->east_t[0] != '\0') ||
	(ft_first(line, "S") == 1 && map->sprite_t[0] != '\0'))
		return (1);
	return (0);
}

int		ft_check_info_map(t_map *map)
{
	if (map->reso[0] != -1 && map->reso[1] != -1 && map->f_path != -1 &&
	map->c_path != -1 && map->north_t[0] != '\0' && map->south_t[0] != '\0'
	&& map->sprite_t[0] != '\0' && map->west_t[0] != '\0'
	&& map->east_t[0] != '\0')
		return (1);
	return (0);
}

void	ft_info(t_map *map, char **line)
{
	int	i;

	i = 0;
	ft_jump(*line, &i);
	if (*line[i] == 'R' && map->reso[0] == -1 && map->reso[1] == -1)
		ft_resolution(*line, map, &i);
	else if ((*line[i] == 'F' && map->f_path == -1) || (*line[i] == 'C'
	&& map->c_path == -1))
		ft_def_color(*line, map, &i);
	else if (ft_check_text(*line, i) == 1)
		ft_find_textures(*line, map);
	ft_free((void **)line);
}

int		ft_bad_char(char **line)
{
	ft_simple_error("[ERROR] Bad character\n");
	ft_free((void **)line);
	return (-1);
}

int		ft_parsing(t_map *map, int *fd)
{
	char	*line;
	int		n;

	while ((n = get_next_line(*fd, &line)) != 0 && ft_check_info_map(map) != 1
			&& ft_check_char(line) != 0)
		ft_info(map, &line);
	if (ft_check_map_char(line, 0) == 0)
		return (ft_bad_char(&line));
	ft_free((void **)&line);
	if (ft_check_info_map(map) == 1 && (n == get_next_line(*fd, &line)) != 0
		&& (line[0] == '1' || line[0] == ' '))
	{
		if (ft_map(map, line, n, fd) == NULL)
			return (-1);
		close(*fd);
	}
	else if (ft_check_info_map(map) != 1)
	{
		ft_parsing_error(map);
		close(*fd);
		return (-1);
	}
	return (0);
}
