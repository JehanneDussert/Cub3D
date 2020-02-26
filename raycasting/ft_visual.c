/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:42:52 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/26 18:08:48 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	On va retirer l'effet fish-eye a notre rendu.
	Pour cela on va prendre le ray non perpendiculaire au mur et le mul†iplier par
	le cosinus de notre angle forme entre ce ray et la droite perpendiculaire au mur.
*/