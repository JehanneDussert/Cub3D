/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:22:04 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/03 12:05:06 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_list	*ft_error_map(char *line)
{
	ft_free((void **)&line);
	return (NULL);
}

t_list	*ft_end_map(char **line, t_list *lst)
{
	ft_free((void **)line);
	return (lst);
}

t_list	*ft_free_lst(char *line, t_list *lst)
{
	ft_lstclear(&lst, free);
	return (ft_error_map(line));
}
