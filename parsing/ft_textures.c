/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:20:43 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/14 16:16:58 by jdussert         ###   ########.fr       */
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

char	*ft_path(char *line)
{
	int		i;

	i = 0;
	ft_jump(line, &i);
	return (line);
	/*
	 image->title = line une fois qu'on retire le "NO" etc 
	path = mlx_xpm_file_to_image(image->mlx_ptr, line, &j, &k);
	 get data addr apres */
}

void	ft_text(char *line, t_map *info)
{
	if (ft_ref_parse(line, "NO", ft_strlen(line)))
	{
		line = ft_ref_parse(line, "NO", ft_strlen(line));
		line = ft_strtrim(line, " ");
		info->n_path = line;
		ft_printf("%s\n", info->n_path);
	}
	else if (ft_ref_parse(line, "SO", ft_strlen(line)))
	{
		line = ft_ref_parse(line, "SO", ft_strlen(line));
		line = ft_strtrim(line, " ");
		info->s_path = line;
		ft_printf("%s\n", info->s_path);
	}
	else if (ft_ref_parse(line, "WE", ft_strlen(line)))
	{
		line = ft_ref_parse(line, "WE", ft_strlen(line));
		line = ft_strtrim(line, " ");
		info->w_path = line;
		ft_printf("%s\n", info->w_path);
	}
	else if (ft_ref_parse(line, "EA", ft_strlen(line)))
	{
		line = ft_ref_parse(line, "EA", ft_strlen(line));
		line = ft_strtrim(line, " ");
		info->e_path = line;
		ft_printf("%s\n", info->e_path);
	}
	else if (ft_ref_parse(line, "S", ft_strlen(line)))
	{
		line = ft_ref_parse(line, "S", ft_strlen(line));
		line = ft_strtrim(line, " ");
		info->spr_path = line;
//		ft_printf("%s\n", info->spr_path);
	}
}

/*
***	void *mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );
*/