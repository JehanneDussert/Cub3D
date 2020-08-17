/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:36:05 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/17 11:00:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_check_colors(char *line, int *i)
{
	int	j;
	int	comma;

	j = *i;
	comma = 2;
	while (line[j])
	{
		if (line[j] == ',')
			comma--;
		else if (((ft_isdigit(line[j])) == 0 && line[j] != ','
					&& line[j] != ' ') || comma < 0)
			return (-1);
		j++;
	}
	return (0);
}

int		ft_colors(char *line, int *color, int *i, int j)
{
	unsigned char	*tab;
	int				p_color;

	tab = (unsigned char *)color;
	if (line[*i] == 'F' || line[*i] == 'C')
		++(*i);
	while (j >= 0)
	{
		ft_jump(line, i);
		if (ft_check_colors(line, i) == -1)
			return (*color = -1);
		p_color = ft_l_atoi(line, i);
		if ((p_color > 255 || p_color < 0) || (j > 0
			&& line[(*i)++] != ',') || j < 0)
			return ((*color = -1));
		tab[j] = p_color;
		j--;
		ft_jump(line, i);
		if (j == -1 && (line[*i] != ' ' && line[*i] != '\0'))
			return (*color = -1);
	}
	tab[3] = 0;
	*i = 0;
	return (*color);
}

void	ft_def_color(char *line, t_map *map, int *i)
{
	int	j;

	j = 2;
	ft_jump(line, i);
	if (line[*i] == 'F')
		ft_colors(line, &map->f_path, i, j);
	else
		ft_colors(line, &map->c_path, i, j);
}
