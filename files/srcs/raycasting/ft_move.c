#include "../../includes/cub3d.h"

void move_up(t_all *all)
{
  printf("move up\n");
  if(all->map->map[(int)(all->map->pos_y)][(int)(all->map->pos_x + all->vec->dirX * all->keys->moveSpeed)] == '0') 
    all->map->pos_x += all->vec->dirX * all->keys->moveSpeed;
  if(all->map->map[(int)(all->map->pos_y + all->vec->dirY * all->keys->moveSpeed)][(int)(all->map->pos_x)] == '0')
    all->map->pos_y += all->vec->dirY * all->keys->moveSpeed;
}

void move_down(t_all *all)
{
  printf("move down\n");
  if(all->map->map[(int)(all->map->pos_y)][(int)(all->map->pos_x - all->vec->dirX * all->keys->moveSpeed)] == '0') 
    all->map->pos_x -= all->vec->dirX * all->keys->moveSpeed;
  if(all->map->map[(int)(all->map->pos_y - all->vec->dirY * all->keys->moveSpeed)][(int)(all->map->pos_x)] == '0')
    all->map->pos_y -= all->vec->dirY * all->keys->moveSpeed;
}

void move_right(t_all *all)
{
  printf("move right\n");
  if(all->map->map[(int)(all->map->pos_y)][(int)(all->map->pos_x + all->vec->planeX * all->keys->moveSpeed)] == '0') 
     all->map->pos_x += all->vec->planeX * all->keys->moveSpeed;
  if(all->map->map[(int)(all->map->pos_y + all->vec->planeY * all->keys->moveSpeed)][(int)(all->map->pos_x)] == '0')
    all->map->pos_y += all->vec->planeY * all->keys->moveSpeed;
}

void move_left(t_all *all)
{
  printf("move left\n");
  if(all->map->map[(int)(all->map->pos_y)][(int)(all->map->pos_x - all->vec->planeX * all->keys->moveSpeed)] == '0') 
     all->map->pos_x -= all->vec->planeX * all->keys->moveSpeed;
  if(all->map->map[(int)(all->map->pos_y - all->vec->planeY * all->keys->moveSpeed)][(int)(all->map->pos_x)] == '0')
    all->map->pos_y -= all->vec->planeY * all->keys->moveSpeed;
}

int  ft_move(t_all *all)
{
  printf("my key :%d\n", all->keys->keyUp);
  if (all->keys->keyUp == 1)
    move_up(all);
  if (all->keys->keyDown == 1)
    move_down(all);
  if (all->keys->keyLeft == 1)
    move_left(all);
  if (all->keys->keyRight == 1)
    move_right(all);
  if ((ft_rotation(all) != 0))
    return (ft_error(9, all));
  printf("heyyy\n");
  return (0);
}
