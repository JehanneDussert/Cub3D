#include "../../includes/cub3d.h"

void move_up(t_all *all)
{
  if(all->map->map[(int)(all->map->pos_x + all->vec->ray_dir_x * all->keys->moveSpeed)][(int)(all->map->pos_y)] == 0) 
    all->map->pos_x += all->vec->ray_dir_x * all->keys->moveSpeed;
  if(all->map->map[(int)(all->map->pos_x)][(int)(all->map->pos_y + all->vec->ray_dir_y * all->keys->moveSpeed)] == 0)
    all->map->pos_y += all->vec->ray_dir_y * all->keys->moveSpeed;
}

void move_down(t_all *all)
{
  if(all->map->map[(int)(all->map->pos_x + all->vec->ray_dir_x * all->keys->moveSpeed)][(int)(all->map->pos_y)] == 0) 
    all->map->pos_x -= all->vec->ray_dir_x * all->keys->moveSpeed;
  if(all->map->map[(int)(all->map->pos_x)][(int)(all->map->pos_y + all->vec->ray_dir_y * all->keys->moveSpeed)] == 0)
    all->map->pos_y -= all->vec->ray_dir_y * all->keys->moveSpeed;
}

void move_right(t_all *all)
{
  if(all->map->map[(int)(all->map->pos_x + all->vec->plane[0] * all->keys->moveSpeed)][(int)(all->map->pos_y)] == '0') 
     all->map->pos_x += all->vec->plane[0] * all->keys->moveSpeed;
  if(all->map->map[(int)(all->map->pos_x)][(int)(all->map->pos_y + all->vec->plane[1] * all->keys->moveSpeed)] == '0')
    all->map->pos_y += all->vec->plane[1] * all->keys->moveSpeed;
}

void move_left(t_all *all)
{
  if(all->map->map[(int)(all->map->pos_x + all->vec->plane[0] * all->keys->moveSpeed)][(int)(all->map->pos_y)] == '0') 
     all->map->pos_x -= all->vec->plane[0] * all->keys->moveSpeed;
  if(all->map->map[(int)(all->map->pos_x)][(int)(all->map->pos_y + all->vec->plane[1] * all->keys->moveSpeed)] == '0')
    all->map->pos_y -= all->vec->plane[1] * all->keys->moveSpeed;
}