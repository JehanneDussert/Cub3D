/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:20:43 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/12 18:51:45 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../cub3d.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "ft_parsing.h"

char	*ft_path(char *line, void *orientation, t_image *image)
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

char	*ft_text(char *line, t_map *info, t_image *image, int *i)
{
	if (ft_ref_parse(line, "NO", ft_strlen(line)))
	{
		ft_printf("%s\n", line);
		info->n_path = ft_ref_parse(line, "NO", ft_strlen(line));
		//info->n_path = ft_path(line, info->n_path, image);
		ft_printf("%s\n", info->n_path);
		return (info->n_path);
	}
	else if (ft_ref_parse(line, "SO", ft_strlen(line)))
	{
		info->s_path = ft_path(line, info->s_path, image);
		return (info->s_path);
	}
	else if (ft_ref_parse(line, "WE", ft_strlen(line)))
	{
		info->w_path = ft_path(line, info->w_path, image);
		return (info->w_path);
	}
	else if (ft_ref_parse(line, "EA", ft_strlen(line)))
	{
		info->e_path = ft_path(line, info->e_path, image);
		return (info->e_path);
	}
	else if (ft_ref_parse(line, "S", ft_strlen(line)))
	{
		info->spr_path = ft_path(line, info->spr_path, image);
		return (info->spr_path);
	}
	(*i) = 0;
	return (NULL);
}

/*
***	void *mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );
*/