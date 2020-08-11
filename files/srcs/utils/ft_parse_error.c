/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:43:45 by user42            #+#    #+#             */
/*   Updated: 2020/08/11 17:01:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_miss_info(char **line, t_map *map, int *fd)
{
	ft_free((void **)line);
	ft_parsing_error(map);
	close(*fd);
	return (-1);
}

int	ft_wrong_map(t_map *map, int *fd)
{
	if (map->map)
		ft_free_map(map);
	ft_simple_error("[ERROR] Wrong map.\n");
	close (*fd);
	return (-1);
}

int	ft_wrong_char(char **line, int *fd)
{
	ft_free((void **)line);
	close(*fd);
	ft_simple_error("[ERROR] Bad character.\n");
	return (-1);
}
