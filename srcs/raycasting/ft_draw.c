/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:44:42 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/12 11:42:07 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_draw_ray(int i, int start, int end, t_map *info, t_wdw *wdw)
{
	int j;

	j = -1;
	printf("My start:%d\nMy end :%d\n", start, end);
	while (++j < start)
		wdw->data[j * info->reso[0] + i] = SKYBLUE;
	while (j < end)
		wdw->data[(j++) * info->reso[0] + i] = D_RED;
	while (j < info->reso[1])
		wdw->data[(j++) * info->reso[0] + i] = GREY_FLOOR;
}
