/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:07:31 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/12 18:0:21 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_existence(t_map *info, char *line, int *i)
{
	if ((line[*i] == 'R' && (info->reso[0] != -1 || info->reso[1] != -1)) ||
	(line[*i] == 'F' && info->f_path != -1) || (line[*i] == 'C'
	&& info->c_path != -1))
		return (1);
	return (0);
}

void	ft_check(char *map, char *title)
{
	t_map	*info;
	char	*line;
	int		i;
	int		n;
	int		fd;

	i = 0;
	if (!(info = ft_init()))
		ft_error(&map, &line, &info, "Probleme d'allocation de memoire.");
	if (!(fd = open(title, O_RDONLY)))
		ft_error(&map, &line, &info, "Probleme a l'ouverture du fichier.");
	while ((n = get_next_line(fd, &line)) == 1 && line[i] != '1')
	{
		if ((line[i] == '\0' && n < 0) || line == NULL)
			ft_error(&map, &line, &info, "Fichier invalide.") ;
		line = ft_strtrim(line, " ");
		if (ft_check_existence(info, line, &i) == 1)
		{
			ft_printf("yoyo\n");
			ft_error(&map, &line, &info, "Fichier invalide.");
			break ;
		}
		else if (line[i] == 'R' && info->reso[0] == -1 && info->reso[1] == -1)
			ft_check_resolution(line, info, map, &i);
		else if ((line[i] == 'F' && info->f_path == -1) || (line[i] == 'C' && info->c_path == -1))
			line[i] == 'F' ? ft_colors(line, &info->f_path, &i) : ft_colors(line, &info->c_path, &i);
		else if (ft_check_text(line, i) == 1)
			ft_text(line, info);
		free(line);
		line = NULL;
		i = 0;
	}
	if (n == 1)
		info->map = ft_map(line, n, fd, info);
	ft_printf("Resolution : %d %d\n", info->reso[0], info->reso[1]);
	ft_printf("My floor :%d\n", info->f_path);
	ft_printf("My ceiling :%d\n", info->c_path);
	ft_printf("My n_path :%s\n", info->n_path);
	ft_printf("My s_path :%s\n", info->s_path);
	ft_printf("My e_path :%s\n", info->e_path);
	ft_printf("My w_path :%s\n", info->w_path);
	ft_printf("My spr_path :%s\n", info->spr_path);
	ft_printf("My ori :%c\n", info->ori);
	while (info->map != NULL)
	{
		ft_printf("Contenu :%s\n", info->map->content);
		info->map = info->map->next;
	}
}
