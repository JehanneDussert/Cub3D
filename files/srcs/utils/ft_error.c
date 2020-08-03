/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/03 15:06:38 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_file_prbl(int msg)
{
	if (msg == 0)
		ft_putstr_fd("[ERROR]\nInvalid file.\n", 1);
	else if (msg == 5)
		ft_putstr_fd("[ERROR]\nFile opening problem.\n", 1);
	else if (msg == 6)
		ft_putstr_fd("[ERROR]\nWrong resolution.\n", 1);
	else if (msg == 8)
		ft_putstr_fd("[ERROR]\nWrong texture.\n", 1);
	else if (msg == 10)
		ft_putstr_fd("[ERROR]\nWrong map.\n", 1);
	else if (msg == 12)
		ft_putstr_fd("[ERROR]\nWrong colors.\n", 1);
}

int		ft_error(int msg, t_all *all)
{
	if (msg == 0 || msg == 5 || msg == 6 || msg == 8 || msg == 10 || msg == 12)
		ft_file_prbl(msg);
	else if (msg == 1)
		ft_putstr_fd("[ERROR]\nWrong argument.\n", 1);
	else if (msg == 2)
		ft_putstr_fd("[ERROR]\nMemory allocation.\n", 1);
	else if (msg == 3)
		ft_putstr_fd("[ERROR]\nParsing error.\n", 1);
	else if (msg == 4)
		ft_putstr_fd("[ERROR]\nRaycasting error.\n", 1);
	else if (msg == 7)
		ft_putstr_fd("[ERROR]\nMlx failed.\n", 1);
	else if (msg == 9)
		ft_putstr_fd("[ERROR]\nMovement error.\n", 1);
	else if (msg == 11)
		ft_putstr_fd("[ERROR]\nToo much sprites.\n", 1);
	else if (msg == 13)
		ft_putstr_fd("[ERROR]\nTextures initialisation failed.\n", 1);
	else if (msg == 14)
		ft_putstr_fd("[ERROR]\nOpening .bmp file failed.\n", 1);
	else if (msg == 15)
		ft_putstr_fd("[ERROR]\nInvalid character.\n", 1);
	ft_killwindow(all);
	return (1);
}
