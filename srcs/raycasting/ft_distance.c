/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:08:01 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/26 16:42:15 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	** On re-calcule Dm pour chaque colonne de pixels dans le champ de vision pour
	** eviter l'effet fish eye.

	On connait la position du joueur qu'on re-calcule avec ft_player_position.
	On doit calculer l'intersection entre la ligne et le mur le plus proche.

	Avec :
	- player position aux coordonnees (x1, y1)
	- intersection aux coordonnees (x2, y2)

	La distance d avec le mur est (cf thrm de Pythagore):
		d^2 = (x1 - x2)^2 + (y1 - y2)^2
*/
