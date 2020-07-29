/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:22:04 by jdussert          #+#    #+#             */
/*   Updated: 2020/07/29 18:54:09 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_list	*ft_error_map(char *line, char *clean_line)
{
	ft_free((void **)&clean_line);
	ft_free((void **)&line);
	return (NULL);
}

t_list	*ft_end_map(char **line, char **clean_line, t_list *lst)
{
	ft_free((void **)clean_line);
	ft_free((void **)line);
	return (lst);
}

t_list	*ft_free_lst(char *line, char *clean_line, t_list *lst)
{
	ft_lstclear(&lst, free);
	return (ft_error_map(line, clean_line));
}

t_map	*ft_free_line(char *line, int *i)
{
/* Double free ? */
	ft_free((void **)&line);
	*i = 0;
	return (NULL);
}
