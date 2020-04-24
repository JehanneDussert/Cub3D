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
	printf("hey\n");
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
  	if (keycode == 12)
    	vec->moveSpeed = (vec->moveSpeed < 0.18) ?  (vec->moveSpeed * 1.5) : vec->moveSpeed;
  	if (keycode == 6)
    	vec->moveSpeed = (vec->moveSpeed > 0.08) ?  (vec->moveSpeed / 1.5) : vec->moveSpeed; 
  	/*if (keycode == 46)
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

int keyRelease(int keycode, t_all *all)
{
	// On va réinitialiser les keys à 0 pour arrêter de turn / move
	//printf("This is my key :%d\n", keycode);
	printf("In function key release\n");
	//keyDeal(all);
	if (keycode == 13)
    	all->vec->keyUp = 0;
  	if (keycode == 1)
    	all->vec->keyDown = 0;
  	if (keycode == 2)
    	all->vec->keyRight = 0;
  	if (keycode == 0)
    	all->vec->keyLeft = 0;
  	if (keycode == 124)
    	all->vec->keyTurnRight = 0;
  	if (keycode == 123)
    	all->vec->keyTurnLeft = 0;
  	if (keycode == 53)
    	all->vec->killWindow = 0;
	//keyDeal(all);
	return (0);
}

int keyDeal(t_all *all)
{
	printf("yoyoyo\n");
	if (all->vec->keyUp == 1)
		move_up(all->vec, all->map);
  	if (all->vec->keyDown == 1)
    	move_down(all->vec, all->map);
  	if (all->vec->keyRight == 1)
    	move_right(all->vec, all->map);
  	if (all->vec->keyLeft == 1)
    	move_left(all->vec, all->map);
  	if (all->vec->keyTurnRight == 1)
    	turn_right(all->vec);
  	if (all->vec->keyTurnLeft == 1)
    	turn_left(all->vec);
	if (all->vec->killWindow == 1)
		exit (0);
	printf("keydeal\n");
  	ft_raycasting(all);  
	printf("new raycasting\n");
	return (0);
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