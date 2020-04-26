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
	if (!(all->text = (t_text *)malloc(sizeof(t_text))))
        return (NULL);
    if (!(ft_keys_init(all->vec)))
        return (NULL);
    if (!(ft_init_map(all->map)))
        return (NULL);
    return (all);
}
