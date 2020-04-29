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

int KillWindow(t_all *all)
{
	int		i;

	i = 0;
	while (all->map->map[i])
	{
		free(all->map->map[i]);
		i++;
	}
	//free(all->map->map[i]);
	//free(all->map->map);
	//free(all->vec);
	mlx_clear_window(all->image->mlx_ptr, all->image->win_ptr);
	mlx_destroy_window(all->image->mlx_ptr, all->image->win_ptr);
	exit(0);
	return(1);
}

int keyRelease(int keycode, t_all *all)
{
	// On va réinitialiser les keys à 0 pour arrêter de turn / move
	printf("This is my key, function key release :%d\n", keycode);
	if (keycode == 13)
    	all->keys->keyUp = 0;
  	else if (keycode == 1)
    	all->keys->keyDown = 0;
  	else if (keycode == 2)
    	all->keys->keyRight = 0;
  	else if (keycode == 0)
    	all->keys->keyLeft = 0;
  	else if (keycode == 124)
    	all->keys->keyTurnRight = 0;
  	else if (keycode == 123)
    	all->keys->keyTurnLeft = 0;
  	else if (keycode == 53)
    	all->keys->killWindow = 0;
	return (0);
}

int keyPress(int keycode, t_all *all)
{
	// En fonction de la keyPressed on va turn / move
	printf("This is my key :%d\n", keycode);
	if (keycode == 13)
    	all->keys->keyUp = 1;
  	else if (keycode == 1)
    	all->keys->keyDown = 1;
  	else if (keycode == 2)
    	all->keys->keyRight = 1;
  	else if (keycode == 0)
    	all->keys->keyLeft = 1;
  	else if (keycode == 124)
    	all->keys->keyTurnRight = 1;
  	else if (keycode == 123)
    	all->keys->keyTurnLeft = 1;
  	else if (keycode == 53)
    	all->keys->killWindow = 1;
	return (0);
}

int keyDeal(t_all *all)
{
	int i;

	i = -1;
	if (!(all->image->img_ptr = mlx_new_image(all->image->mlx_ptr, all->map->reso[0], all->map->reso[1])))
		return (ft_error(7, all));
	if (!(all->image->data = (int *)mlx_get_data_addr(all->image->img_ptr, &all->image->bpp, &all->image->size_l, &all->image->endian)))
		return (ft_error(7, all));
	all->image->bpp = all->image->bpp / 8;
	/*while (++i < all->map->reso[0] * (all->map->reso[1] / 2))
		*(int *)&all->image->data[i * all->image->bpp] = all->map->c_path;
	while (++i < all->map->reso[0] * (all->map->reso[1]))
		*(int *)&all->image->data[i * all->image->bpp] = all->map->f_path;
	*/
	if (!(all = ft_raycasting(all)))
		return (ft_error(4, all));
	if ((ft_move(all)) != 0)
		return (ft_error(9, all));
	if (!(mlx_put_image_to_window(all->image->mlx_ptr, all->image->win_ptr, all->image->img_ptr, 0, 0)))
		return (ft_error(7, all));
	mlx_destroy_image(all->image->mlx_ptr, all->image->img_ptr);
	if (all->keys->killWindow == 1)
		KillWindow(all);
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