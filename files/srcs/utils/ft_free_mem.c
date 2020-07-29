/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:22:04 by jdussert          #+#    #+#             */
/*   Updated: 2020/07/29 15:17:01 by jdussert         ###   ########.fr       */
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
	printf("clean line end :%s\n", *clean_line);
	printf("line end :%s\n", *line);
	ft_free((void **)clean_line);
	ft_free((void **)line);
	printf("clean line end :%s\n", *clean_line);
	printf("line end :%s\n", *line);
	return (lst);
}

t_list	*ft_free_lst(char *line, char *clean_line, t_list *lst)
{
	if (lst)
		ft_lstclear(&lst, free);
	return (ft_error_map(line, clean_line));
}
