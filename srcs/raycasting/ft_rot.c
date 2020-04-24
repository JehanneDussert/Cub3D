#include "../../includes/cub3d.h"

void turn_right(t_vec *vec)
{
  //both camera direction and camera plane must be rotated
  vec->oldDir_x = vec->dir[0];
  vec->dir[0] = vec->dir[0] * cos(-vec->rotSpeed) - vec->dir[1] * sin(-vec->rotSpeed);
  vec->dir[1] = vec->oldDir_x * sin(-vec->rotSpeed) + vec->dir[1] * cos(-vec->rotSpeed);
  vec->oldPlane_x = vec->plane[0];
  vec->plane[0] = vec->plane[0] * cos(vec->rotSpeed) - vec->plane[1] * sin(-vec->rotSpeed);
  vec->plane[1] = vec->oldPlane_x * sin(-vec->rotSpeed) + vec->plane[1] * cos(-vec->rotSpeed);
}

void turn_left(t_vec *vec)
{
  //both camera direction and camera plane must be rotated
  vec->oldDir_x = vec->dir[0];
  vec->dir[0] = vec->dir[0] * cos(vec->rotSpeed) - vec->dir[1] * sin(vec->rotSpeed);
  vec->dir[1] = vec->oldDir_x * sin(vec->rotSpeed) + vec->dir[1] * cos(vec->rotSpeed);
  vec->oldPlane_x = vec->plane[0];
  vec->plane[0] = vec->plane[0] * cos(vec->rotSpeed) - vec->plane[1] * sin(vec->rotSpeed);
  vec->plane[1] = vec->oldPlane_x * sin(vec->rotSpeed) + vec->plane[1] * cos(vec->rotSpeed);
}