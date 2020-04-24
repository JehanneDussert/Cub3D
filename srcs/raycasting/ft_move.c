#include "../../includes/cub3d.h"

void move_up(t_vec *vec, t_map *map)
{
  if(map->map[(int)(map->pos_x + vec->ray_dir_x * vec->moveSpeed)][(int)(map->pos_y)] == 0) 
    map->pos_x += vec->ray_dir_x * vec->moveSpeed;
  if(map->map[(int)(map->pos_x)][(int)(map->pos_y + vec->ray_dir_y * vec->moveSpeed)] == 0)
    map->pos_y += vec->ray_dir_y * vec->moveSpeed;
}

void move_down(t_vec *vec, t_map *map)
{
  if(map->map[(int)(map->pos_x + vec->ray_dir_x * vec->moveSpeed)][(int)(map->pos_y)] == 0) 
    map->pos_x -= vec->ray_dir_x * vec->moveSpeed;
  if(map->map[(int)(map->pos_x)][(int)(map->pos_y + vec->ray_dir_y * vec->moveSpeed)] == 0)
    map->pos_y -= vec->ray_dir_y * vec->moveSpeed;
}

void move_right(t_vec *vec, t_map *map)
{
  if(map->map[(int)(map->pos_x + vec->plane[0] * vec->moveSpeed)][(int)(map->pos_y)] == '0') 
     map->pos_x += vec->plane[0] * vec->moveSpeed;
  if(map->map[(int)(map->pos_x)][(int)(map->pos_y + vec->plane[1] * vec->moveSpeed)] == '0')
    map->pos_y += vec->plane[1] * vec->moveSpeed;
}

void move_left(t_vec *vec, t_map *map)
{
  if(map->map[(int)(map->pos_x + vec->plane[0] * vec->moveSpeed)][(int)(map->pos_y)] == '0') 
     map->pos_x -= vec->plane[0] * vec->moveSpeed;
  if(map->map[(int)(map->pos_x)][(int)(map->pos_y + vec->plane[1] * vec->moveSpeed)] == '0')
    map->pos_y -= vec->plane[1] * vec->moveSpeed;
}