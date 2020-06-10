/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:44:42 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/13 02:36:10 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_draw_side(t_vec *vec, int color)
{
	if (vec->step_y == 1 && vec->side == 1)
		color = 0xCD5C5C;
	else if (vec->step_y == -1 && vec->side == 1)
		color = 0xd97d69;
	else if (vec->step_x == 1 && vec->side == 0)
		color = 0xE9967A;
	else if (vec->step_x == -1 && vec->side == 0)
		color = 0xffae75;
	return (color);
}

void	ft_draw_mode(t_all *all)
{
	if (all->player->look == DOWN)
		ft_look_down(all);
	else if (all->player->look == UP)
		ft_look_up(all);
	else if (all->player->pos == UP)
		ft_player_jump(all);
	else if (all->player->pos == DOWN)
		ft_player_crawl(all);
}

void	ft_draw_ray(int i, t_all *all)
{
	int j;
	int color;

	j = -1;
	color = 0;
	ft_draw_mode(all);
	color = ft_draw_side(all->vec, color);
	while (++j < all->vec->draw_start)
		*(int *)&all->image->data[j * all->map->reso[0] + i] = SKYBLUE;
	while (j < all->vec->draw_end && j < all->map->reso[1])
		*(int *)&all->image->data[(j++) * all->map->reso[0] + i] = color;
	while (j < all->map->reso[1])
		*(int *)&all->image->data[(j++) * all->map->reso[0] + i] = GREY_FLOOR;
}
