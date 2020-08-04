/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:48:19 by jehannedu         #+#    #+#             */
/*   Updated: 2020/08/04 13:11:24 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_spr_txt(t_all *all, t_spr_txt *spr_txt)
{
	int i;
	int j;

	i = spr_txt->draw_sx;
	while (i < spr_txt->draw_ex)
	{
		spr_txt->texx = (int)((256 * (i - (-spr_txt->spr_w / 2
		+ spr_txt->screen_x)) * spr_txt->text_w / spr_txt->spr_w) / 256);
		j = spr_txt->draw_sy;
		while (j < spr_txt->draw_ey && spr_txt->transform_y > 0 &&
				spr_txt->transform_y < all->buffer[i])
		{
			spr_txt->d = j * 256 - all->map->reso[1] * 128 + spr_txt->spr_h
			* 128;
			spr_txt->texy = ((spr_txt->d * spr_txt->text_h) / spr_txt->spr_h) / 256;
			if (all->text[4].img[spr_txt->texy % 64 * all->text[4].size_l
				+ spr_txt->texx % 64 * all->text[4].bpp / 8] != 0)
				ft_memcpy(all->image->data + 4 * all->map->reso[0] * j + i * 4,
				&all->text[4].img[spr_txt->texy % 64 * all->text[4].size_l
				+ spr_txt->texx % 64 * all->text[4].bpp / 8], sizeof(int));
			j++;
		}
		i++;
	}
}

void	ft_draw_spr(t_all *all, t_spr_txt *spr_txt, t_spr *spr, int *spr_order)
{
	spr_txt->x = spr[spr_order[spr_txt->i]].x - all->map->pos_x;
	spr_txt->y = spr[spr_order[spr_txt->i]].y - all->map->pos_y;
	spr_txt->inv_det = 1.0 / (all->vec->plane_x * all->vec->dir_y
	- all->vec->dir_x * all->vec->plane_y);
	spr_txt->transform_x = spr_txt->inv_det * (all->vec->dir_y * spr_txt->x
	- all->vec->dir_x * spr_txt->y);
	spr_txt->transform_y = spr_txt->inv_det * (-all->vec->plane_y * spr_txt->x
	+ all->vec->plane_x * spr_txt->y);
	spr_txt->screen_x = (int)((all->map->reso[0] / 2) *
	(1 + spr_txt->transform_x / spr_txt->transform_y));
	spr_txt->spr_h = abs((int)(all->map->reso[1] / spr_txt->transform_y));
	spr_txt->draw_sy = -spr_txt->spr_h / 2 + all->map->reso[1] / 2;
	if (spr_txt->draw_sy < 0)
		spr_txt->draw_sy = 0;
	spr_txt->draw_ey = spr_txt->spr_h / 2 + all->map->reso[1] / 2;
	if (spr_txt->draw_ey >= all->map->reso[1])
		spr_txt->draw_ey = all->map->reso[1] - 1;
	spr_txt->spr_w = abs((int)(all->map->reso[1] / spr_txt->transform_y));
	spr_txt->draw_sx = -spr_txt->spr_w / 2 + spr_txt->screen_x;
	if (spr_txt->draw_sx < 0)
		spr_txt->draw_sx = 0;
	spr_txt->draw_ex = spr_txt->spr_w / 2 + spr_txt->screen_x;
	if (spr_txt->draw_ex >= all->map->reso[0])
		spr_txt->draw_ex = all->map->reso[0] - 1;
}

void	ft_check_spr_dist(int spr, int *spr_order, double *spr_dist)
{
	int		i;
	int		tmp_o;
	double	tmp_d;

	i = 0;
	while (i < spr - 1)
	{
		if (spr_dist[i] > spr_dist[i + 1])
		{
			tmp_d = spr_dist[i];
			spr_dist[i] = spr_dist[i + 1];
			spr_dist[i + 1] = tmp_d;
			tmp_o = spr_order[i];
			spr_order[i] = spr_order[i + 1];
			spr_order[i + 1] = tmp_o;
			i = -1;
		}
		i++;
	}
}

void	ft_init_spr(t_all *all, t_spr *spr, double *spr_dist, int *spr_order)
{
	int i;

	i = 0;
	while (i < all->map->spr)
	{
		spr_dist[i] = ((all->map->pos_x - spr[i].x) *
		(all->map->pos_x - spr[i].x) + (all->map->pos_y - spr[i].y)
		* (all->map->pos_y - spr[i].y));
		spr_order[i] = i ;
		i++;
	}
	ft_check_spr_dist(all->map->spr, spr_order, spr_dist);
}

void	ft_sprites(t_all *all, t_spr *spr, int spr_nb)
{
	int			spr_order[spr_nb];
	double		spr_dist[spr_nb];
	t_spr_txt	spr_txt;
	
	ft_init_spr(all, spr, spr_dist, spr_order);
	spr_txt.i = spr_nb - 1;
	spr_txt.text_w = 64;
	spr_txt.text_h = 64;
	while (spr_txt.i >= 0)
	{
		ft_draw_spr(all, &spr_txt, spr, spr_order);
		ft_spr_txt(all, &spr_txt);
		spr_txt.i--;
	}
}
