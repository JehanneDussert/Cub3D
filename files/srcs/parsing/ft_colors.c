/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:36:05 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/12 09:50:17 by user42           ###   ########.fr       */
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

		if (((ft_isdigit(line[j])) == 0 && line[j] != ',') || comma < 0)
			return (-1);
		else if (line[j] == ',')
			comma--;
		j++;
	}
	return (0);
}

int		ft_colors(char *line, int *color, int *i)
{
	unsigned char	*tab;
	int				j;
	int				p_color;

	tab = (unsigned char *)color;
	j = 2;
	ft_jump(line, i);
	if (line[*i] == 'F' || line[*i] == 'C')
		++(*i);
	while (j >= 0)
	{
		ft_jump(line, i);
		if (ft_check_colors(line, i) == -1)
			return (-1);
		p_color = ft_l_atoi(line, i);
		ft_jump(line, i);
		if ((p_color > 255 || p_color < 0) || (j > 0
			&& line[(*i)++] != ','))
			return ((*color = -1));
		tab[j] = p_color;
		j--;
	}
	tab[3] = 0;
	*i = 0;
	return (*color);
}

void	ft_def_color(char *line, t_map *map, int *i)
{
	ft_jump(line, i);
	if (line[*i] == 'F')
	{
		if (ft_colors(line, &map->f_path, i) == -1)
			ft_simple_error("[ERROR] Wrong floor color.\n");
	}
	else
	{
		if (ft_colors(line, &map->c_path, i) == -1)
			ft_simple_error("[ERROR] Wrong ceil color.\n");
	}
}
