/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:37:41 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/11 14:30:01 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_abs(double nb)
{
	if (nb < 0)
	{
		nb *= -1;
		return ((int)(nb));
	}
	return ((int)nb);
}

int		ft_degre_to_rad(int deg)
{
	int res;

	res = deg * 3.14 / 180;
	return (res);
}

// On arrondi
int		ft_rounded_down(float f)
{
	int res;

	res = ((float)((int) f * 100)) / 100;
	return (res);
}

// Racine carree
int		ft_sqrt(int nb)
{
	int	sqrt;

	if (nb < 0)
		return (0);
	sqrt = 1;
	while (sqrt * sqrt < nb)
		++sqrt;
	if (sqrt * sqrt == nb)
		return (sqrt);
	return (0);
}

// Calcul de tangente
int		ft_tan(int angle)
{
	int	res;

	if (angle == 30)
		res = (1 / ft_sqrt(3));
	else if (angle == 60)
		res = ft_sqrt(3);
	return (-1);
}

double	ft_def_angle(char ori, t_player *player)
{
	if (ori == 'E')
	{
		player->dir[0] = 1;
		player->dir[1] = 0;
		return (0);
	}
	else if (ori == 'N')
	{
		player->dir[0] = 0;
		player->dir[1] = -1;
		return (90);
	}
	else if (ori == 'W')
	{
		player->dir[0] = -1;
		player->dir[1] = 0;
		return (180);
	}
	else if (ori == 'S')
	{
		player->dir[0] = 0;
		player->dir[1] = 1;
		return (270);
	}
	return (-1);
}
