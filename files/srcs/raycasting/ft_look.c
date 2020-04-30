#include "../../includes/cub3d.h"

int     ft_look_up(t_all *all)
{
    all->vec->drawStart += all->vec->drawStart;
    all->vec->drawEnd = all->map->reso[1];
    return (0);
}

int     ft_look_down(t_all *all)
{
    all->vec->drawEnd -= all->vec->drawStart;
    all->vec->drawStart = 0;
    return (0);
}