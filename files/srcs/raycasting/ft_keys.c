/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:25:58 by jdussert          #+#    #+#             */
/*   Updated: 2020/06/25 16:16:24 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_killwindow(t_all *all)
{
	int		i;

	i = 0;
	if (all->map->map != NULL)
	{
		while (all->map->map && all->map->map[i])
		{
			free(all->map->map[i]);
			i++;
		}
		free(all->map->map[i]);
		free(all->map->map);
	}
	/*if (all->image)
		free(all->image);
	if (all->vec)
		free(all->vec);
	if (all->text)
		free(all->text);
	if (all->keys)
		free(all->keys);
	if (all->player)
		free(all->player);*/
	if (all->image->mlx_ptr != NULL && all->image->win_ptr != NULL)
	{
		mlx_clear_window(all->image->mlx_ptr, all->image->win_ptr);
		mlx_destroy_window(all->image->mlx_ptr, all->image->win_ptr);
	}
	exit(0);
	return (1);
}

int	ft_keyrelease(int keycode, t_all *all)
{
	if (keycode == A_KEY)
		all->keys->keyup = 0;
	else if (keycode == W_KEY)
		all->keys->keydown = 0;
	else if (keycode == D_KEY)
		all->keys->keyright = 0;
	else if (keycode == S_KEY)
		all->keys->keyleft = 0;
	else if (keycode == ARROW_RIGHT)
		all->keys->keyturnright = 0;
	else if (keycode == ARROW_LEFT)
		all->keys->keyturnleft = 0;
	else if (keycode == EXIT_CODE)
		all->keys->killwindow = 0;
	else if (keycode == ARROW_UP)
		all->player->look = 0;
	else if (keycode == ARROW_DOWN)
		all->player->look = 0;
	else if (keycode == SPACE_KEY)
		all->player->pos = 0;
	else if (keycode == P_KEY)
		all->keys->move_speed = NORMAL;
	else if (keycode == O_KEY)
	{
		all->player->pos = 0;
		all->keys->move_speed = NORMAL;
	}
	return (0);
}

int	ft_keypress(int keycode, t_all *all)
{
	if (keycode == A_KEY)
		all->keys->keyup = 1;
	else if (keycode == W_KEY)
		all->keys->keydown = 1;
	else if (keycode == D_KEY)
		all->keys->keyright = 1;
	else if (keycode == S_KEY)
		all->keys->keyleft = 1;
	else if (keycode == ARROW_RIGHT)
		all->keys->keyturnright = 1;
	else if (keycode == ARROW_LEFT)
		all->keys->keyturnleft = 1;
	else if (keycode == EXIT_CODE)
		all->keys->killwindow = 1;
	else if (keycode == ARROW_UP)
		all->player->look = UP;
	else if (keycode == ARROW_DOWN)
		all->player->look = DOWN;
	else if (keycode == SPACE_KEY)
		all->player->pos = UP;
	else if (keycode == P_KEY)
		all->keys->move_speed = RUN;
	else if (keycode == O_KEY)
	{
		all->player->pos = DOWN;
		all->keys->move_speed = SLOW;
	}
	return (0);
}

int	ft_keydeal(t_all *all)
{
	int i;

	i = -1;
	if (!(all->image->img_ptr = mlx_new_image(all->image->mlx_ptr,
		all->map->reso[0], all->map->reso[1])))
		return (ft_error(7, all));
	if (!(all->image->data = mlx_get_data_addr(all->image->img_ptr,
		&all->image->bpp, &all->image->size_l, &all->image->endian)))
		return (ft_error(7, all));
	all->image->bpp = all->image->bpp / 8;
	while (++i < all->map->reso[0] * (all->map->reso[1] / 2))
		*(int *)&all->image->data[i * all->image->bpp] = all->map->c_path;
	while (++i < all->map->reso[0] * (all->map->reso[1]))
		*(int *)&all->image->data[i * all->image->bpp] = all->map->f_path;
	if (!(all = ft_raycasting(all)))
		return (ft_error(4, all));
	ft_sprites(all, all->spr, all->map->spr);
	free(all->buffer);
	if ((ft_move(all)) != 0)
		return (ft_error(9, all));
	if (!(mlx_put_image_to_window(all->image->mlx_ptr, all->image->win_ptr,
		all->image->img_ptr, 0, 0)))
		return (ft_error(7, all));
	mlx_destroy_image(all->image->mlx_ptr, all->image->img_ptr);
	if (all->keys->killwindow == 1)
		ft_killwindow(all);
	return (0);
}

/*
** int funct(int button, int x, int y, void *param)
** {
** 	// Dans le cas où la souris est utilisée
** 	return (0);
** }
**
** int funct(void *param)
** {
** 	//  Pour tous les autres évènements
** 	return (0);
}*/
