/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:13:09 by jdussert          #+#    #+#             */
/*   Updated: 2020/01/31 15:18:16 by jdussert         ###   ########.fr       */
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

int		ft_error(t_image *image, t_pos *pos, t_data *data, int res)
{
	if(image)
	{
		free(image);
		image = NULL;
	}
	if(pos)
	{
		free(pos);
		pos = NULL;
	}
	if (data)
	{
		free(data);
		data = NULL;
	}
	return(res);
}

int		ft_init(t_image *image, t_pos *pos, t_data *data)
{
	pos->x = 0;
	pos->y = 0;
	image->width = 1000;
	image->height = 1000;
	image->title = "cub3d";
	if(!(image->mlx_ptr = mlx_init()))
		return(ft_error(image, pos, data, -1));
	if(!(image->win_ptr = mlx_new_window(image->mlx_ptr, image->width, image->height, image->title)))
		return(ft_error(image, pos, data, -1));
	if(!(image->img = mlx_new_image(image->mlx_ptr, image->width, image->height)))
		return(ft_error(image, pos, data, -1));
	if(!(data->m_data = (int *)mlx_get_data_addr(image->img, &data->bpp, &data->size_l, &data->endian)))
		return(ft_error(image, pos, data, -1));
	return(1);
}

int	main(void)
{
	t_image		*image;
	t_data		*data;
	t_pos		*pos;
	int			i;

	i = 1000;
	if(!(image = (t_image *)malloc(sizeof(t_image))))
		return(-1);
	if(!(pos = (t_pos *)malloc(sizeof(t_pos))))
		return(ft_error(image, pos, data, -1));
	if(!(data = (t_data *)malloc(sizeof(t_data))))
		return(ft_error(image, pos, data, -1));
	ft_init(image, pos, data);
	while(i++ - 1000 < 50)
		data->m_data[500*i+500] = 0xAC9EF0;
	if(!(mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->img, pos->x, pos->y)))
		return(ft_error(image, pos, data, -1));
	if(!(mlx_loop(image->mlx_ptr)))
		return(ft_error(image, pos, data, -1));
	return(0);
}
