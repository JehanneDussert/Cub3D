/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:35:30 by jdussert          #+#    #+#             */
/*   Updated: 2020/06/18 16:59:04 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#include "../../includes/cub3d.h"

t_map	*ft_check_pos(t_map *info, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_check_char(map[i], j) == 2)
			{
				info->pos_x = (double)j + 0.5;
				info->pos_y = (double)i + 0.5;
				return (info);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

int		ft_check_map_errors(char *line, int mode)
{
	int	i;

	i = 0;
	if (mode == 0)
	{
		while (line[i])
		{
			if (line[i] != '1' && line[i] != ' ')
				return (0);
			i++;
		}
	}
	else if (mode == 1)
	{
		if ((line[0] != '1' && line[0] != ' ') || line[ft_strlen(line) - 1] != '1')
			return (0);
	}
	return (1);
}

int		ft_map_len(char *line, char *ori, int *map_l)
{
	int	i;
	int	map_len;

	i = 0;
	map_len = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (ft_check_char(line, i) == 1 || ft_check_char(line, i) == 2)
		{
			if (*ori != '1' && ft_check_char(line, i) == 2)
				return (-1);
			map_len++;
			i++;
		}
		else
			return (-1);
	}
	if (i > *map_l)
		*map_l = i;
	return (map_len);
}

char	*ft_clean_line(char *line, char *ori, int map_l)
{
	char	*clean_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	//if ((clean_line = ft_calloc(map_l + 1, sizeof(char) * (map_l + 1))) == NULL)
	//	return (NULL);
	if (!(clean_line = (char *)malloc(sizeof(char) * (map_l + 1))))
		return (NULL);
	while (line[i])
	{
		if (line[i] == ' ')
		{
			clean_line[j] = '1';
			j++;
		}
		if (ft_check_char(line, i) == 1 || ft_check_char(line, i) == 2)
		{
			if (ft_check_char(line, i) == 2)
				*ori = line[i];
			clean_line[j] = line[i];
			j++;
		}
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

t_list	*ft_list(char *line, int n, int fd, t_all *all)
{
	t_list	*lst;
	char	*clean_line;
	int		map_len;
	int		i;
	int		j;
	int		nb;

	lst = NULL;
	nb = 0;
	j = 0;
	while (n == 1 || n == 0)
	{
		i = 0;
		map_len = ft_map_len(line, &all->map->ori, &all->map->map_l);
		if (map_len > all->map->map_l)
			all->map->map_l = map_len;
		if (map_len < 3 && line == NULL)
			return (NULL);
		clean_line = ft_clean_line(line, &all->map->ori, all->map->map_l);
		if (map_len < 3 && clean_line[0] == '\0')
			return (lst);
		while (clean_line[i])
		{
			if (clean_line[i] == '2')
			{
				all->spr[nb].x = (double)i + 0.5;
				all->spr[nb].y = (double)j + 0.5;
				nb++;
				all->map->spr++;
			}
			i++;
		}
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

char	**ft_map(char *line, int n, int fd, t_all *all)
{
	t_list	*lst;
	t_list	*tmp;
	int		len;
	int		i;
	int		j;

	lst = ft_list(line, n, fd, all);
	tmp = lst;
	len = ft_lstsize(lst);
	j = 0;
	i = 0;
	if ((all->map->map = ft_calloc(len + 1, sizeof(*all->map->map))) == NULL)
		return (NULL);
	while (lst)
	{
		if ((i + 1) == len)
		{
			if (ft_check_map_errors(lst->content, 0) != 1)
				return (NULL);
		}
		all->map->map[i] = ft_substr(lst->content, 0, all->map->map_l + 1);
		lst = lst->next;
		i++;
	}
	return (ft_check_pos(all->map, all->map->map) != NULL ? all->map->map : NULL);
}
