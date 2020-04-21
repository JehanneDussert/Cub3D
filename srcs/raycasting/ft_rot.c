#include "../../includes/cub3d.h"

void turn_right(t_vec *vec, t_player *player)
{
  //both camera direction and camera plane must be rotated
  vec->oldDir_x = player->dir[0];
  player->dir[0] = player->dir[0] * cos(-vec->rotSpeed) - player->dir[1] * sin(-vec->rotSpeed);
  player->dir[1] = vec->oldDir_x * sin(-vec->rotSpeed) + player->dir[1] * cos(-vec->rotSpeed);
  vec->oldPlane_x = player->plane[0];
  player->plane[0] = player->plane[0] * cos(vec->rotSpeed) - player->plane[1] * sin(-vec->rotSpeed);
  player->plane[1] = vec->oldPlane_x * sin(-vec->rotSpeed) + player->plane[1] * cos(-vec->rotSpeed);
}

void turn_left(t_vec *vec, t_player *player)
{
  //both camera direction and camera plane must be rotated
  vec->oldDir_x = player->dir[0];
  player->dir[0] = player->dir[0] * cos(vec->rotSpeed) - player->dir[1] * sin(vec->rotSpeed);
  player->dir[1] = vec->oldDir_x * sin(vec->rotSpeed) + player->dir[1] * cos(vec->rotSpeed);
  vec->oldPlane_x = player->plane[0];
  player->plane[0] = player->plane[0] * cos(vec->rotSpeed) - player->plane[1] * sin(vec->rotSpeed);
  player->plane[1] = vec->oldPlane_x * sin(vec->rotSpeed) + player->plane[1] * cos(vec->rotSpeed);
}