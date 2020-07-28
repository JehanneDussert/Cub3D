/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:22:04 by jdussert          #+#    #+#             */
/*   Updated: 2020/07/28 18:33:34 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_list	*ft_break_map(char *line, char *clean_line)
{
	ft_free((void **)&line);
	ft_free((void **)&clean_line);
	return (NULL);
}
