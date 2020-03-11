/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:44:42 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/11 17:20:45 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_draw_ray(int i, int start, int end, t_map *info, t_wdw *wdw)
{
	int j;

	j = 0;
	while (j++ < start)
		wdw->data[i * info->reso[0] + j] = SKYBLUE;
	while (j++ < end)
		wdw->data[i * info->reso[0] + j] = D_RED;
	while (j++ < info->reso[1])
		wdw->data[i * info->reso[0] + j] = GREY_FLOOR;
}
