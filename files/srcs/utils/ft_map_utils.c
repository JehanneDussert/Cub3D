/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:29:28 by jehannedu         #+#    #+#             */
/*   Updated: 2020/08/14 11:17:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		if (line && ((line[0] != '1' && line[0] != ' ') ||
			line[ft_strlen(line) - 1] != '1'))
			return (0);
	}
	return (1);
}

int		ft_map_len(char *line, char *ori, int *map_l)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (ft_check_map_char(line, i) != 0)
		{
			if (*ori != '1' && ft_check_map_char(line, i) == 2)
				return (-1);
			i++;
		}
		else
			return (-1);
	}
	if (i > *map_l)
		*map_l = i;
	return (i);
}

int		ft_check_len(char *str, char *tmp)
{
	int i;

	if (ft_strlen(str) > ft_strlen(tmp))
	{
		i = ft_strlen(tmp);
		while (str && str[i] != '\0')
		{
			if (str[i] != '1')
				return (-1);
			i++;
		}
	}
	else if (ft_strlen(str) < ft_strlen(tmp))
	{
		i = ft_strlen(str);
		while (tmp && tmp[i] != '\0')
		{
			if (tmp[i] != '1')
				return (-1);
			i++;
		}
	}
	return (1);
}

int		ft_check_map_char(char *line, int i)
{
	if (line)
	{
		if (line[i] == '1' || line[i] == '2' || line[i] == '0'
				|| line[i] == ' ')
			return (1);
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
		|| line[i] == 'E')
			return (2);
		else if (line[i] == ' ')
			return (3);
	}
	return (0);
}

int		ft_check_char(char *line, int i)
{
	ft_jump(line, &i);
	if (line[i] == 'R' || line[i] == 'C' || line[i] == 'S' || line[i] == 'F'
		|| (ft_first(line, "NO", &i) == 1) || (ft_first(line, "SO", &i) == 1)
		|| (ft_first(line, "WE", &i) == 1) || (ft_first(line, "EA", &i) == 1)
		|| line[i] == '\0' || line[i] == ' ')
		return (1);
	return (0);
}
