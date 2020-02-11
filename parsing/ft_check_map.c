/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:07:31 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/11 18:38:28 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../cub3d.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "ft_parsing.h"

int		ft_check_info(char *line, int reso, int *i)
{
	if (line[*i] == ' ')
		ft_jump(line, i);
	if (line[*i] == 'R')
	{
		++(*i);
		ft_jump(line, i);
	}
	if (line[*i] >= '0' && line[*i] <= '9')
	{
		reso = ft_l_atoi(line, i);
		if (ft_int_len(reso, 10) == 4)
			return (reso);
	}
	return (-1);
}

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
	{
		info->reso[0] = ft_check_info(line, info->reso[0], &i);
		info->reso[1] = ft_check_info(line, info->reso[1], &i);
	}
	ft_printf("%s\n", line);
	ft_printf("%d\n%d\n", info->reso[0], info->reso[1]);
	while (n == 1)
	{
		if (line[i] == ' ')
			ft_jump(line, &i);
		if (line[i] == 'R' && info->reso[0] == -1 && info->reso[1] == -1)
		{
			if (!(ft_check_info(line, info->reso[0], &i)))
				ft_error(&map, &line, &info, "[ERROR]\nWrong resolution.");
			if (!(ft_check_info(line, info->reso[1], &i)))
				ft_error(&map, &line, &info, "[ERROR]\nWrong resolution.");
			else
				break ;
		}
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
