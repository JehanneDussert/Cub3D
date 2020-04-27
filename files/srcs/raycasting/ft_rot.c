#include "../../includes/cub3d.h"

void turn_right(t_vec *vec, t_keys *keys)
{
  vec->oldDir_x = vec->dirX;
  vec->dirX = vec->dirX * cos(-keys->rotSpeed) - vec->dirY * sin(-keys->rotSpeed);
  vec->dirY = vec->oldDir_x * sin(-keys->rotSpeed) + vec->dirY * cos(-keys->rotSpeed);
  vec->oldPlane_x = vec->planeX;
  vec->planeX = vec->planeX * cos(-keys->rotSpeed) - vec->planeY * sin(-keys->rotSpeed);
  vec->planeY = vec->oldPlane_x * sin(-keys->rotSpeed) + vec->planeY * cos(-keys->rotSpeed);
}

void turn_left(t_vec *vec, t_keys *keys)
{
  vec->oldDir_x = vec->dirX;
  vec->dirX = vec->dirX * cos(keys->rotSpeed) - vec->dirY * sin(keys->rotSpeed);
  vec->dirY = vec->oldDir_x * sin(keys->rotSpeed) + vec->dirY * cos(keys->rotSpeed);
  vec->oldPlane_x = vec->planeX;
  vec->planeX = vec->planeX * cos(keys->rotSpeed) - vec->planeY * sin(keys->rotSpeed);
  vec->planeY = vec->oldPlane_x * sin(keys->rotSpeed) + vec->planeY * cos(keys->rotSpeed);
}

int  ft_rotation(t_all *all)
{
  if (all->keys->keyTurnLeft == 1)
    turn_right(all->vec, all->keys);
  if (all->keys->keyTurnRight == 1)
    turn_left(all->vec, all->keys);
  return (0);
}