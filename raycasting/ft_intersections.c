/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/27 19:31:55 by jdussert         ###   ########.fr       */
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

#include "../cub3d.h"

int		ft_degre_to_rad(int deg)
{
	int res;

	res = deg x M_PI / 180;
	return (res);
}


/* On arrondi */
int		ft_rounded_down(float f)
{
	int res;

	res = ((float)((int) f * 100)) / 100;
	return (res);
}

int		ft_tan(int)
{

}

int		ft_ray(t_map *info, t_pos *pos)
{
	int	dist;
	int tmp;
	int	inter_y;
	int	inter_x;
	int	angle;

	angle = 60;
	/* On va chercher la premiere intersection
		Si le ray va vers le nord
	La coordonnee y de l'intersection A sera :
		A.y = (Pos.y/64) (a arrondir) * 64 - 1;

		Si le ray va vers le sud
		A.y = (Pos.y/64) * 64 + 64;
	*/

	// Coordonnee y de l'intersection
	tmp = ft_rounded_down(pos->y / GRID) * (GRID) - 1;
	inter_y = ft_rounded_down(tmp / GRID);

	// Coordonnee x de l'intersection
	tmp = pos->x + (pos->y - inter_y) / ft_tan(angle);
}

void	ft_loop(t_map *info)
{
	int	i;

	i = 0;
	while (i++ < info->reso[0])
		ft_ray(info);
}