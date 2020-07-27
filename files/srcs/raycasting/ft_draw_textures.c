/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:04:51 by jdussert          #+#    #+#             */
/*   Updated: 2020/07/27 12:17:25 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_textures(t_all *all)
{
	if (all->vec->side == 0)
		all->vec->wallx = all->map->pos_y + all->vec->dist * all->vec->raydir_y;
	else
		all->vec->wallx = all->map->pos_x + all->vec->dist * all->vec->raydir_x;
	all->vec->wallx -= floor(all->vec->wallx);
	all->vec->texx = (int)(all->vec->wallx * 64.0);
	if (all->vec->side == 0 && all->vec->raydir_x > 0)
		all->vec->texx = 64.0 - all->vec->texx - 1;
	if (all->vec->side == 1 && all->vec->raydir_y < 0)
		all->vec->texx = 64.0 - all->vec->texx - 1;
}

int		ft_draw_ns(int i, t_vec *vec, t_text *text, t_all *all)
{
	if (vec->raydir_y >= 0)
	{
		while (vec->draw_start < vec->draw_end)
		{
			vec->texy = abs((((vec->draw_start * 256 - all->map->reso[1]
			* 128 + vec->line_height * 128) * 64) / vec->line_height) / 256);
			ft_memcpy(all->image->data + 4 * all->map->reso[0] * vec->draw_start
			+ i * 4, &text[1].img[vec->texy % 64 * text[1].size_l +
			vec->texx % 64 * text[1].bpp / 8], sizeof(int));
			vec->draw_start++;
		}
	}
	else
	{
		while (vec->draw_start < vec->draw_end)
		{
			vec->texy = abs((((vec->draw_start * 256 - all->map->reso[1] * 128
			+ vec->line_height * 128) * 64) / vec->line_height) / 256);
			ft_memcpy(all->image->data + 4 * all->map->reso[0] * vec->draw_start
			+ i * 4, &text[0].img[vec->texy % 64 * text[0].size_l +
			vec->texx % 64 * text[0].bpp / 8], sizeof(int));
			vec->draw_start++;
		}
	}
	return (1);
}

int		ft_draw_ew(int i, t_vec *vec, t_text *text, t_all *all)
{
	if (vec->raydir_x >= 0)
	{
		while (vec->draw_start < vec->draw_end)
		{
			vec->texy = abs((((vec->draw_start * 256 - all->map->reso[1] * 128
			+ vec->line_height * 128) * 64) / vec->line_height) / 256);
			ft_memcpy(all->image->data + 4 * all->map->reso[0] * vec->draw_start
			+ i * 4, &text[3].img[vec->texy % 64 * text[3].size_l +
			vec->texx % 64 * text[3].bpp / 8], sizeof(int));
			vec->draw_start++;
		}
	}
	else
	{
		while (vec->draw_start < vec->draw_end)
		{
			vec->texy = abs((((vec->draw_start * 256 - all->map->reso[1] * 128
			+ vec->line_height * 128) * 64) / vec->line_height) / 256);
			ft_memcpy(all->image->data + 4 * all->map->reso[0] * vec->draw_start
			+ i * 4, &text[2].img[vec->texy % 64 * text[2].size_l +
			vec->texx % 64 * text[2].bpp / 8], sizeof(int));
			vec->draw_start++;
		}
	}
	return (1);
}

int		ft_draw_text(int i, t_all *all)
{
	ft_textures(all);
	if (all->vec->side == 1)
		ft_draw_ns(i, all->vec, all->text, all);
	else
		ft_draw_ew(i, all->vec, all->text, all);
	if (ft_draw_ns(i, all->vec, all->text, all) != 1 ||
		ft_draw_ew(i, all->vec, all->text, all) != 1)
		return (-1);
	return (1);
}
