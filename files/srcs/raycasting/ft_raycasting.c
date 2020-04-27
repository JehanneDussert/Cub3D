/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:39:38 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/11 17:59:55 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_all	*ft_raycasting(t_all *all)
{
	//printf("rentrée\n");
	//if (!(all = ft_def_dir_plane(all)))
	//	return (NULL);
	//printf("dir plane ok\n");
	if (!(all = ft_delta_dist(all->vec, all->map, all)))
		return (NULL);
	//printf("delta dist ok\n");
	return (all);
}