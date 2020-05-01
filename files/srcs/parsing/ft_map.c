/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:35:30 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/12 16:31:08 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_check_map_errors(char *line, int len, int mode)
{
	int	i;

	i = 0;
	if (mode == 0)
	{
		while (line[i])
		{
			if (line[i] != '1')
				return (0);
			i++;
		}
	}
	else if (mode == 1)
	{
		if (line[0] != '1' || line[len - 1] != '1')
			return (0);
	}
	return (1);
}

int		ft_map_len(char *line, char *ori)
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
	return (map_len);
}

char	*ft_clean_line(char *line, char *ori, int len)
{
	char	*clean_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(clean_line = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (line[i])
	{
		if (ft_check_char(line, i) == 1 || ft_check_char(line, i) == 2)
		{
			if (ft_check_char(line, i) == 2)
				*ori = line[i];
			clean_line[j] = line[i];
			j++;
		}
		i++;
	}
	clean_line[len] = '\0';
	return (clean_line);
}

t_list	*ft_new_line(t_list *lst, char *clean_line, int len, int mode)
{
	t_list	*tmp;

	if (mode == 0)
	{
		if (ft_check_map_errors(clean_line, len, 0) == 0)
			return (NULL);
		lst = ft_lstnew(clean_line);
	}
	else if (mode == 1)
	{
		if (ft_check_map_errors(clean_line, len, 1) == 0)
			return (NULL);
		tmp = ft_lstnew(clean_line);
		ft_lstadd_back(&lst, tmp);
	}
	return (lst);
}

t_list	*ft_list(char *line, int n, int fd, t_map *info)
{
	t_list	*lst;
	char	*clean_line;
	int		map_len;

	lst = NULL;
	info->ori = '1';
	while (n == 1 || n == 0)
	{
		map_len = ft_map_len(line, &info->ori);
		if (map_len < 3)
			return (NULL);
		clean_line = ft_clean_line(line, &info->ori, map_len);
		if (lst == NULL)
			lst = ft_new_line(lst, clean_line, map_len, 0);
		else
		{
			lst = ft_new_line(lst, clean_line, map_len, 1);
			if (n == 0 && ft_check_map_errors(clean_line, map_len, 0) == 1)
				return (lst);
		}
		free(line);
		line = NULL;
		n = get_next_line(fd, &line);
	}
	return (ft_check_map_errors(line, map_len, 1) == 1 ? lst : NULL);
}

char	**ft_map(char *line, int n, int fd, t_map *info)
{
	char	**map;
	t_list	*lst;
	int		len;
	int		i;
	int		j;

	lst = ft_list(line, n, fd, info);
	len = ft_lstsize(lst);
	i = 0;
	j = 0;
	if ((map = ft_calloc(len + 1, sizeof(*map))) == NULL)
		return (NULL);
	while (lst)
	{
		map[i] = lst->content;
		lst = lst->next;
		i++;
	}
	return (ft_check_pos(info, map) != NULL ? map : NULL);
}
