#include "../../includes/cub3d.h"

int		ft_init_texture_data(t_all *all)
{
	if (!(all->text[0].img = mlx_get_data_addr(all->text[0].ptr, &all->text[0].bpp,
	&all->text[0].size_l, &all->text[0].endian)))
		return (ft_error(8, all));
	if (!(all->text[1].img = mlx_get_data_addr(all->text[1].ptr, &all->text[1].bpp,
	&all->text[1].size_l, &all->text[1].endian)))
		return (ft_error(8, all));
	if (!(all->text[2].img = mlx_get_data_addr(all->text[2].ptr, &all->text[2].bpp,
	&all->text[2].size_l, &all->text[2].endian)))
		return (ft_error(8, all));
	if (!(all->text[2].img = mlx_get_data_addr(all->text[3].ptr, &all->text[3].bpp,
	&all->text[2].size_l, &all->text[3].endian)))
		return (ft_error(8, all));
	return (0);
}

int		ft_init_texture(t_all *all)
{
	if ((all->text[0].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->n_path, &all->image->width, &all->image->height)) == NULL)
		return (ft_error(8, all));
	if ((all->text[1].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->s_path, &all->image->width, &all->image->height)) == NULL)
		return (ft_error(8, all));
	if ((all->text[2].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->w_path, &all->image->width, &all->image->height)) == NULL)
		return (ft_error(8, all));
	if ((all->text[3].ptr = mlx_xpm_file_to_image(all->image->mlx_ptr,
	all->map->e_path, &all->image->width, &all->image->height)) == NULL)
		return (ft_error(8, all));
	ft_init_texture_data(all);
	return (0);
}

t_keys *ft_keys_init(t_keys *keys)
{
	keys->keyUp = 0;
	keys->keyDown = 0;
	keys->keyLeft = 0;
	keys->keyRight = 0;
	keys->keyTurnRight = 0;
	keys->keyTurnLeft = 0;
	keys->moveSpeed = 0.2;
	keys->rotSpeed = 0.2;
	keys->killWindow = 0;
	return (keys);
}

t_vec   *ft_vec_init(t_vec *vec)
{
	vec->map_x = 0;
	vec->map_y = 0;
	vec->sideDistX = 0.0;
	vec->sideDistY = 0.0;
	vec->step_x = 0;
	vec->step_y = 0;
	vec->side = 0;
	vec->hit = 0;
	vec->dist = 0.0;
	vec->rayDirX = 0.0;
	vec->rayDirY = 0.0;
	vec->deltaDistX = 0.0;
	vec->deltaDistY = 0.0;
	vec->camera_x = 0.0;
	vec->lineHeight = 0;
	vec->drawStart = 0;
	vec->drawEnd = 0;
	vec->oldDir_x = 0.0;
	vec->oldDir_y = 0.0;
	vec->oldPlane_x = 0.0;
	vec->oldPlane_y = 0.0;
	vec->dirX = -1;
	vec->dirY = 0;
	vec->planeX = 0.66;
	vec->planeY = 0;
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
	map->ori = ' ';
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
	if (!(all->text = (t_text *)malloc(sizeof(t_text))))
        return (NULL);
	if (!(all->keys = (t_keys *)malloc(sizeof(t_keys))))
        return (NULL);
    if (!(ft_vec_init(all->vec)))
        return (NULL);
    if (!(ft_init_map(all->map)))
        return (NULL);
	if (!(ft_keys_init(all->keys)))
        return (NULL);
    return (all);
}
