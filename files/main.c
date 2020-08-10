/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:10:35 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/06 12:54:00 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_mlx(t_image *img, t_map *map)
{
	t_all		all;
	t_text		text[6];
	t_player	p;
	t_s_txt		s_txt;
	t_vec		vec;
	t_keys		keys;
	
	ft_pos_spr(map, &all);
	ft_player(&p);
	ft_vec_init(&vec);
	ft_keys_init(&keys);
	ft_def_dir_plane(map, &vec);
	ft_init(&all, &vec, &keys, &s_txt);
	ft_init_all(&all, &p, map, img);
	if ((img->mlx_ptr = mlx_init()) == NULL)
		return (ft_simple_error("Mlx init failed.\n"));
	ft_check_screen_size(img, map);
	if (!(img->win_ptr = mlx_new_window(img->mlx_ptr,
		map->reso[0], map->reso[1], "cub3D")))
		return (ft_simple_error("[ERROR] Opening new window failed.\n"));
	if (ft_init_texture(&all, text, 64, 64) != 0)
		return (ft_simple_error("[ERROR] Init textures failed.\n"));
	if (!(mlx_hook(img->win_ptr, 2, 1, ft_keypress, &keys)))
		return (ft_simple_error("[ERROR] Raycasting failed.\n"));
	if (!(mlx_hook(img->win_ptr, 3, 2, ft_keyrelease, &keys)))
		return (ft_simple_error("[ERROR] Raycasting failed.\n"));
	if (!(mlx_hook(img->win_ptr, 17, 1L<<17, ft_killwindow, &all)))
		return (ft_simple_error("[ERROR] Raycasting failed.\n"));
	mlx_loop_hook(img->mlx_ptr, ft_keydeal, &all);
	mlx_loop(img->mlx_ptr);
		//return (ft_simple_error("[ERROR] Mlx failed.\n"));
	return (1);
}

int	ft_start(t_image img, char **argv, int save)
{
	t_map	map;
	int	fd;

	ft_init_map(&map);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (ft_simple_error("[ERROR] Opening file failed.\n"));
	if (ft_parsing(&map, &fd) == -1)
		return (-1);
	if (save == 1)
		ft_save(&img, &map);
	else
		ft_mlx(&img, &map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_image	img;
	int	s;

	s = 0;
	img.mlx_ptr = 0;
	if (argc > 1 && argc < 4)
	{
		if (ft_last(argv[1], ".cub") != 1)
			return (ft_simple_error("[ERROR] Invalid file.\n"));
		if (argc == 3 && (ft_strncmp(argv[2], "--save", 5) != 0))
			return (ft_simple_error("[ERROR] Wrong arguments.\n"));
		else if (argc == 3 && ft_strncmp(argv[2], "--save", 5) == 0)
			s = 1;
	}
	if (argc == 2 || (argc == 3 && s == 1))
		ft_start(img, argv, s);
	return (0);
}
