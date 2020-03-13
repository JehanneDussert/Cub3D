/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:44:42 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/13 01:54:00 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_draw_mode(t_vec *vec, int color)
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

void ft_draw_ray(int i, int start, int end, t_map *info, t_wdw *wdw, t_vec *vec)
{
	int j;
	int color;

	j = -1;
	color = 0;
	color = ft_draw_mode(vec, color);
	while (++j < start)
		wdw->data[j * info->reso[0] + i] = SKYBLUE;
	while (j < end)
		wdw->data[(j++) * info->reso[0] + i] = color;
	while (j < info->reso[1])
		wdw->data[(j++) * info->reso[0] + i] = GREY_FLOOR;
}
