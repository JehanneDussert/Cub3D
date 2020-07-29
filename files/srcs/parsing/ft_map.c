/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:35:30 by jdussert          #+#    #+#             */
/*   Updated: 2020/07/29 18:16:38 by jdussert         ###   ########.fr       */
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
		if (ft_check_char(line, i) == 1 || ft_check_char(line, i) == 2)
		{
			if (ft_check_char(line, i) == 2)
				*ori = line[i];
			clean_line[j] = line[i];
			j++;
		}
		else
			return (NULL);
		i++;
	}
	clean_line[j] = '\0';
	return (clean_line);
}

t_list	*ft_new_line(t_list *lst, char *clean_line, int mode)
{
	t_list	*tmp;

	if (ft_check_map_errors(clean_line, mode) == 0)
		return (NULL);
		// Attention au malloc qui crash ?
	if ((tmp = ft_lstnew(clean_line)) == NULL)
		return (NULL);
	ft_lstadd_back(&lst, tmp);
	return (lst);
}

t_list	*ft_list(char **line, int n, int fd, t_all *all)
{
	t_list	*lst;
	char	*clean_line;

	lst = NULL;
	while (n == 1 || n == 0)
	{
		if (ft_len(*line, all) == -1 || (clean_line =
		ft_clean_line(*line, &all->map->ori, all->map->map_l)) == NULL)
			return (ft_error_map(*line, clean_line));
		if (ft_len(*line, all) < 3 && clean_line[0] == '\0')
			return (ft_end_map(line, &clean_line, lst));
		if (ft_nb_spr(all, clean_line, all->map->len_y++) == -1)
			return (ft_error_map(*line, clean_line));
		if ((lst = ft_new_line(lst, clean_line, (lst == NULL ? 0 : 1))) == NULL)
			return (ft_free_lst(*line, clean_line, lst));
		if (lst != NULL && n == 0 && ft_check_map_errors(clean_line, 0) == 1)
			return (ft_end_map(line, &clean_line, lst));
		ft_free((void **)line);
		n = get_next_line(fd, line);
	}
	return (ft_check_map_errors(*line, 1) == 1 ? lst : NULL);
}

char	**ft_create_map(t_all *all, t_list *lst, int len)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if ((all->map->map = ft_calloc(len + 1, sizeof(*all->map->map))) == NULL)
		return (NULL);
	while (lst)
	{
		tmp = lst;
		if ((i + 1) == len)
		{
			if (ft_check_map_errors(lst->content, 0) != 1)
				return (NULL);
		}
		all->map->map[i] = ft_substr(lst->content, 0, all->map->map_l + 1);
		lst = lst->next;
		if (lst != NULL)
		{
			if (ft_check_len(lst->content, tmp->content) != 1)
				return (NULL);
		}
		i++;
	}
	return (all->map->map);
}

char	**ft_map(char *line, int n, int fd, t_all *all)
{
	t_list	*lst;
	int		len;

	if ((lst = ft_list(&line, n, fd, all)) == NULL)
		return (NULL);
	len = ft_lstsize(lst);
	ft_create_map(all, lst, len);
	if (lst)
		ft_lstclear(&lst, free);
	return (ft_check_pos(all->map, all->map->map) != NULL ?
		all->map->map : NULL);
}
