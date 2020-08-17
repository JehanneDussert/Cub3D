/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:00:44 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/17 11:29:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_check_existence(t_map *map, char *line)
{
	if ((line[0] == 'R' && (map->reso[0] != -1 || map->reso[1] != -1)) ||
	(line[0] == 'F' && map->f_path != -1) || (line[0] == 'C'
	&& map->c_path != -1) || (ft_first(line, "NO", 0) == 1 && map->north_t[0]
	!= '\0') || (ft_first(line, "SO", 0) == 1 && map->south_t[0] != '\0') ||
	(ft_first(line, "WE", 0) == 1 && map->west_t[0] != '\0') ||
	(ft_first(line, "EA", 0) == 1 && map->east_t[0] != '\0') ||
	(ft_first(line, "S", 0) == 1 && map->sprite_t[0] != '\0'))
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

int		ft_info(t_map *map, char *line)
{
	int	i;

	i = 0;
	ft_jump(line, &i);
	if (ft_check_char(line, i) == 0)
		return (-1);
	if (line[i] == 'R' && map->reso[0] == -1 && map->reso[1] == -1)
		ft_resolution(line, map, &i);
	else if (line[i] == 'R')
		return (ft_simple_error("Error\nDuplicate resolution.\n"));
	if ((line[i] == 'F' && map->f_path == -1) || (line[i] == 'C'
				&& map->c_path == -1))
		ft_def_color(line, map, &i);
	else if ((line[i] == 'F' && map->f_path != -1) || (line[i] == 'C'
			&& map->c_path != -1))
	{
		if (line[i] == 'F')
			return (ft_simple_error("Error\nDuplicate floor color.\n"));
		else
			return (ft_simple_error("Error\nDuplicate ceiling color.\n"));
	}
	else if (line[i] != 'R' && ft_check_text(line, i) == 1 &&
			ft_find_textures(line, map) == -1)
		return (ft_simple_error("Error\nDuplicate texture.\n"));
	return (0);
}

int		ft_parsing(t_map *map, int *fd)
{
	char	*line;
	int		n;

	while ((n = get_next_line(*fd, &line)) != 0
			&& ft_check_info_map(map) != 1)
	{
		if (ft_info(map, line) == -1)
			return (ft_wrong_char(&line, fd));
		ft_free((void **)&line);
	}
	while (line[0] != ' ' && line[0] != '1' && n != 0)
	{
		if (ft_check_info_map(map) == 1 && ft_check_char(line, 0) && line[0])
			return (ft_duplicate_args(&line));
		if (ft_check_char(line, 0) == 0)
			return (ft_wrong_char(&line, fd));
		ft_free((void **)&line);
		n = get_next_line(*fd, &line);
	}
	if (ft_correct_map(map, line, n, fd) != 0)
		return (ft_wrong_map(map, fd));
	else if (ft_check_info_map(map) != 1)
		return (ft_miss_info(&line, map, fd));
	return (0);
}
