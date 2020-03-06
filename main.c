/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:33:56 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/06 13:05:20 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		main(int argc, char **argv)
{
	char	*map;
	t_image	*image;
	t_map	*info;

	map = NULL;
	info = NULL;
	if (!(image = (t_image *)malloc(sizeof(t_image))))
		return (-1);
	if (argc > 1 && argc < 4)
	{
		if (ft_last(argv[1], ".cub") != 1)
		{
			ft_printf("[ERROR]\nWrong filename.");
			return (-1);
		}
		else
			image->title = argv[1];
		if (argc == 3 && !(ft_strncmp(argv[2], "-save", 5)))
		{
			ft_printf("[ERROR]\nWrong argument.");
			return (-1);
		}
		info = ft_check(map, image->title);
		ft_loop(info, image);
	}
	return (0);
}
