/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:56:48 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/10 15:03:38 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

/*
int	test(void)
{
	char *tab;
	int res;

	tab = (char *)&res;
	tab[0] = 150;
	tab[1] = 255;
	tab[2] = 100;
	tab[3] = 0;
//	printf("%x", res);
	return(res);
}

void	ft_init(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	int		r;
	void	*image;
	int		width;
	int		height;
	int		*data;
	int		bits;
	int		size_l;
	int		endian;

	i = 1000;
	width = 1000;
	height = 1000;
	mlx_ptr = mlx_init();
	r = test();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "Cub3D");
	while (j++ - 250 < 250)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, j, 250, r);
		mlx_pixel_put(mlx_ptr, win_ptr, 250, j, r);
	}
//	mlx_key_hook(win_ptr, deal_key, (void *)0);
	image = mlx_new_image (mlx_ptr, width, height);
	data = (int *)mlx_get_data_addr (image, &bits, &size_l, &endian);
	while (i++ - 1000 < 300)
		data[500*i+500] = 0xAC9EF0;
	data[500*1000+500+1] = 0xAC9EF0;
	data[500*1000+500+2] = 0xAC9EF0;
	data[500*1000+500+3] = 0xAC9EF0;

	mlx_put_image_to_window(mlx_ptr, win_ptr, image, 0, 0);
//	while (i++ - 1000 < 50)
		//mlx_get_color_value (mlx_ptr, r);
	mlx_loop(mlx_ptr);
}*/

int			ft_error(t_all *all, int res)
{
	if (all->image)
	{
		free(all->image);
		all->image = NULL;
	}
	if (all->pos)
	{
		free(all->pos);
		all->pos = NULL;
	}
	if (all->data)
	{
		free(all->data);
		all->data = NULL;
	}
	return (res);
}

t_all		*ft_init(t_all *all)
{
	if (!(all->image = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	if (!(all->pos = (t_pos *)malloc(sizeof(t_pos))))
		return (NULL);
	if (!(all->data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	all->pos->x = 0;
	all->pos->y = 0;
	all->image->width = 1000;
	all->image->height = 1000;
	all->image->title = "cub3d";
	if (!(all->image->mlx_ptr = mlx_init()))
		return (NULL);
	if (!(all->image->win_ptr = mlx_new_window(all->image->mlx_ptr,
		all->image->width, all->image->height, all->image->title)))
		return (NULL);
	if (!(all->image->img = mlx_new_image(all->image->mlx_ptr,
		all->image->width, all->image->height)))
		return (NULL);
	if (!(all->data->m_data = (int *)mlx_get_data_addr(all->image->img,
	&all->data->bpp, &all->data->size_l, &all->data->endian)))
		return (NULL);
	return (all);
}

int			main(void)
{
	int		i;
	t_all	*all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (-1);
	i = 1000;
	if (ft_init(all) == NULL)
		return (ft_error(all, -1));
	while (i++ - 1000 < 50)
		all->data->m_data[500 * i + 500] = 0xAC9EF0;
	if (!(mlx_put_image_to_window(all->image->mlx_ptr, all->image->win_ptr,
		all->image->img, all->pos->x, all->pos->y)))
		return (ft_error(all, -1));
	if (!(mlx_loop(all->image->mlx_ptr)))
		return (ft_error(all, -1));
	return (0);
}
