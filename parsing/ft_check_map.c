/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:07:31 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/11 18:54:57 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../cub3d.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "ft_parsing.h"

void	ft_check(char *map, char *title)
{
	t_map	*info;
	char	*line;
	int		i;
	int		n;
	int		fd;

	i = 0;
	if (!(info = (t_map *)malloc(sizeof(t_map) + 1)))
		ft_error(&map, &line, &info, "[ERROR]\nProbleme d'allocation de memoire");
	if (!(map = (char *)malloc(sizeof(char) + 1)))
		ft_error(&map, &line, &info, "[ERROR]\nProbleme d'allocation de memoire.");
	ft_init(info);
	if (!(fd = open(title, O_RDONLY)))
		ft_error(&map, &line, &info, "[ERROR]\nProbleme a l'ouverture du fichier.");
	n = get_next_line(fd, &line);
	if (line == NULL)
		ft_error(&map, &line, &info, "[ERROR]\nProbleme de lecture");
	else
		ft_check_resolution(line, info, map, &i);
	ft_printf("%s\n", line);
	ft_printf("%d\n%d\n", info->reso[0], info->reso[1]);
	while (n == 1)
	{
		if (line[i] == ' ')
			ft_jump(line, &i);
		if (line[i] == 'R' && info->reso[0] == -1 && info->reso[1] == -1)
			ft_check_resolution(line, info, map, &i);
		else
			break ;
	}
}

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
