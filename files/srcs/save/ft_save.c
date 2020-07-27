/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:03:43 by jdussert          #+#    #+#             */
/*   Updated: 2020/07/27 12:21:57 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_init_save(t_all *all, t_save *save)
{
	save->size = 54 + 4 * all->map->reso[0] * all->map->reso[1];
	save->unused = 0;
	save->offset_begin = 54;
	save->header_bytes = 40;
	save->plane = 1;
	save->bpp = 32;
	save->fd = open("img.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	if (save->fd == -1)
		return (ft_error(14, all));
	return (0);
}

void	ft_write_text_bmp_file(t_all *all, int fd)
{
	int	x;
	int	y;
	int	line;

	y = 0;
	while (y < all->map->reso[1])
	{
		x = 0;
		line = all->map->reso[0] * (all->map->reso[1] - y);
		printf("data b:%s\n", all->image->data);
		while (x < all->map->reso[0])
		{
			write(fd, &all->image->data[line * 4] , 4);
			line++;
			x++;
		}
		y++;
	}
	printf("data a:%s\n", all->image->data);
}

void    ft_write_bmp_file(t_all *all)
{
	t_save	save;

	ft_init_save(all, &save);
	write(save.fd, "BM", 2);
	write(save.fd, &save.size, sizeof(int));
	write(save.fd, &save.unused, sizeof(int));
	write(save.fd, &save.offset_begin, sizeof(int));
	write(save.fd, &save.header_bytes, sizeof(int));
	write(save.fd, &all->map->reso[0], sizeof(int));
	write(save.fd, &all->map->reso[1], sizeof(int));
	write(save.fd, &save.plane, sizeof(short int));
	write(save.fd, &save.bpp, sizeof(short int));
	write(save.fd, &save.unused, sizeof(int));
	write(save.fd, &save.unused, sizeof(int));
	write(save.fd, &save.unused, sizeof(int));
	write(save.fd, &save.unused, sizeof(int));
	write(save.fd, &save.unused, sizeof(int));
	write(save.fd, &save.unused, sizeof(int));
	ft_write_text_bmp_file(all, save.fd);
	close(save.fd);
}

int		ft_save(t_all *all)
{
	t_text  text[6];
	
	if ((all->image->mlx_ptr = mlx_init()) == NULL)
		return (ft_error(7, all));
	if ((all->image->win_ptr = mlx_new_window(all->image->mlx_ptr,
		all->map->reso[0], all->map->reso[1], "Save")) == NULL)
		return (ft_error(7, all));
	if (ft_init_texture(all, text, 64, 64) != 0)
		return (ft_error(13, all));
	if (ft_keydeal(all) != 0)
		return (ft_error(7, all));
	ft_write_bmp_file(all);
	ft_killwindow(all);
	return (0);
}
