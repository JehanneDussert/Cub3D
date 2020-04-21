/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:34:58 by jdussert          #+#    #+#             */
/*   Updated: 2020/04/18 16:34:34 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_keys_init(t_vec *vec)
{
    vec->keyUp = 0;
	vec->keyDown = 0;
	vec->keyLeft = 0;
	vec->keyRight = 0;
	vec->keyTurnRight = 0;
	vec->keyTurnLeft = 0;
	vec->killWindow = 0;
    vec->moveSpeed = 0.05;
    vec->rotSpeed = 0.01;
}