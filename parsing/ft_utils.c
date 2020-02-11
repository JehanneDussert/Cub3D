/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:27:33 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/11 18:36:18 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../cub3d.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "ft_parsing.h"

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
