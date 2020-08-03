/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:00:44 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/03 15:23:40 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_check_existence(t_map *map, char *line, int *i, int mode)
{
	if (mode == 0)
	{
		if ((line[*i] == 'R' && (map->reso[0] != -1 || map->reso[1] != -1)) ||
		(line[*i] == 'F' && map->f_path != -1) || (line[*i] == 'C'
		&& map->c_path != -1) || (ft_first(line, "NO") == 1 && map->north_t[0]
		!= '\0') || (ft_first(line, "SO") == 1 && map->south_t[0] != '\0') ||
		(ft_first(line, "WE") == 1 && map->west_t[0] != '\0') ||
		(ft_first(line, "EA") == 1 && map->east_t[0] != '\0') ||
		(ft_first(line, "S") == 1 && map->sprite_t[0] != '\0'))
			return (1);
	}
	else if (mode == 1)
	{
		if (map->reso[0] != -1 && map->reso[1] != -1 && map->f_path != -1 &&
		map->c_path != -1 && map->north_t[0] != '\0' && map->south_t[0] != '\0'
		&& map->sprite_t[0] != '\0' && map->west_t[0] != '\0'
		&& map->east_t[0] != '\0')
			return (1);
	}
	return (0);
}

int		ft_info(t_all *all, char *line, int *i)
{
	if (line[*i] == 'R' && all->map->reso[0] == -1 &&
		all->map->reso[1] == -1)
	{
		if (ft_check_resolution(line, all->map, i) == -1)
			exit(ft_error(6, all));
	}
	else if ((line[*i] == 'F' && all->map->f_path == -1) || (line[*i] == 'C'
	&& all->map->c_path == -1))
	{
		if (line[*i] == 'F')
		{
			if (ft_colors(line, &all->map->f_path, i) == -1)
				exit(ft_error(12, all));
		}
		else if (line[*i] == 'C')
			if (ft_colors(line, &all->map->c_path, i) == -1)
				exit(ft_error(12, all));
	}
	else if (ft_check_text(line, *i) == 1)
	{
		ft_text(line, all->map);
		if (ft_open_text(all->map) == -1)
			exit(ft_error(5, all));
	}
	return (1);
}

int		ft_line_error(t_all *all, char *line, int *i, int n)
{
	if ((line[*i] == '\0' && n < 0) || line == NULL)
		exit(ft_error(0, all));
	line = ft_strtrim(line, " ");
	if (ft_check_existence(all->map, line, i, 0) == 1)
		exit(ft_error(0, all));
	ft_info(all, line, i);
	ft_free((void **)&line);
	return (1);
}

t_map	*ft_parsing(t_all *all, char *title)
{
	char	*line;
	int		n;
	int		i;
	int		fd;

	i = 0;
	if (!(fd = open(title, O_RDONLY)))
		exit(ft_error(5, all));
	if (!(line = (char *)malloc(sizeof(2))))
		exit(ft_error(2, all));
	while ((n = get_next_line(fd, &line)) == 1 && (ft_check_map_char(line, i) != 1))
	{
		if (ft_check_char(line) == 0)
			exit(ft_error(15, all));
		ft_line_error(all, line, &i, n);
		ft_free((void **)&line);
		i = 0;
	}
	if ((ft_check_existence(all->map, line, &i, 1) == 1) &&
	n == 1 && (line[0] == '1' || line[0] == ' '))
	{
		if ((all->map->map = ft_map(line, n, fd, all)) == NULL)
			exit(ft_error(10, all));
	}
	else
		return (NULL);
	return (all->map);
}
