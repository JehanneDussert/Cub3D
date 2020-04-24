/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:00:44 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/12 16:39:16 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_check_existence(t_map *map, char *line, int *i, int mode)
{
	if (mode == 0)
	{
		if ((line[*i] == 'R' && (map->reso[0] != -1 || map->reso[1] != -1)) ||
		(line[*i] == 'F' && map->f_path != -1) || (line[*i] == 'C'
		&& map->c_path != -1) || (ft_first(line, "NO") == 1 && map->n_path
		!= NULL) || (ft_first(line, "SO") == 1 && map->s_path != NULL) ||
		(ft_first(line, "WE") == 1 && map->w_path != NULL) ||
		(ft_first(line, "EA") == 1 && map->e_path != NULL) ||
		(ft_first(line, "S") == 1 && map->spr_path != NULL))
			return (1);
	}
	else if (mode == 1)
	{
		if (map->reso[0] != -1 && map->reso[1] != -1 && map->f_path != -1 &&
		map->c_path != -1 && map->n_path != NULL && map->s_path != NULL &&
		map->spr_path != NULL && map->w_path != NULL && map->e_path != NULL)
			return (1);
	}
	return (0);
}

t_map	*ft_parsing(t_all *all, char *title)
{
	char	*line;
	int		n;
	int		i;
	int		fd;

	i = 0;
	if (!(fd = open(title, O_RDONLY)))
		exit(ft_error(5, all));
	if (!(line = (char *)malloc(sizeof(2))))
		exit(ft_error(2, all));
	while ((n = get_next_line(fd, &line)) == 1 && line[i] != '1')
	{
		if ((line[i] == '\0' && n < 0) || line == NULL)
			exit(ft_error(0, all));
		line = ft_strtrim(line, " ");
		if (ft_check_existence(all->map, line, &i, 0) == 1)
			exit(ft_error(0, all));
		else if (line[i] == 'R' && all->map->reso[0] == -1 && all->map->reso[1] == -1)
		{
			if (ft_check_resolution(line, all->map, &i) == -1)
				exit(ft_error(6, all));
		}
		else if ((line[i] == 'F' && all->map->f_path == -1) || (line[i] == 'C'
		&& all->map->c_path == -1))
			line[i] == 'F' ? ft_colors(line, &all->map->f_path, &i) :
			ft_colors(line, &all->map->c_path, &i);
		else if (ft_check_text(line, i) == 1)
			ft_text(line, all->map);
		free(line);
		line = NULL;
		i = 0;
	}
	if ((ft_check_existence(all->map, line, &i, 1) == 1) &&
	n == 1 && line[0] == '1')
		all->map->map = ft_map(line, n, fd, all->map);
	else
		exit(ft_error(0, all));
	ft_print(all);
	return (all->map);
}

void	ft_print(t_all *all)
{
	printf("Resolution : %d %d\n", all->map->reso[0], all->map->reso[1]);
	printf("My floor :%d\n", all->map->f_path);
	printf("My ceiling :%d\n", all->map->c_path);
	printf("My n_path :%s\n", all->map->n_path);
	printf("My s_path :%s\n", all->map->s_path);
	printf("My e_path :%s\n", all->map->e_path);
	printf("My w_path :%s\n", all->map->w_path);
	printf("My spr_path :%s\n", all->map->spr_path);
	printf("My ori :%c\n", all->map->ori);
//	printf("My x :%f\n", all->map->pos_x);
//	printf("My y :%f\n", all->map->pos_y);
	int i = 0;
	while (all->map->map[i])
	{
		printf("Contenu :%s\n", all->map->map[i]);
		i++;
	}
}
