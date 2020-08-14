/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_txt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:32:37 by user42            #+#    #+#             */
/*   Updated: 2020/08/14 13:39:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_init_texture_data(t_text *text)
{
	if ((text[0].img = mlx_get_data_addr(text[0].ptr, &text[0].bpp,
		&text[0].size_l, &text[0].endian)) == NULL)
		return (-1);
	if ((text[1].img = mlx_get_data_addr(text[1].ptr, &text[1].bpp,
		&text[1].size_l, &text[1].endian)) == NULL)
		return (-1);
	if ((text[2].img = mlx_get_data_addr(text[2].ptr, &text[2].bpp,
		&text[2].size_l, &text[2].endian)) == NULL)
		return (-1);
	if ((text[3].img = mlx_get_data_addr(text[3].ptr, &text[3].bpp,
		&text[3].size_l, &text[3].endian)) == NULL)
		return (-1);
	if ((text[4].img = mlx_get_data_addr(text[4].ptr, &text[4].bpp,
		&text[4].size_l, &text[4].endian)) == NULL)
		return (-1);
	return (0);
}

int	ft_init_texture(t_all *all, t_text *text, int width, int height)
{
	if ((text[0].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->north_t, &width, &height)) == NULL)
		return (ft_error(8, all));
	if ((text[1].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->south_t, &width, &height)) == NULL)
		return (ft_error(8, all));
	if ((text[2].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->west_t, &width, &height)) == NULL)
		return (ft_error(8, all));
	if ((text[3].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->east_t, &width, &height)) == NULL)
		return (ft_error(8, all));
	if ((text[4].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->sprite_t, &width, &height)) == NULL)
		return (ft_error(8, all));
	text[5].ptr = NULL;
	if (ft_init_texture_data(text) != 0)
		return (ft_error(8, all));
	all->text = text;
	return (0);
}
