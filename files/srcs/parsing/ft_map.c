/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:35:30 by jdussert          #+#    #+#             */
/*   Updated: 2020/06/25 17:50:12 by jdussert         ###   ########.fr       */
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
		if (line[i] == ' ')
			ft_replace_space(clean_line, &j);
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

	if (mode == 0)
	{
		if (ft_check_map_errors(clean_line, 0) == 0)
			return (NULL);
		lst = ft_lstnew(clean_line);
	}
	else if (mode == 1)
	{
		if (ft_check_map_errors(clean_line, 1) == 0)
			return (NULL);
		tmp = ft_lstnew(clean_line);
		ft_lstadd_back(&lst, tmp);
	}
	return (lst);
}

int		ft_nb_spr(t_all *all, char *str, int *nb, int j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '2')
		{
			all->spr[*nb].x = (double)i + 0.5;
			all->spr[*nb].y = (double)j + 0.5;
			(*nb)++;
			all->map->spr++;
		}
		i++;
	}
	if (all->map->spr > 49)
		return (-1);
	return (1);
}

t_list	*ft_list(char *line, int n, int fd, t_all *all)
{
	t_list	*lst;
	char	*clean_line;
	int		map_len;
	int		j;
	int		nb;

	lst = NULL;
	nb = 0;
	j = 0;
	while (n == 1 || n == 0)
	{
		map_len = ft_map_len(line, &all->map->ori, &all->map->map_l);
		if (map_len > all->map->map_l)
			all->map->map_l = map_len;
		if (map_len < 3 && line == NULL)
			return (NULL);
		if ((clean_line = ft_clean_line(line, &all->map->ori,
			all->map->map_l)) == NULL)
			return (NULL);
		if (map_len < 3 && clean_line[0] == '\0')
			return (lst);
		if (ft_nb_spr(all, clean_line, &nb, j) == -1)
			return (NULL);
		if (lst == NULL)
			lst = ft_new_line(lst, clean_line, 0);
		else
		{
			lst = ft_new_line(lst, clean_line, 1);
			if (n == 0 && ft_check_map_errors(clean_line, 0) == 1)
				return (lst);
		}
		free(line);
		line = NULL;
		n = get_next_line(fd, &line);
		j++;
	}
	return (ft_check_map_errors(line, 1) == 1 ? lst : NULL);
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

	lst = ft_list(line, n, fd, all);
	len = ft_lstsize(lst);
	ft_create_map(all, lst, len);
	return (ft_check_pos(all->map, all->map->map) != NULL ?
		all->map->map : NULL);
}
