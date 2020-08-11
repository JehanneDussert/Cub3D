/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:35:30 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/06 12:49:24 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_clean_line(char *line, char *ori, int map_l)
{
	char	*clean_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(clean_line = (char *)malloc(sizeof(char) * (map_l + 1))))
		return (NULL);
	while (line[i])
	{
		while (line[i] == ' ')
			ft_replace_space(clean_line, &i, &j);
		if (ft_check_map_char(line, i) != 0)
		{
			if (ft_check_map_char(line, i) == 2 && *ori == '1')
				*ori = line[i];
			else if (ft_check_map_char(line, i) == 2 && *ori != '1')
			{
				ft_free((void **)&clean_line);
				return (NULL);
			}
			clean_line[j] = line[i];
			j++;
		}
		else
		{
			if (clean_line)
				ft_free((void **)&clean_line);
			return (NULL);
		}
		i++;
	}
	clean_line[j] = '\0';
	return (clean_line);
}

t_list	*ft_new_line(t_list *lst, char *clean_line, int mode)
{
	t_list	*tmp;

	if (ft_check_map_errors(clean_line, mode) == 0)
	{
		ft_lstclear(&lst, free);
		return (NULL);
	}
	if ((tmp = ft_lstnew(clean_line)) == NULL)
		return (NULL);
	ft_lstadd_back(&lst, tmp);
	return (lst);
}

t_list	*ft_list(char **line, int n, int *fd, t_map *map)
{
	t_list	*lst;
	char	*clean_line;

	lst = NULL;
	while (n == 0 || n == 1)
	{
		if (ft_len(*line, map) == -1 || (clean_line =
		ft_clean_line(*line, &map->ori, map->map_l)) == NULL)
		{
			ft_lstclear(&lst, free);
			break ;
		}
		if (ft_len(*line, map) < 3 && clean_line[0] == '\0')
		{
			ft_free((void **)line);
			ft_free((void **)&clean_line);
			return (lst);
		}
		if ((lst = ft_new_line(lst, clean_line, (lst == NULL ? 0 : 1))) == NULL)
		{

			ft_free((void **)&clean_line);
			break ;
		}
		if (lst != NULL && n == 0 && ft_check_map_errors(clean_line, 0) == 1)
		{
			ft_simple_error("[ERROR] Wrong map.\n");
			break ;
		}
		ft_free((void **)line);
		n = get_next_line(*fd, line);
	}
	ft_free((void **)line);
	return (lst);
}

char	**ft_create_map(t_map *map, t_list *lst, int len)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if ((map->map = ft_calloc(len + 1, sizeof(char *))) == NULL)
		return (NULL);
	while (lst)
	{
		tmp = lst;
		if ((i + 1) == len)
		{
			if (ft_check_map_errors(lst->content, 0) != 1)
				return (NULL);
		}
		map->map[i] = ft_substr(lst->content, 0, map->map_l + 1);
		lst = lst->next;
		if (lst != NULL)
		{
			if (ft_check_len(lst->content, tmp->content) != 1)
				return (NULL);
		}
		else if (map->ori == 1)
			return (NULL);
		i++;
	}
	return (map->map);
}

char	**ft_map(t_map *map, char **line, int n, int *fd)
{
	t_list	*lst;

	if ((lst = ft_list(line, n, fd, map)) == NULL)
		ft_lstclear(&lst, free);	
	map->len_y = ft_lstsize(lst);
	if ((lst && !(map->map = ft_create_map(map, lst, map->len_y))) || (map->ori == '1' && map->map))
	{
		ft_free((void **)line);
		ft_lstclear(&lst, free);
		return (NULL);
	}
	ft_lstclear(&lst, free);
	close(*fd);
	if (map->map != NULL)
		return (ft_check_pos(map, map->map) != NULL ? map->map : NULL);
	return (NULL);
}
