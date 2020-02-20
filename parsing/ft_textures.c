/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:20:43 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/20 15:08:12 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_text(char *line, int i)
{
	if (ft_strncmp(&line[i], "NO", 2) || ft_strncmp(&line[i], "SO", 2) ||
		ft_strncmp(&line[i], "WE", 2) || ft_strncmp(&line[i], "EA", 2) ||
		ft_strncmp(&line[i], "S", 1))
		return (1);
	return (0);
}

void	ft_text(char *line, t_map *info)
{
	if (ft_ref_parse(line, "NO", ft_strlen(line)))
	{
		line = ft_ref_parse(line, "NO", ft_strlen(line));
		info->n_path = ft_strtrim(line, " ");
	}
	else if (ft_ref_parse(line, "SO", ft_strlen(line)))
	{
		line = ft_ref_parse(line, "SO", ft_strlen(line));
		info->s_path = ft_strtrim(line, " ");
	}
	else if (ft_ref_parse(line, "WE", ft_strlen(line)))
	{
		line = ft_ref_parse(line, "WE", ft_strlen(line));
		info->w_path = ft_strtrim(line, " ");
	}
	else if (ft_ref_parse(line, "EA", ft_strlen(line)))
	{
		line = ft_ref_parse(line, "EA", ft_strlen(line));
		info->e_path = ft_strtrim(line, " ");
	}
	else if (ft_ref_parse(line, "S", ft_strlen(line)))
	{
		line = ft_ref_parse(line, "S", ft_strlen(line));
		info->spr_path = ft_strtrim(line, " ");
	}
}
