#include "../../includes/cub3d.h"

void turn_right(t_vec *vec, t_keys *keys)
{
  //both camera direction and camera plane must be rotated
  vec->oldDir_x = vec->dir[0];
  vec->dir[0] = vec->dir[0] * cos(-keys->rotSpeed) - vec->dir[1] * sin(-keys->rotSpeed);
  vec->dir[1] = vec->oldDir_x * sin(-keys->rotSpeed) + vec->dir[1] * cos(-keys->rotSpeed);
  vec->oldPlane_x = vec->plane[0];
  vec->plane[0] = vec->plane[0] * cos(keys->rotSpeed) - vec->plane[1] * sin(-keys->rotSpeed);
  vec->plane[1] = vec->oldPlane_x * sin(-keys->rotSpeed) + vec->plane[1] * cos(-keys->rotSpeed);
}

void turn_left(t_vec *vec, t_keys *keys)
{
  //both camera direction and camera plane must be rotated
  vec->oldDir_x = vec->dir[0];
  vec->dir[0] = vec->dir[0] * cos(keys->rotSpeed) - vec->dir[1] * sin(keys->rotSpeed);
  vec->dir[1] = vec->oldDir_x * sin(keys->rotSpeed) + vec->dir[1] * cos(keys->rotSpeed);
  vec->oldPlane_x = vec->plane[0];
  vec->plane[0] = vec->plane[0] * cos(keys->rotSpeed) - vec->plane[1] * sin(keys->rotSpeed);
  vec->plane[1] = vec->oldPlane_x * sin(keys->rotSpeed) + vec->plane[1] * cos(keys->rotSpeed);
}