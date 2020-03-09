/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/09 19:47:51 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_ray_dir(t_map *info, t_camera *camera, t_ray_dir *ray_dir, t_player *player, t_image *image)
{
	int	i;

	i = 0;
	while (i++ < info->reso[0])
	{
		// On calcule la position du ray et sa direction
		camera->x = 2 * i / (double)info->reso[0] - 1; // Coordonnee x sur l'ecran
		ray_dir->x = player->dir[0] + image->pov->x * camera->x;
		ray_dir->y = player->dir[1] + image->pov->y * camera->x;
	}
}

void	ft_delta_dist(t_delta_dist *delta_dist, t_ray_dir *ray_dir, t_pos pos)
{
	int		map_x;
	int		map_y;
	double	sideDist_x;
	double	sideDist_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;

	// Savoir dans quelle carre on est
	map_x = (int)pos.x;
	map_y = (int)pos.y;
	hit = 0;
	// Distance pour aller d'un cote x a un autre et d'un cote y a un autre
	delta_dist->x = (ray_dir->y == 0) ? 0 : ((ray_dir->x == 0) ? 1 : ft_abs(1 / ray_dir->x));
	delta_dist->y = (ray_dir->x == 0) ? 0 : ((ray_dir->y == 0) ? 1 : ft_abs(1 / ray_dir->y));
	if (ray_dir->x < 0)
	{
		step_x = -1;
		sideDist_x = (pos.x - map_x) * delta_dist->x;
	}
	else
	{
		step_x = -1;
		sideDist_x = (map_x + 1.0 - pos.x) * delta_dist->x;
	}
	if (ray_dir->y < 0)
	{
		step_y = -1;
		sideDist_y = (pos->y - map_y) * delta_dist->y;
	}
	else
	{
		step_y = 1;
		sideDist_y = (map_y + 1.0 - pos.y) * delta_dist->y;
	}
	//perform DDA
	while (hit == 0)
	{
	//jump to next map square, OR in x-direction, OR in y-direction
		if (sideDist_x < sideDist_y)
		{
			sideDist_x += delta_dist->x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			sideDist_y += delta_dist->y;
			map_y += step_y;
			side = 1;
		}
		//Check if ray has hit a wall
		if (info->map[map_x][map_y] > 0)
			hit = 1;
	} 
}

void	ft_loop(t_map *info, t_image *image)
{
	int		i;
	t_wdw	*wdw;

	i = 0;
	image->mlx_ptr = mlx_init();
	if (!(image->pov = (t_pov *)malloc(sizeof(t_pov))))
		return ;
	image->pov->plane_x = 0;
	image->pov->plane_y = 0.6;
	if (!(image->player = (t_player *)malloc(sizeof(t_player))))
		return ;
	if (!(wdw = (t_wdw *)malloc(sizeof(t_wdw))))
		return ;
	printf("This is my plane X :%f\nAnd my plane Y:%f\n", image->pov->plane_x, image->pov->plane_y);
	image->win_ptr = mlx_new_window(image->mlx_ptr, info->reso[0], info->reso[1], image->title);
	image->player->angle = ft_def_angle(info->ori, image->player);
	image->img_ptr = mlx_new_image(image->mlx_ptr, info->reso[0], info->reso[1]);
	wdw->data = (int *)mlx_get_data_addr (image->img_ptr, &wdw->bpp, &wdw->size_l, &wdw->endian);
	while (i++ < info->reso[0])
		wdw->data[500 * (i + 500) + 500] = 0xAC9EF0;
	mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->img_ptr, wdw->x, wdw->y);
	printf("this is my angle :%f\n", image->player->angle);
	ft_printf("This is my dir[0]:%d\nAnd my dir[1]:%d\n", image->player->dir[0], image->player->dir[1]);
	// On trace un ray par coordonnee horizontale
	while (i++ < info->reso[0])
		ft_ray(info->pos, image->player->angle);
	mlx_loop(image->mlx_ptr);
}