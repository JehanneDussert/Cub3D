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

void ft_ray_dir(t_map *info, t_vec *vec, t_player *player)
{
	int i;

	i = 0;
	while (i++ < info->reso[0])
	{
		// On calcule la position du ray et sa direction
		vec->camera_x = 2 * i / (double)info->reso[0] - 1; // Coordonnee x sur l'ecran
		vec->ray_dir_x = player->dir[0] + info->pos_x * vec->camera_x;
		vec->ray_dir_y = player->dir[1] + info->pos_y * vec->camera_x;
	}
}

void ft_init_sideDist(t_vec *vec, t_map *info)
{
	if (vec->ray_dir_x < 0)
	{
		vec->step_x = -1;
		vec->sideDist_x = (info->pos_x - vec->map_x) * vec->ray_dir_x;
	}
	else
	{
		vec->step_x = -1;
		vec->sideDist_x = (vec->map_x + 1.0 - info->pos_x) * vec->ray_dir_x;
	}
	if (vec->ray_dir_y < 0)
	{
		vec->step_y = -1;
		vec->sideDist_y = (info->pos_y - vec->map_y) * vec->delta_dist_y;
	}
	else
	{
		vec->step_y = 1;
		vec->sideDist_y = (vec->map_y + 1.0 - info->pos_y) * vec->delta_dist_y;
	}
}

int ft_hit(char **map, t_vec *vec)
{
	vec->hit = 0;
	/* 
	** On va incrementer x ou y d'un carre jusqu'a hit un wall
	*/
	if (vec->sideDist_x < vec->sideDist_y)
	{
		vec->sideDist_x += vec->delta_dist_x;
		vec->map_x += vec->step_x;
		vec->side = 0;
	}
	else
	{
		vec->sideDist_y += vec->delta_dist_y;
		vec->map_y += vec->step_y;
		vec->side = 1;
	}
	/*
	** On regarde si on a frappe un wall
	*/
	//ft_printf("map_x :%d\nmap_y :%d\n", vec->map_x, vec->map_y);
	if (map[vec->map_x][vec->map_y] > '0')
	{
		vec->hit = 1;
		return (vec->hit);
	}
	return (vec->hit);
}

int ft_vec_side(t_vec *vec, t_map *info)
{
	if (vec->side == 0)
		vec->dist = (vec->map_x - info->pos_x + (1 - vec->step_x) / 2) / vec->ray_dir_x;
	else
		vec->dist = (vec->map_y - info->pos_y + (1 - vec->step_y) / 2) / vec->ray_dir_y;
	return (vec->side);
}

void ft_init_draw(t_vec *vec, int height)
{
	/*
	** On calcule la hauteur de la ligne a dessiner sur l'ecran
	*/
	vec->lineHeight = (int)(height / vec->dist);
	/*
	** On calcule le premier et le dernier pixel a colorier dans la colonne
	*/
	vec->drawStart = -(vec->lineHeight) / 2 + height / 2;
	if (vec->drawStart < 0)
		vec->drawStart = 0;
	vec->drawEnd = vec->lineHeight / 2 + height / 2;
	if (vec->drawEnd >= height)
		vec->drawEnd = height - 1;
}

void ft_delta_dist(t_map *info, t_player *player, t_vec *vec, t_wdw *wdw)
{
	int i;

	i = -1;
	while (++i < info->reso[0])
	{
		/* 
		** On calcule la position du ray et la direction
		*/
		ft_ray_dir(info, vec, player);
		/*
		** Distance pour aller d'un cote x a un autre et d'un cote y a un autre
		*/
		vec->delta_dist_x = (vec->ray_dir_y == 0) ? 0 : ((vec->ray_dir_x == 0) ? 1 : ft_abs(1 / vec->ray_dir_x));
		vec->delta_dist_y = (vec->ray_dir_x == 0) ? 0 : ((vec->ray_dir_y == 0) ? 1 : ft_abs(1 / vec->ray_dir_y));
		ft_init_sideDist(vec, info);
		/*
		** DDA : on va avancer dans les x / y jusqu'a frapper un mur
		*/
		while (vec->hit == 0)
			vec->hit = ft_hit(info->map, vec);
		/*
		** On va calculer la longueur du rayon-mur afin de calculer la taille du mur a dessiner
		*/
		vec->side = ft_vec_side(vec, info);
		ft_init_draw(vec, info->reso[1]);
		/*
		** if (side == 1)
		**		color = color / 2;
		*/
		ft_draw_ray(i, vec->drawStart, vec->drawEnd, info, wdw);
	}
}

void ft_ray(t_map *info, t_image *image, t_player *player, t_wdw *wdw)
{
	t_vec *vec;

	if (!(vec = (t_vec *)malloc(sizeof(t_vec))))
		return;
	vec->hit = 0;
	/*
	** Savoir dans quel carre on est
	*/
	vec->map_x = (int)info->pos_x;
	vec->map_y = (int)info->pos_y;
	// On trace un ray par coordonnee horizontale
	image->win_ptr = mlx_new_window(image->mlx_ptr, info->reso[0], info->reso[1], image->title);
	image->player->angle = ft_def_angle(info->ori, image->player);
	image->img_ptr = mlx_new_image(image->mlx_ptr, info->reso[0], info->reso[1]);
	wdw->data = (int *)mlx_get_data_addr(image->img_ptr, &wdw->bpp, &wdw->size_l, &wdw->endian);
	ft_delta_dist(info, player, vec, wdw);
//	ft_printf("coucou\n");
	mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->img_ptr, 0, 0);
//	printf("this is my angle :%f\n", image->player->angle);
//	ft_printf("This is my dir[0]:%d\nAnd my dir[1]:%d\n", image->player->dir[0], image->player->dir[1]);
	mlx_loop(image->mlx_ptr);
}
