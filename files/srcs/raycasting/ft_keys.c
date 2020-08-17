/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:25:58 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/17 10:31:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_killwindow(t_all *all)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (all->map && all->map->map && i < all->map->len_y)
		ft_free((void **)&all->map->map[i++]);
	if (all->map && all->map->map)
		ft_free((void **)&all->map->map);
	while (y < 5)
	{
		mlx_destroy_image(all->image->mlx_ptr, all->text[y].ptr);
		all->text[y].ptr = NULL;
		all->text[y].img = NULL;
		y++;
	}
	all->image->mlx_ptr = NULL;
	if (all->image->mlx_ptr != 0 && all->image->win_ptr != 0)
	{
		mlx_clear_window(all->image->mlx_ptr, all->image->win_ptr);
		mlx_destroy_window(all->image->mlx_ptr, all->image->win_ptr);
	}
	exit(0);
	return (1);
}

int	ft_keyrelease(int keycode, t_keys *keys)
{
	if (keycode == A_KEY)
		keys->keyup = 0;
	else if (keycode == W_KEY)
		keys->keydown = 0;
	else if (keycode == D_KEY)
		keys->keyright = 0;
	else if (keycode == S_KEY)
		keys->keyleft = 0;
	else if (keycode == ARROW_RIGHT)
		keys->keyturnright = 0;
	else if (keycode == ARROW_LEFT)
		keys->keyturnleft = 0;
	else if (keycode == EXIT_CODE)
		keys->killwindow = 0;
	else if (keycode == P_KEY)
		keys->move_speed = NORMAL;
	else if (keycode == O_KEY)
		keys->move_speed = NORMAL;
	return (0);
}

int	ft_keypress(int keycode, t_keys *keys)
{
	if (keycode == A_KEY)
		keys->keyup = 1;
	else if (keycode == W_KEY)
		keys->keydown = 1;
	else if (keycode == D_KEY)
		keys->keyright = 1;
	else if (keycode == S_KEY)
		keys->keyleft = 1;
	else if (keycode == ARROW_RIGHT)
		keys->keyturnright = 1;
	else if (keycode == ARROW_LEFT)
		keys->keyturnleft = 1;
	else if (keycode == EXIT_CODE)
		keys->killwindow = 1;
	else if (keycode == P_KEY)
		keys->move_speed = RUN;
	else if (keycode == O_KEY)
		keys->move_speed = SLOW;
	return (0);
}

int	ft_new_image(t_all *all)
{
	if (all->s == 0)
		mlx_put_image_to_window(all->image->mlx_ptr, all->image->win_ptr,
			all->image->img_ptr, 0, 0);
	if (all->s == 0)
		mlx_destroy_image(all->image->mlx_ptr, all->image->img_ptr);
	if (all->keys->killwindow == 1)
		ft_killwindow(all);
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
	if (!(all = ft_raycasting(all->vec, all->map, all)))
		return (ft_error(4, all));
	ft_sprites(all, all->spr, all->map->spr);
	free(all->buffer);
	if ((ft_move(all)) != 0)
		return (ft_error(9, all));
	ft_new_image(all);
	return (0);
}
