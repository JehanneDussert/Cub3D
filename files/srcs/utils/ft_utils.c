/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:27:33 by jdussert          #+#    #+#             */
/*   Updated: 2020/06/25 17:22:34 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_replace_space(char *str, int *i, int *j)
{
	str[*i] = '1';
	(*i)++;
	(*j)++;
}

void	ft_jump(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
}

int		ft_l_atoi(const char *str, int *i)
{
	unsigned int	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = (result * 10) + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}
