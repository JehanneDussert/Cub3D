/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:07:31 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/11 17:42:54 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../cub3d.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

void	ft_init(t_map *info)
{
	info->reso[0] = -1;
	info->reso[1] = -1;
	info->n_path = NULL;
	info->s_path = NULL;
	info->w_path = NULL;
	info->e_path = NULL;
	info->spr_path = NULL;
	info->f_path = NULL;
	info->c_path = NULL;
}

char	*ft_error(char **map, char **line, t_map **info, char *message)
{
	if (*map)
	{
		free(*map);
		*map = NULL;
	}
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	if (*info)
	{
		free(*info);
		*info = NULL;
	}
	return (message);
}

void	ft_jump(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
}

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
