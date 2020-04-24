#include "../../includes/cub3d.h"

t_vec   *ft_keys_init(t_vec *vec)
{
    vec->keyUp = 0;
	vec->keyDown = 0;
	vec->keyLeft = 0;
	vec->keyRight = 0;
	vec->keyTurnRight = 0;
	vec->keyTurnLeft = 0;
	vec->killWindow = 0;
    vec->moveSpeed = 0.05;
    vec->rotSpeed = 0.01;
    return (vec);
}

t_map	*ft_init_map(t_map *map)
{
	map->reso[0] = -1;
	map->reso[1] = -1;
	map->n_path = NULL;
	map->s_path = NULL;
	map->w_path = NULL;
	map->e_path = NULL;
	map->spr_path = NULL;
	map->f_path = -1;
	map->c_path = -1;
	map->pos_x = 0;
	map->pos_y = 0;
	return (map);
}

t_all    *ft_init_all(t_all *all)
{
    if (!(all->image = (t_image *)malloc(sizeof(t_image))))
        return (NULL);
    if (!(all->map = (t_map *)malloc(sizeof(t_map))))
        return (NULL);
    if (!(all->vec = (t_vec *)malloc(sizeof(t_vec))))
        return (NULL);
    if (!(ft_keys_init(all->vec)))
        return (NULL);
    if (!(ft_init_map(all->map)))
        return (NULL);
    return (all);
}
