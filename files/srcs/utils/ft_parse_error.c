/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:43:45 by user42            #+#    #+#             */
/*   Updated: 2020/08/12 12:10:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_miss_info(char **line, t_map *map, int *fd)
{
	ft_free((void **)line);
	ft_parsing_error(map);
	close(*fd);
	return (-1);
}

int		ft_wrong_map(t_map *map, int *fd)
{
	if (map->map)
		ft_free_map(map);
	ft_simple_error("[ERROR] Wrong map.\n");
	close(*fd);
	return (-1);
}

int		ft_wrong_char(char **line, int *fd)
{
	ft_free((void **)line);
	close(*fd);
	ft_simple_error("[ERROR] Bad character.\n");
	return (-1);
}

t_list	*ft_ret_lst(char **line, char **clean_line, t_list *lst)
{
	ft_free((void **)line);
	ft_free((void **)clean_line);
	return (lst);
}

char	*ft_end_clean_line(char **clean_line)
{
	ft_free((void **)clean_line);
	return (NULL);
}
