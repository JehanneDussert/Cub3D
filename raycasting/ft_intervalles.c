/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intervalles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:16:38 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/26 15:24:41 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	Fonction calcul des intervalles :
	On calcule la hauteur percue Hp = De x (Hm/Dm)
	Ou De = distance ecran, Hm = hauteur mur, Dm = distance mur

	On distingue les categories de pixels a colorier :
	- les murs : intervalle[Hr - (Hp/2), Hr + (Hp/2)] ;
	- le sol : intervalle en dessous ;
	- le plafond : intervalle au dessus.

	Du coup on va faire 4 fonctions :
	1) Fonction pour colorier les murs
	2) Fonction pour colorier le plafond
	3) Fonction pour colorier le sol
	4) Fonction qui appelle la fonction ft_intersections pour calculer la distamce
	avec les murs / objets et qui appelle apres les trois premieres
*/