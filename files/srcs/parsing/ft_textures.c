/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:20:43 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/03 12:09:46 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_open_text(t_map *map)
{
	if (!(open(map->n_path, O_RDONLY)))
		return (-1);
	if (!(open(map->s_path, O_RDONLY)))
		return (-1);
	if (!(open(map->e_path, O_RDONLY)))
		return (-1);
	if (!(open(map->w_path, O_RDONLY)))
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
	while(i < (int)ft_strlen(line) && line[i] == ' ')
		i++;
	while ((i + len) <= (int)ft_strlen(line) && line[len + i] != ' ')
		len++;
	if (ft_ref_parse(line, "NO", ft_strlen(line)))
		ft_strlcpy(map->n_path, &line[i], len);
	else if (ft_ref_parse(line, "SO", ft_strlen(line)))
		ft_strlcpy(map->s_path, &line[i], len);
	else if (ft_ref_parse(line, "WE", ft_strlen(line)))
		ft_strlcpy(map->w_path, &line[i], len);
	else if (ft_ref_parse(line, "EA", ft_strlen(line)))
		ft_strlcpy(map->e_path, &line[i], len);
	else if (ft_ref_parse(line, "S", ft_strlen(line)))
		ft_strlcpy(map->spr_path, &line[i], len);
}
