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

int main(int argc, char **argv)
{
	t_all	*all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
        return (ft_error(2, all));
	if (argc > 1 && argc < 4)
	{
		if (ft_last(argv[1], ".cub") != 1)
			return (ft_error(0, all));
		if (argc == 3 && !(ft_strncmp(argv[2], "-save", 5)))
			return (ft_error(1, all));
		if (!(all = ft_init_all(all)))
			return (ft_error(2, all));
		all->image->title = argv[1];
		if (!(all->map = ft_parsing(all, all->image->title)))
			return (ft_error(3, all));
		if (!(all = ft_raycasting(all)))
			return (ft_error(4, all));
		while (1)
		{
			if (!(mlx_hook(all->image->win_ptr, 2, 0, &keyPress, &all->image)))
				return (ft_error(4, all));
			printf("keyPress ok\n");
    		if (!(mlx_hook(all->image->win_ptr, 3, 0, &keyRelease, &all->image)))
				return (ft_error(4, all));
			printf("keyRelease ok\n");
    		if (!(mlx_hook(all->image->win_ptr, 17, 0, &KillWindow, &all->image)))
				return (ft_error(4, all));
			printf("killWindow ok\n");
    		if (!(mlx_loop_hook(all->image->mlx_ptr, &keyDeal, &all->image)))
				return (ft_error(4, all));
			printf("keyDeal ok\n");
    		if (!(mlx_loop(all->image->mlx_ptr)))
				return (ft_error(4, all));
			printf("loop ok\n");
		}
	}
	return (0);
}
