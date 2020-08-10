/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/04 18:04:35 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_file_prbl(int msg)
{
	if (msg == 0)
		ft_putstr_fd("[ERROR] Invalid file.\n", 1);
	else if (msg == 5)
		ft_putstr_fd("[ERROR] File opening problem.\n", 1);
	else if (msg == 6)
		ft_putstr_fd("[ERROR] Wrong resolution.\n", 1);
	else if (msg == 8)
		ft_putstr_fd("[ERROR] Wrong textures.\n", 1);
	else if (msg == 10)
		ft_putstr_fd("[ERROR] Wrong map.\n", 1);
	else if (msg == 12)
		ft_putstr_fd("[ERROR] Wrong colors.\n", 1);
}

int		ft_error(int msg, t_all *all)
{
	if (msg == 0 || msg == 5 || msg == 6 || msg == 8 || msg == 10 || msg == 12)
		ft_file_prbl(msg);
	else if (msg == 1)
		ft_putstr_fd("[ERROR] Wrong argument.\n", 1);
	else if (msg == 2)
		ft_putstr_fd("[ERROR] Memory allocation.\n", 1);
	else if (msg == 3)
		ft_putstr_fd("[ERROR] Parsing error.\n", 1);
	else if (msg == 4)
		ft_putstr_fd("[ERROR] Raycasting error.\n", 1);
	else if (msg == 7)
		ft_putstr_fd("[ERROR] Mlx failed.\n", 1);
	else if (msg == 9)
		ft_putstr_fd("[ERROR] Movement error.\n", 1);
	else if (msg == 11)
		ft_putstr_fd("[ERROR] Too much sprites.\n", 1);
	else if (msg == 13)
		ft_putstr_fd("[ERROR] Textures initialisation failed.\n", 1);
	else if (msg == 14)
		ft_putstr_fd("[ERROR] Opening .bmp file failed.\n", 1);
	else if (msg == 15)
		ft_putstr_fd("[ERROR] Invalid character.\n", 1);
	ft_killwindow(all);
	return (1);
}

int		ft_simple_error(char *msg)
{
	ft_putstr_fd(msg, 1);
	return (0);
}

int		ft_parsing_error(t_map *map)
{
	if (map->reso[0] == -1 && map->reso[1] == -1 &&
		map->f_path == -1 && map->c_path == -1 &&
		map->north_t[0] == '\0' && map->south_t[0] == '\0'
		&& map->sprite_t[0] == '\0' && map->west_t[0] == '\0'
		&& map->east_t[0] == '\0')
		ft_simple_error("[ERROR] Invalid file.\n");
	if ((map->reso[0] == -1 || map->reso[1] == -1) || 
		(map->reso[0] == -1 && map->reso[1] == -1))
		ft_simple_error("[ERROR] Wrong resolution.\n");
	if (map->c_path == -1 || map->f_path == -1)
		ft_simple_error("[ERROR] Missing ceil path.\n");
	if (map->f_path == -1)
		ft_simple_error("[ERROR] Missing floor path.\n");
	if (map->north_t[0] == '\0')
		ft_simple_error("[ERROR] Missing north path.\n");
	if (map->south_t[0] == '\0')	
		ft_simple_error("[ERROR] Missing south path.\n");
	if (map->east_t[0] == '\0')
		ft_simple_error("[ERROR] Missing east path.\n");
	if (map->west_t[0] == '\0')
		ft_simple_error("[ERROR] Missing west path.\n");
	if (map->sprite_t[0] == '\0')
		ft_simple_error("[ERROR] Missing sprite path.\n");
	return (1);
}


void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		ft_free((void **)&map->map[i]);
		i++;
	}
	ft_free((void **)&map->map);
}
