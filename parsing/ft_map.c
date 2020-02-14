/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:06:42 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/14 15:01:47 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_char(char *line, int i)
{
	if (line[i] == '1' || line[i] == '2' || line[i] == '0' ||
			line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		return (1);
	return (0);
}

char	*ft_clean_map(char *line, char **map, int *i)
{
	int j;

	j = 0;
	ft_printf("Je suis ici\n");
	while (line[*i] != '\0')
	{
		ft_printf("Hey toi\n");
		if (line[*i] == ' ')
			(*i)++;
		if (ft_check_char(line, *i) == 1)
			*map[j++] = line[(*i)++];
		//	ft_lstadd_back((t_list **)map, (t_list *)line);
	}
	return (*map);
}

int		ft_map_len(char *line, int *i)
{
	int	len;

	len = 0;
	while (line[*i])
	{
		if (line[*i] == ' ')
			(*i)++;
		else if (ft_check_char(line, *i) == 1)
		{
			(*i)++;
			len++;
		}
		else
			break ;
	}
	ft_printf("Len :%d\n", len);
	return (len);
}

void	ft_map(char *line, t_map *info, int n, int fd)
{
	int	len;
	int i;

	len = 0;
	i = 0;
	ft_printf("%s\n", line);
	ft_jump(line, &i);
	ft_printf("line :%s\n", line);
	while (n == 1 || n == 0)
	{
		ft_printf("heere\n");
		if (ft_check_char(line, i) == 1)
		{
			ft_printf("hello\n");
			len = ft_map_len(line, &i);
			free(info->map);
			info->map = NULL;
			if (!(info->map = (char **)malloc(sizeof(char *) * (len + 1))))
				return ;
			ft_printf("This is my len :%d\n", len);
			ft_clean_map(line, info->map, &i);
		}
		if (n == 0)
			break;
		n = get_next_line(fd, &line);
	}
}