/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:36:05 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/05 12:14:47 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			ft_colors(char *line, int *color, int *i)
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
		if (ft_isdigit(line[*i]) == 0)
			return (-1);
		p_color = ft_l_atoi(line, i);
		ft_jump(line, i);
		if ((p_color > 255 || p_color < 0) || (j > 0
			&& line[(*i)++] != ','))
			return (-1);
		tab[j] = p_color;
		j--;
	}
	tab[3] = 0;
	*i = 0;
	return (-1);
}
