/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:47:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/03 12:09:39 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void move_up(t_all *all)
{
  if (all->map->map[(int)(all->map->pos_y + all->vec->dir_y * all->keys->move_speed)][(int)(all->map->pos_x)] != '1')
    all->map->pos_y += all->vec->dir_y * all->keys->move_speed;
  if (all->map->map[(int)(all->map->pos_y)][(int)(all->map->pos_x + all->vec->dir_x * all->keys->move_speed)] != '1') 
    all->map->pos_x += all->vec->dir_x * all->keys->move_speed;
}

void move_down(t_all *all)
{
  if (all->map->map[(int)(all->map->pos_y - all->vec->dir_y * all->keys->move_speed)][(int)(all->map->pos_x)] != '1')
    all->map->pos_y -= all->vec->dir_y * all->keys->move_speed;
  if (all->map->map[(int)(all->map->pos_y)][(int)(all->map->pos_x - all->vec->dir_x * all->keys->move_speed)] != '1') 
    all->map->pos_x -= all->vec->dir_x * all->keys->move_speed;
}

void move_right(t_all *all)
{
  if (all->map->map[(int)(all->map->pos_y + all->vec->plane_y * all->keys->move_speed)][(int)(all->map->pos_x)] != '1')
    all->map->pos_y += all->vec->plane_y * all->keys->move_speed;
  if (all->map->map[(int)(all->map->pos_y)][(int)(all->map->pos_x + all->vec->plane_x * all->keys->move_speed)] != '1') 
     all->map->pos_x += all->vec->plane_x * all->keys->move_speed;
}

void move_left(t_all *all)
{
  if (all->map->map[(int)(all->map->pos_y - all->vec->plane_y * all->keys->move_speed)][(int)(all->map->pos_x)] != '1')
    all->map->pos_y -= all->vec->plane_y * all->keys->move_speed;
  if (all->map->map[(int)(all->map->pos_y)][(int)(all->map->pos_x - all->vec->plane_x * all->keys->move_speed)] != '1') 
     all->map->pos_x -= all->vec->plane_x * all->keys->move_speed;
}

int  ft_move(t_all *all)
{
  if (all->keys->keyup == 1)
    move_up(all);
  if (all->keys->keydown == 1)
    move_down(all);
  if (all->keys->keyleft == 1)
    move_left(all);
  if (all->keys->keyright == 1)
    move_right(all);
  if ((ft_rotation(all) != 0))
    return (ft_error(9, all));
  return (0);
}
