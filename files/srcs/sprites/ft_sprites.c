/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:48:19 by jehannedu         #+#    #+#             */
/*   Updated: 2020/08/04 14:08:13 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_s_txt(t_all *all, t_s_txt *s_txt)
{
	int i;
	int j;

	i = s_txt->draw_sx;
	while (i < s_txt->draw_ex)
	{
		s_txt->texx = (int)((256 * (i - (-s_txt->spr_w / 2
		+ s_txt->screen_x)) * s_txt->text_w / s_txt->spr_w) / 256);
		j = s_txt->draw_sy;
		while (j < s_txt->draw_ey && s_txt->transform_y > 0 &&
				s_txt->transform_y < all->buffer[i])
		{
			s_txt->d = j * 256 - all->map->reso[1] * 128 + s_txt->spr_h
			* 128;
			s_txt->texy = ((s_txt->d * s_txt->text_h) / s_txt->spr_h) / 256;
			if (all->text[4].img[s_txt->texy % 64 * all->text[4].size_l
				+ s_txt->texx % 64 * all->text[4].bpp / 8] != 0)
				ft_memcpy(all->image->data + 4 * all->map->reso[0] * j + i * 4,
				&all->text[4].img[s_txt->texy % 64 * all->text[4].size_l
				+ s_txt->texx % 64 * all->text[4].bpp / 8], sizeof(int));
			j++;
		}
		i++;
	}
}

void	ft_draw_spr(t_all *all, t_s_txt *s_txt, t_spr *spr, int *spr_order)
{
	s_txt->x = spr[spr_order[s_txt->i]].x - all->map->pos_x;
	s_txt->y = spr[spr_order[s_txt->i]].y - all->map->pos_y;
	s_txt->inv_det = 1.0 / (all->vec->plane_x * all->vec->dir_y
	- all->vec->dir_x * all->vec->plane_y);
	s_txt->transform_x = s_txt->inv_det * (all->vec->dir_y * s_txt->x
	- all->vec->dir_x * s_txt->y);
	s_txt->transform_y = s_txt->inv_det * (-all->vec->plane_y * s_txt->x
	+ all->vec->plane_x * s_txt->y);
	s_txt->screen_x = (int)((all->map->reso[0] / 2) *
	(1 + s_txt->transform_x / s_txt->transform_y));
	s_txt->spr_h = abs((int)(all->map->reso[1] / s_txt->transform_y));
	s_txt->draw_sy = -s_txt->spr_h / 2 + all->map->reso[1] / 2;
	if (s_txt->draw_sy < 0)
		s_txt->draw_sy = 0;
	s_txt->draw_ey = s_txt->spr_h / 2 + all->map->reso[1] / 2;
	if (s_txt->draw_ey >= all->map->reso[1])
		s_txt->draw_ey = all->map->reso[1] - 1;
	s_txt->spr_w = abs((int)(all->map->reso[1] / s_txt->transform_y));
	s_txt->draw_sx = -s_txt->spr_w / 2 + s_txt->screen_x;
	if (s_txt->draw_sx < 0)
		s_txt->draw_sx = 0;
	s_txt->draw_ex = s_txt->spr_w / 2 + s_txt->screen_x;
	if (s_txt->draw_ex >= all->map->reso[0])
		s_txt->draw_ex = all->map->reso[0] - 1;
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
		spr_order[i] = i;
		i++;
	}
	ft_check_spr_dist(all->map->spr, spr_order, spr_dist);
}

void	ft_sprites(t_all *all, t_spr *spr, int spr_nb)
{
	int			spr_order[spr_nb];
	double		spr_dist[spr_nb];
	t_s_txt		s_txt;

	ft_init_spr(all, spr, spr_dist, spr_order);
	s_txt.i = spr_nb - 1;
	s_txt.text_w = 64;
	s_txt.text_h = 64;
	while (s_txt.i >= 0)
	{
		ft_draw_spr(all, &s_txt, spr, spr_order);
		ft_s_txt(all, &s_txt);
		s_txt.i--;
	}
}
