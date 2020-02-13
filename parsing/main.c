/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:33:56 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/13 14:29:27 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		main(int argc, char **argv)
{
	char	*map = NULL;

	if (argc > 1 && argc < 4)
	{
		if (ft_last(argv[1], ".cub") != 1)
		{
			ft_printf("[ERROR]\nWrong filename.");
			return (-1);
		}
		if (argc == 3 && !(ft_strncmp(argv[2], "-save", 5)))
		{
			ft_printf("[ERROR]\nWrong argument.");
			return (-1);
		}
		ft_check(map, argv[1]);
	}
	return (0);
}
