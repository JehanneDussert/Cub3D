/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:00:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/26 16:07:16 by jdussert         ###   ########.fr       */
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

int		ft_intersections(t_map *info)
{
	
}