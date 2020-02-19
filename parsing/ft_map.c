/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:06:42 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/14 17:45:10by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_char(char *line, int i)
{
	if (line[i] == '1' || line[i] == '2' || line[i] == '0')
		return (1);
	else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		return (2);
	return (0);
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
	if (mode == 1)
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
	return(clean_line);
}

t_list	*ft_map(char *line, int n, int fd, t_map *info)
{
	t_list	*lst;
	t_list	*tmp;
	char	*clean_line;
	int		map_len;
	int		s;

	s = 0;
	if (!(info->ori = (char)malloc(2)))
		return (NULL);
	info->ori = '1';
	while (n == 1 || n == 0)
	{
			map_len = ft_map_len(line, &info->ori);
		if (map_len < 1)
			return (NULL);
		clean_line = ft_clean_line(line, &info->ori, map_len);
		if (s == 0)
		{
			if (ft_check_map_errors(clean_line, map_len, 0) == 0)
				return (NULL);
			lst = ft_lstnew(clean_line);
			s++;
		}
		else
		{
			if (ft_check_map_errors(clean_line, map_len, 1) == 0)
				return (NULL);
			tmp = ft_lstnew(clean_line);
			ft_lstadd_back(&lst, tmp);
			if (n == 0 && ft_check_map_errors(clean_line, map_len, 0) == 1)
				return (lst);
		}
		free(line);
		line = NULL;
		n = get_next_line(fd, &line);
	}
	if (ft_check_map_errors(line, map_len, 1) == 1)
		return (lst);
	return (NULL);
}
