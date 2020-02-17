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
	if (line[i] == '1' || line[i] == '2' || line[i] == '0' ||
			line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		return (1);
	return (0);
}

char	*ft_clean_map(char *line, char **map, int *i, int *j, int len)
{
	int	k;

	ft_printf("Je suis ici\n");
	k = 0;
	ft_printf("line ici :%s\n", line);
	ft_printf("len :%d\n", len);
	ft_printf("line[len] :%c\n", line[29]);
	ft_printf("map ici :%s\n", map[*j]);
	while (line[*i] != '\0')
	{
		ft_printf("Hey toi\n");
		if (line[*i] == ' ')
			(*i)++;
		if (ft_check_char(line, *i) == 1)
			ft_memcpy(map[*j], line, len);
		//	map[*j][k++] = line[(*i)++];
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
	return (len);
}

char	**ft_map(char *line, t_map *info, int n, int fd)
{
	int	len;
	int i;
	int	j;
	char	**map;

	j = 0;
	len = 0;
	i = 0;
	ft_printf("ma len line :%d\n", ft_strlen(line));
	ft_printf("%s\n", line);
	ft_jump(line, &i);
	ft_printf("voici mon i :%d\n", i);
	ft_printf("line :%s\n", line);
	while (n == 1 || n == 0)
	{
		if (ft_check_char(line, i) == 1)
		{
			ft_printf("yoooo\n");
			len = ft_map_len(line, &i) + 1;
			line[len] = '\0';
			if (!(map = (char **)malloc(sizeof(char *) * (len))))
				return (NULL);
		//	ft_printf("This is my len :%d\n", len);
			map[j] = ft_clean_map(line, map, &i, &j, len);
			ft_printf("info->map :%s\n", map[j]);
			j++;
		}
		if (n == 0)
			break;
		i = 0;
		n = get_next_line(fd, &line);
		/*ft_printf("yo %d\n", j);
		ft_printf("la new line :%s\n", line);
		ft_printf("mon ft_check_char :%d\n", ft_check_char(line, i));
		ft_printf("mon line[i] :%c\n", line[i]);*/
	}
	return (info->map);
}