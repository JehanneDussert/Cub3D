/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:36:05 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/04 17:04:19 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_clean_color(char *line, int *i)
{
	ft_jump(line, i);
	if (line[*i] == ',')
		(*i)++;
	ft_jump(line, i);
}

int			ft_colors(char *line, int *color, int *i)
{
	unsigned char	*tab;
	int				j;

	tab = (unsigned char *)color;
	j = 2;
	ft_jump(line, i);
	if (line[*i] == 'F' || line[*i] == 'C')
		++(*i);
	while (j >= 0)
	{
		ft_jump(line, i);
		if (ft_isdigit(line[*i]) == 0)
			return (-1);
		ft_jump(line, i);
		tab[j] = ft_l_atoi(line, i);
		ft_jump(line, i);
		if ((tab[j] > 255 || tab[j] < 0) || (j > 0
			&& line[*i] != ','))
			return (-1);
		j--;
		ft_clean_color(line, i);
	}
	tab[3] = 0;
	*i = 0;
	return (*color);
}
