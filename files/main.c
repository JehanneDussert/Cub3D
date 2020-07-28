/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:10:35 by jdussert          #+#    #+#             */
/*   Updated: 2020/07/28 17:06:12 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_init(t_all *all)
{
	if (!(all = ft_init_all(all)))
		return (ft_error(2, all));
	return (1);
}

int	ft_mlx(t_all *all)
{
	t_text	text[6];

	if ((all->image->mlx_ptr = mlx_init()) == NULL)
		return (ft_error(7, all));
	if (!(all->image->win_ptr = mlx_new_window(all->image->mlx_ptr,
		all->map->reso[0], all->map->reso[1], "cub3D")))
		return (ft_error(7, all));
	if (ft_init_texture(all, text, 64, 64) != 0)
		return (ft_error(13, all));
	if (!(mlx_hook(all->image->win_ptr, 2, 1, ft_keypress, all)))
		return (ft_error(4, all));
	if (!(mlx_hook(all->image->win_ptr, 3, 2, ft_keyrelease, all)))
		return (ft_error(4, all));
	if (!(mlx_hook(all->image->win_ptr, 17, 0, ft_killwindow, all)))
		return (ft_error(4, all));
	mlx_loop_hook(all->image->mlx_ptr, ft_keydeal, all);
	if (!(mlx_loop(all->image->mlx_ptr)))
		return (ft_error(4, all));
	return (1);
}

int	ft_start(t_all *all, char **argv, int save)
{
	ft_init(all);
	all->image->title = argv[1];
	if (!(all->map = ft_parsing(all, all->image->title)))
		return (ft_error(3, all));
	if (!(all = ft_def_dir_plane(all)))
		return (-1);
	if (save == 1)
		ft_save(all);
	else
		ft_mlx(all);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (ft_error(2, all));
	all->s = -1;
	if (argc > 1 && argc < 4)
	{
		if (ft_last(argv[1], ".cub") != 1)
			return (ft_error(0, all));
		if (argc == 3 && (ft_strncmp(argv[2], "--save", 5) != 0))
			return (ft_error(1, all));
		else if (argc == 3 && ft_strncmp(argv[2], "--save", 5) == 0)
			all->s = 1;
	}
	if (argc == 2 || (argc == 3 && all->s == 1))
		ft_start(all, argv, all->s);
	return (0);
}
