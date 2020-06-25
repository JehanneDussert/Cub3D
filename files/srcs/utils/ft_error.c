/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:34:14 by jdussert          #+#    #+#             */
/*   Updated: 2020/06/25 15:49:09 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_free_all(t_all **all)
{
    if (*all)
    {
        free (*all);
        *all = NULL;
    }
}

int     ft_error(int msg, t_all *all)
{
    if (msg == 0)
        ft_putstr_fd("[ERROR]\nInvalid file.", 0);
    else if (msg == 1)
        ft_putstr_fd("[ERROR]\nWrong argument.", 0);
    else if (msg == 2)
        ft_putstr_fd("[ERROR]\nMemory allocation.", 0);
    else if (msg == 3)
        ft_putstr_fd("[ERROR]\nParsing error.", 0);
    else if (msg == 4)
        ft_putstr_fd("[ERROR]\nRaycasting error.", 0);
    else if (msg == 5)
        ft_putstr_fd("[ERROR]\nFile opening problem.", 0);
    else if (msg == 6)
        ft_putstr_fd("[ERROR]\nWrong resolution.", 0);
    else if (msg == 7)
        ft_putstr_fd("[ERROR]\nMlx failed.", 0);
    else if (msg == 8)
        ft_putstr_fd("[ERROR]\nWrong texture.", 0);
    else if (msg == 9)
        ft_putstr_fd("[ERROR]\nMovement error.", 0);
    else if (msg == 10)
        ft_putstr_fd("[ERROR]\nWrong map.", 0);
    else if (msg == 11)
        ft_putstr_fd("[ERROR]\nToo much sprites.", 0);
    else if (msg == 12)
        ft_putstr_fd("[ERROR]\nWrong colors.", 0);
    ft_killwindow(all);
    return (1);
}
