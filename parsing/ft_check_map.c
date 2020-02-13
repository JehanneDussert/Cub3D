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

void	ft_check(char *map, char *title)
{
	t_map	*info;
	t_image	*image;
	char	*line;
	int		i;
	int		n;
	int		fd;
	
	i = 0;
	if (!(info = (t_map *)malloc(sizeof(t_map) + 1)))
		ft_error(&map, &line, &info, &image, "[ERROR]\nProbleme d'allocation de memoire");
	if (!(map = (char *)malloc(sizeof(char) + 1)))
		ft_error(&map, &line, &info, &image, "[ERROR]\nProbleme d'allocation de memoire.");
	if (!(image = (t_image *)malloc(sizeof(t_image) + 1)))
		ft_error(&map, &line, &info, &image, "[ERROR]\nProbleme d'allocation de memoire");
	ft_init(info);
	if (!(fd = open(title, O_RDONLY)))
		ft_error(&map, &line, &info, &image, "[ERROR]\nProbleme a l'ouverture du fichier.");
	n = get_next_line(fd, &line);
	if (line == NULL)
		ft_error(&map, &line, &info, &image, "[ERROR]\nProbleme de lecture");
	else
		ft_check_resolution(line, info, image, map, &i);
	ft_printf("%s\n", line);
	ft_printf("Reso 1 :%d\nReso 2 :%d\n", info->reso[0], info->reso[1]);
	while (n == 1)
	{
		ft_jump(line, &i);
		if (line[i] == 'R' && info->reso[0] == -1 && info->reso[1] == -1)
			ft_check_resolution(line, info, image, map, &i);	
		else if ((line[i] == 'F' && info->f_path == -1) || (line[i] == 'C' && info->c_path == -1))
			line[i] == 'F' ? ft_colors(line, &info->f_path, &i) : ft_colors(line, &info->c_path, &i);
		else if (ft_strncmp(&line[i], "NO", 2) || ft_strncmp(&line[i], "SO", 2)
				|| ft_strncmp(&line[i], "WE", 2) || ft_strncmp(&line[i], "EA", 2) || ft_strncmp(&line[i], "S", 1))
			ft_text(line, info, image, &i);
		n = get_next_line(fd, &line);
		/*else
			break ;*/
	}
}
