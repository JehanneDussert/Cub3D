/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/04 17:10:23 by jdussert         ###   ########.fr       */
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

	// Coordonnee y de l'intersection
	inter_y = (int)pos->y - 1;
/*	inter_y = (int)(inter_y / GRID);
	ft_printf("My GRID :%d\n", GRID); */

	// Coordonnee x de l'intersection
	inter_x = (int)pos->x + ((int)pos->y - inter_y) / ft_tan(angle + ray);
//	inter_x = (int)(inter_x / GRID);
	printf("This is my inter_y :%d\n And my inter_x :%d\n", inter_y, inter_x);
	return (1);
}

void	ft_loop(t_map *info)
{
	int	i;
	double angle;

	i = 0;
	angle = ft_def_angle(info->ori);
	printf("this is my angle :%f\n", angle);
	while (i++ < 1)
		ft_ray(info->pos, angle);
}