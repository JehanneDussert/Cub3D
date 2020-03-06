/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/06 14:54:34 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* On va checker les intersections avec les walls */

/* 
	On connait Hm (hauteur mur) et De (distance ecran)
	On calcule notre inconnue Dm (distance mur) cf ft_intervalles. 
	C'est ce qui va me permettre de colorier mes pixels apres et de definir mes 
	intervalles mur / plafond / sol.

	Dm a recalculer pour chaque colonne de pixels dans le champ de vision.
*/

#include "../../includes/cub3d.h"

int		ft_ray(t_pos *pos, double angle)
{
	int	inter_y;
	int	inter_x;
	int	ray;

	ray = -30;
	/* On va chercher la premiere intersection
		Si le ray va vers le nord
	La coordonnee y de l'intersection A sera :
		A.y = (Pos.y/64) (a arrondir) * 64 - 1;

		Si le ray va vers le sud
		A.y = (Pos.y/64) * 64 + 64;
	*/

	printf("My pos y :%f\n", pos->y);
	// Le ray angle - 30
	// Coordonnee y de l'intersection
	inter_y = (int)pos->y;
/*	inter_y = (int)(inter_y / GRID);
	ft_printf("My GRID :%d\n", GRID); */

	// Coordonnee x de l'intersection
	inter_x = (int)pos->x + ((int)pos->y - inter_y) / ft_tan(angle + ray);
//	inter_x = (int)(inter_x / GRID);
	printf("This is my inter_y :%d\nAnd my inter_x :%d\n", inter_y, inter_x);

	inter_y -= 1;
	inter_x = (int)pos->x + ((int)pos->y - inter_y) / ft_tan(angle + ray);
	printf("This is my inter_y :%d\nAnd my inter_x :%d\n", inter_y, inter_x);

	inter_y -= 1;
	inter_x = (int)pos->x + ((int)pos->y - inter_y) / ft_tan(angle + ray);
	printf("This is my inter_y :%d\nAnd my inter_x :%d\n", inter_y, inter_x);

	inter_y -= 1;
	inter_x = (int)pos->x + ((int)pos->y - inter_y) / ft_tan(angle + ray);
	printf("This is my inter_y :%d\nAnd my inter_x :%d\n", inter_y, inter_x);
	return (1);
}

void	ft_loop(t_map *info, t_image *image)
{
	int		i;
	t_wdw	*wdw;

	i = 0;
	image->mlx_ptr = mlx_init();
	if (!(image->pov = (t_pov *)malloc(sizeof(t_pov))))
		return ;
	image->pov->plane_X = 0;
	image->pov->plane_Y = 0.6;
	if (!(image->player = (t_player *)malloc(sizeof(t_player))))
		return ;
	if (!(wdw = (t_wdw *)malloc(sizeof(t_wdw))))
		return ;
	printf("This is my plane X :%f\nAnd my plane Y:%f\n", image->pov->plane_X, image->pov->plane_Y);
	image->win_ptr = mlx_new_window(image->mlx_ptr, info->reso[0], info->reso[1], image->title);
	image->player->angle = ft_def_angle(info->ori, image->player);
	image->img_ptr = mlx_new_image(image->mlx_ptr, info->reso[0], info->reso[1]);
	wdw->data = (int *)mlx_get_data_addr (image->img_ptr, &wdw->bpp, &wdw->size_l, &wdw->endian);
	while (i++ < 300)
		wdw->data[100 *(i + 1000) + 100] = 0xAC9EF0;
	mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->img_ptr, wdw->x, wdw->y);
	printf("this is my angle :%f\n", image->player->angle);
	ft_printf("This is my dir[0]:%d\nAnd my dir[1]:%d\n", image->player->dir[0], image->player->dir[1]);
	// On trace un ray par coordonnee horizontale
//	while (i++ < info->reso[0])
		//ft_ray(info->pos, image->player->angle);
	mlx_loop(image->mlx_ptr);
}