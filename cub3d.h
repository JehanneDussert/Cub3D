/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/01/30 16:56:00 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define speed = 1
# define angle = 1
# define rot_sp = 1
#include <mlx.h>
#include <unistd.h>

typedef struct	s_pos
{
	float	x;
	float	y;
}				t_pos;

typedef struct	s_cub
{
	t_pos	pos;
}				t_cub

void	ft_init(void);

#endif
/*
int main(void)
{
	t_cub *tab;
	
	tab->pos.x ???????????????????????? WTF
}*/
