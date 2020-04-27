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

int KillWindow(int key, t_all *all)
{
	int		i;

	(void)key;
	i = 0;
	while (all->map->map[i])
	{
		free(all->map->map[i]);
		i++;
	}
	free(all->map->map[i]);
	free(all->map->map);
	mlx_clear_window(all->image->mlx_ptr, all->image->win_ptr);
	mlx_destroy_window(all->image->mlx_ptr, all->image->win_ptr);
	exit(0);
	return(1);
}

int keyRelease(int keycode, t_all *all)
{
	// On va réinitialiser les keys à 0 pour arrêter de turn / move
	printf("This is my key :%d\n", keycode);
	printf("In function key release\n");
	if (keycode == 13)
    	all->keys->keyUp = 0;
  	if (keycode == 1)
    	all->keys->keyDown = 0;
  	if (keycode == 2)
    	all->keys->keyRight = 0;
  	if (keycode == 0)
    	all->keys->keyLeft = 0;
  	if (keycode == 124)
    	all->keys->keyTurnRight = 0;
  	if (keycode == 123)
    	all->keys->keyTurnLeft = 0;
  	if (keycode == 53)
    	all->keys->killWindow = 0;
	return (0);
}

int keyPress(int keycode, t_keys *keys)
{
	// En fonction de la keyPressed on va turn / move
	printf("This is my key :%d\n", keycode);
	if (keycode == W_KEY)
		keys->keyUp = 1;
	if (keycode == S_KEY)
		keys->keyDown = 1;
	if (keycode == D_KEY)
		keys->keyRight = 1;
  	if (keycode == A_KEY)
    	keys->keyLeft= 1;
  	if (keycode == ARROW_RIGHT)
    	keys->keyTurnRight = 1;
  	if (keycode == ARROW_LEFT)
   		keys->keyTurnLeft = 1;
	else
		printf("%d\n", keycode);
  	/*if (keycode == 12)
    	keys->moveSpeed = (keys->moveSpeed < 0.18) ?  (keys->moveSpeed * 1.5) : keys->moveSpeed;
  	if (keycode == 6)
    	keys->moveSpeed = (keys->moveSpeed > 0.08) ?  (keys->moveSpeed / 1.5) : keys->moveSpeed; 
  	*/
	/*if (keycode == 46)
  	{
		if (mlx->move.mode == 0)
    		mlx->move.mode = 1;
    	else if (mlx->move.mode == 1)
      		mlx->move.mode = 2;
    	else
    		mlx->move.mode = 0;
  	}*/
	/*if (keycode == 53)
    	keys->killWindow = 1;*/
	return (0);
}

int keyDeal(t_all *all)
{
	int i;

	i = -1;
	if (!(all->image->img_ptr = mlx_new_image(all->image->mlx_ptr, all->map->reso[0], all->map->reso[1])))
		return (ft_error(7, all));
	printf("new image ok\n");
	if (!(all->image->data = (int *)mlx_get_data_addr(all->image->img_ptr, &all->image->bpp, &all->image->size_l, &all->image->endian)))
		return (ft_error(7, all));
	printf("data addr ok\n");
	all->image->bpp = all->image->bpp / 8;
	/*while (++i < all->map->reso[0] * (all->map->reso[1] / 2))
		*(int *)&all->image->data[i * all->image->bpp] = all->map->c_path;
	while (++i < all->map->reso[0] * (all->map->reso[1]))
		*(int *)&all->image->data[i * all->image->bpp] = all->map->f_path;
	*/
	if (!(all = ft_raycasting(all)))
		return (ft_error(4, all));
	if (!(mlx_put_image_to_window(all->image->mlx_ptr, all->image->win_ptr, all->image->img_ptr, 0, 0)))
		return (ft_error(7, all));
	mlx_destroy_image(all->image->mlx_ptr, all->image->img_ptr);
	//	return (ft_error(7, all));
	printf("put image ok\n");
	//KillWindow(0, all);
	return (0);
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