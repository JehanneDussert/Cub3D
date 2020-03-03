/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:36:05 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/21 11:57:09 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		j--;
		if (line[*i] == ',')
			(*i)++;
	}
	tab[3] = 0;
	*i = 0;
	return (*color);
}
