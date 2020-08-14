/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/14 09:30:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_file_prbl(int msg)
{
	if (msg == 0)
		ft_putstr_fd("Error\nInvalid file.\n", 1);
	else if (msg == 5)
		ft_putstr_fd("Error\nFile opening problem.\n", 1);
	else if (msg == 8)
		ft_putstr_fd("Error\nWrong textures.\n", 1);
	else if (msg == 10)
		ft_putstr_fd("Error\nWrong map.\n", 1);
	else if (msg == 12)
		ft_putstr_fd("Error\nWrong colors.\n", 1);
}

int		ft_error(int msg, t_all *all)
{
	if (msg == 0 || msg == 5 || msg == 8 || msg == 10 || msg == 12)
		ft_file_prbl(msg);
	else if (msg == 1)
		ft_putstr_fd("Error\nWrong argument.\n", 1);
	else if (msg == 2)
		ft_putstr_fd("Error\nMemory allocation.\n", 1);
	else if (msg == 3)
		ft_putstr_fd("Error\nParsing error.\n", 1);
	else if (msg == 4)
		ft_putstr_fd("Error\nRaycasting error.\n", 1);
	else if (msg == 7)
		ft_putstr_fd("Error\nMlx failed.\n", 1);
	else if (msg == 9)
		ft_putstr_fd("Error\nMovement error.\n", 1);
	else if (msg == 11)
		ft_putstr_fd("Error\nToo much sprites.\n", 1);
	else if (msg == 13)
		ft_putstr_fd("Error\nTextures initialisation failed.\n", 1);
	else if (msg == 14)
		ft_putstr_fd("Error\nOpening .bmp file failed.\n", 1);
	else if (msg == 15)
		ft_putstr_fd("Error\nInvalid character.\n", 1);
	ft_killwindow(all);
	return (1);
}

int		ft_simple_error(char *msg)
{
	ft_putstr_fd(msg, 1);
	return (-1);
}

int		ft_invalid_file(t_map *map)
{
	if (map->reso[0] == -1 && map->reso[1] == -1 &&
		map->f_path == -1 && map->c_path == -1 &&
		map->north_t[0] == '\0' && map->south_t[0] == '\0'
		&& map->sprite_t[0] == '\0' && map->west_t[0] == '\0'
		&& map->east_t[0] == '\0')
	{
		ft_simple_error("Error\nInvalid file.\n");
		return (0);
	}
	return (1);
}

int		ft_parsing_error(t_map *map)
{
	if (ft_invalid_file(map) == 0)
		return (1);
	if ((map->reso[0] == -1 || map->reso[1] == -1) ||
		(map->reso[0] == -1 && map->reso[1] == -1))
		ft_simple_error("Error\nWrong resolution.\n");
	if (map->c_path == -1)
		ft_simple_error("Error\nMissing correct ceiling path.\n");
	if (map->f_path == -1)
		ft_simple_error("Error\nWrong floor path.\n");
	if (map->north_t[0] == '\0')
		ft_simple_error("Error\nWrong north path.\n");
	if (map->south_t[0] == '\0')
		ft_simple_error("Error\nWrong south path.\n");
	if (map->east_t[0] == '\0')
		ft_simple_error("Error\nWrong east path.\n");
	if (map->west_t[0] == '\0')
		ft_simple_error("Error\nWrong west path.\n");
	if (map->sprite_t[0] == '\0')
		ft_simple_error("Error\nWrong sprite path.\n");
	if (ft_check_info_map(map) == 1 && !map->map)
		ft_simple_error("Error\nMissing map.\n");
	return (-1);
}
