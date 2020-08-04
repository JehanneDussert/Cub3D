/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/04 17:16:20 by jdussert         ###   ########.fr       */
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

int		ft_parsing_error(t_all *all)
{
	if (all->map->reso[0] == -1 || all->map->reso[1] == -1)
		ft_error(6, all);
	else if (all->map->c_path == -1 || all->map->f_path == -1)
		ft_error(12, all);
	else if (all->map->north_t[0] == '\0' || all->map->south_t[0] == '\0'
		|| all->map->east_t[0] == '\0' || all->map->west_t[0] == '\0' ||
		all->map->sprite_t[0] == '\0')
		ft_error(8, all);
	return (1);
}
