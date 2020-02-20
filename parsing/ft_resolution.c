/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:47:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/20 14:14:24 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_info(char *line, int *reso, int *i)
{
	if (line[*i] == ' ')
		ft_jump(line, i);
	if (line[*i] == 'R')
	{
		++(*i);
		ft_jump(line, i);
	}
	if (line[*i] >= '0' && line[*i] <= '9')
		*reso = ft_l_atoi(line, i);
	return (*reso);
}

void	ft_check_resolution(char *line, t_map *info, char *map, int *i)
{
	if (!(ft_check_info(line, &info->reso[0], i)))
		ft_error(&map, &line, &info, "[ERROR]\nWrong resolution.");
	if (!(ft_check_info(line, &info->reso[1], i)))
		ft_error(&map, &line, &info, "[ERROR]\nWrong resolution.");
	*i = 0;
}
