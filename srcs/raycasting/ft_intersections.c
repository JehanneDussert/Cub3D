/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/10 15:310:57 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_ray_dir(t_map *info, t_camera *camera, t_ray_dir *ray_dir, t_player *player)
{
	int i;

	i = 0;
	while (i++ < info->reso[0])
	{
		// On calcule la position du ray et sa direction
		camera->x = 2 * i / (double)info->reso[0] - 1; // Coordonnee x sur l'ecran
		ray_dir->x = player->dir[0] + player->pos.x * camera->x;
		ray_dir->y = player->dir[1] + player->pos.y * camera->x;
	}
}

int ft_hit(char **map, t_ldv *ldv, t_delta_dist *delta_dist)
{
	ldv->hit = 0;
	/* 
	** On va incrementer x ou y d'un carre jusqu'a hit un wall
	*/
	if (ldv->sideDist_x < ldv->sideDist_y)
	{
		ldv->sideDist_x += delta_dist->x;
		ldv->map_x += ldv->step_x;
		ldv->side = 0;
	}
	else
	{
		ldv->sideDist_y += delta_dist->y;
		ldv->map_y += ldv->step_y;
		ldv->side = 1;
	}
	/*
	** On regarde si on a frappe un wall
	*/
	if (map[ldv->map_x][ldv->map_y] > 0)
	{
		ldv->hit = 1;
		return (ldv->hit);
	}
	return (ldv->hit);
}

void ft_delta_dist(t_map *info)
{
	t_ldv *ldv;
	t_camera *camera;
	t_player *player;
	t_delta_dist *delta_dist;
	t_ray_dir *ray_dir;
	t_pos *pos;
	int lineHeight;
	int drawStart;
	int	drawEnd;

	// Savoir dans quelle carre on est
	if (!(ldv = (t_ldv *)malloc(sizeof(t_ldv))))
		return;
	if (!(camera = (t_camera *)malloc(sizeof(t_camera))))
		return;
	if (!(player = (t_player *)malloc(sizeof(t_camera))))
		return;
	if (!(delta_dist = (t_delta_dist *)malloc(sizeof(delta_dist))))
		return;
	if (!(ray_dir = (t_ray_dir *)malloc(sizeof(t_ray_dir))))
		return;
	if (!(pos = (t_pos *)malloc(sizeof(t_pos))))
		return;
	ft_ray_dir(info, camera, ray_dir, player);
	ldv->map_x = (int)pos->x;
	ldv->map_y = (int)pos->y;
	ldv->hit = 0;
	// Distance pour aller d'un cote x a un autre et d'un cote y a un autre
	delta_dist->x = (ray_dir->y == 0) ? 0 : ((ray_dir->x == 0) ? 1 : ft_abs(1 / ray_dir->x));
	delta_dist->y = (ray_dir->x == 0) ? 0 : ((ray_dir->y == 0) ? 1 : ft_abs(1 / ray_dir->y));
	while (i++ < info->reso[0])
	{
		if (ray_dir->x < 0)
		{
			ldv->step_x = -1;
			ldv->sideDist_x = (pos->x - ldv->map_x) * delta_dist->x;
		}
		else
		{
			ldv->step_x = -1;
			ldv->sideDist_x = (ldv->map_x + 1.0 - pos->x) * delta_dist->x;
		}
		if (ray_dir->y < 0)
		{
			ldv->step_y = -1;
			ldv->sideDist_y = (pos->y - ldv->map_y) * delta_dist->y;
		}
		else
		{
			ldv->step_y = 1;
			ldv->sideDist_y = (ldv->map_y + 1.0 - pos->y) * delta_dist->y;
		}
		/*
	** DDA : on va avancer dans les x / y jusqu'a frapper un mur
	*/
		while (ft_hit(info->map, ldv, delta_dist) == 0)
			ldv->hit = ft_hit(info->map, ldv, delta_dist);
		/*
	** On va calculer la longueur du rayon-mur afin de calculer la taille du mur a dessiner
	*/
		if (ldv->side == 0)
			ldv->dist = (ldv->map_x - pos->x + (1 - ldv->step_x) / 2) / ray_dir->x;
		else
			ldv->dist = (ldv->map_y - pos->y + (1 - ldv->step_y) / 2) / ray_dir->y;
	//Calculate height of line to draw on screen
	lineHeight = (int)(info->reso[1] / perpWallDist);
	//calculate lowest and highest pixel to fill in current stripe
	drawStart = -lineHeight / 2 + info->reso[1] / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + info->reso[1] / 2;
	if (drawEnd >= info->reso[1])
		drawEnd = info->reso[1] - 1;
	}
}

void ft_loop(t_map *info, t_image *image)
{
	int i;
	t_wdw *wdw;

	i = 0;
	image->mlx_ptr = mlx_init();
	if (!(image->pov = (t_pov *)malloc(sizeof(t_pov))))
		return;
	image->pov->plane_x = 0;
	image->pov->plane_y = 0.6;
	if (!(image->player = (t_player *)malloc(sizeof(t_player))))
		return;
	if (!(wdw = (t_wdw *)malloc(sizeof(t_wdw))))
		return;
	printf("This is my plane X :%f\nAnd my plane Y:%f\n", image->pov->plane_x, image->pov->plane_y);
	image->win_ptr = mlx_new_window(image->mlx_ptr, info->reso[0], info->reso[1], image->title);
	image->player->angle = ft_def_angle(info->ori, image->player);
	image->img_ptr = mlx_new_image(image->mlx_ptr, info->reso[0], info->reso[1]);
	wdw->data = (int *)mlx_get_data_addr(image->img_ptr, &wdw->bpp, &wdw->size_l, &wdw->endian);
	while (i++ < info->reso[0])
		wdw->data[500 * (i + 500) + 500] = 0xAC9EF0;
	mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->img_ptr, wdw->x, wdw->y);
	printf("this is my angle :%f\n", image->player->angle);
	ft_printf("This is my dir[0]:%d\nAnd my dir[1]:%d\n", image->player->dir[0], image->player->dir[1]);
	// On trace un ray par coordonnee horizontale
	ft_delta_dist(info);
	mlx_loop(image->mlx_ptr);
}