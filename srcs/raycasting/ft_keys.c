/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:25:58 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/27 11:26:43 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int keyPress(int keycode, t_vec *vec)
{
	// En fonction de la keyPressed on va turn / move
	printf("hey");
	if (keycode == W_KEY)
		vec->keyUp = 1;
	if (keycode == S_KEY)
		vec->keyDown = 1;
	if (keycode == D_KEY)
		vec->keyRight = 1;
  	if (keycode == A_KEY)
    	vec->keyLeft= 1;
  	if (keycode == ARROW_RIGHT)
    	vec->keyTurnRight = 1;
  	if (keycode == ARROW_LEFT)
   		vec->keyTurnLeft = 1;
  	/*if (keycode == 12)
    	keys->moveSpeed = (keys->moveSpeed < 0.18) ?  (keys->moveSpeed * 1.5) : keys->moveSpeed;
  	if (keycode == 6)
    	keys->moveSpeed = (keys->moveSpeed > 0.08) ?  (keys->moveSpeed / 1.5) : keys->moveSpeed; 
  	if (keycode == 46)
  	{
		if (mlx->move.mode == 0)
    		mlx->move.mode = 1;
    	else if (mlx->move.mode == 1)
      		mlx->move.mode = 2;
    	else
    		mlx->move.mode = 0;
  	}*/
	if (keycode == 53)
    	vec->killWindow = 1;
	return (0);
}

int keyRelease(int keycode, t_vec *vec)
{
	// On va réinitialiser les keys à 0 pour arrêter de turn / move
	printf("This is my key :%d\n", keycode);
	if (keycode == 13)
    	vec->keyUp = 0;
  	if (keycode == 1)
    	vec->keyDown = 0;
  	if (keycode == 2)
    	vec->keyRight = 0;
  	if (keycode == 0)
    	vec->keyLeft = 0;
  	if (keycode == 124)
    	vec->keyTurnRight = 0;
  	if (keycode == 123)
    	vec->keyTurnLeft = 0;
  	if (keycode == 53)
    	vec->killWindow = 0;
	return (0);
}

int keyDeal(t_vec *vec)
{
	if(vec->keyUp == 1)
		move_up(vec, vec->map);
  	if(vec->keyDown == 1)
    	move_down(vec, vec->map);
  	if(vec->keyRight == 1)
    	move_right(vec, vec->map);
  	if(vec->keyLeft == 1)
    	move_left(vec, vec->map);
  	if(vec->keyTurnRight == 1)
    	turn_right(vec, vec->player);
  	if(vec->keyTurnLeft == 1)
    	turn_left(vec, vec->player);
	if (vec->killWindow == 1)
		exit (0);
  	ft_raycasting(vec->map, vec->img);  
	return(0);
}

int KillWindow(int key, t_vec *vec)
{
	(void)key;
	(void)vec;
  	exit (0);
}

/*
int funct(int button, int x, int y, void *param)
{
	// Dans le cas où la souris est utilisée
	return (0);
}

int funct(void *param)
{
	//  Pour tous les autres évènements
	return (0);
}*/