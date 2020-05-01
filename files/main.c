/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:33:56 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/12 17:28:22 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_start(t_all *all, char **argv, int save)
{
	(void)save;
	if (!(all = ft_init_all(all)))
		return (ft_error(2, all));
	all->image->title = argv[1];
	if (!(all->map = ft_parsing(all, all->image->title)))
		return (ft_error(3, all));
	if (!(all = ft_def_dir_plane(all)))
		return (-1);
	if (!(all->image->mlx_ptr = mlx_init()))
		return (ft_error(7, all));
	if (!(all->image->win_ptr = mlx_new_window(all->image->mlx_ptr,
		all->map->reso[0], all->map->reso[1], all->image->title)))
		return (ft_error(7, all));
	if (!(mlx_hook(all->image->win_ptr, 2, 1, ft_keypress, all)))
		return (ft_error(4, all));
	if (!(mlx_hook(all->image->win_ptr, 3, 2, ft_keyrelease, all)))
		return (ft_error(4, all));
	if (!(mlx_hook(all->image->win_ptr, 17, 0, ft_killwindow, all)))
		return (ft_error(4, all));
	mlx_loop_hook(all->image->mlx_ptr, ft_keydeal, all);
	if (!(mlx_loop(all->image->mlx_ptr)))
		return (ft_error(4, all));
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	int		save;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (ft_error(2, all));
	save = -1;
	if (argc > 1 && argc < 4)
	{
		if (ft_last(argv[1], ".cub") != 1)
			return (ft_error(0, all));
		if (argc == 3 && !(ft_strncmp(argv[2], "--save", 7)))
			return (ft_error(1, all));
		else
			save = 1;
	}
	if (argc == 2 || (argc == 3 && save == 1))
		ft_start(all, argv, save);
	return (0);
}