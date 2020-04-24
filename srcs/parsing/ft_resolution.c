/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:47:07 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/03 12:09:39 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	ft_check_resolution(char *line, t_map *info, int *i)
{
	if (!(ft_check_info(line, &info->reso[0], i)))
		return (-1);
	if (!(ft_check_info(line, &info->reso[1], i)))
		return (-1);
	*i = 0;
	return (0);
}
