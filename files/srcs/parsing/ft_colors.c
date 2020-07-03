/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:36:05 by jdussert          #+#    #+#             */
/*   Updated: 2020/06/25 15:43:16 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			ft_colors(char *line, int *color, int *i)
{
	unsigned char	*tab;
	int				j;

	tab = (unsigned char *)color;
	j = 2;
	ft_jump(line, i);
	if (line[*i] == 'F' || line[*i] == 'C')
	{
		++(*i);
		ft_jump(line, i);
	}
	while (j >= 0)
	{
		tab[j] = ft_l_atoi(line, i);
		if (tab[j] > 255 || tab[j] < 0)
			return (-1);
		j--;
		if (line[*i] == ',')
			(*i)++;
	}
	tab[3] = 0;
	*i = 0;
	return (*color);
}
