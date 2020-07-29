/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:47:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/07/29 18:52:56 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_look_up(t_all *all)
{
	all->vec->draw_start *= 2;
	all->vec->draw_end = all->map->reso[1];
	return (0);
}

int	ft_look_down(t_all *all)
{
	all->vec->draw_end -= all->vec->draw_start;
	all->vec->draw_start = 0;
	return (0);
}

int	ft_player_jump(t_all *all)
{
	all->vec->draw_start /= (0.9 - all->keys->move_speed);
	all->vec->draw_end /= (0.94 - all->keys->move_speed);
	return (0);
}

int	ft_player_crawl(t_all *all)
{
	all->vec->draw_start *= (0.94 - all->keys->move_speed);
	all->vec->draw_end *= (0.94 - all->keys->move_speed);
	return (0);
}
