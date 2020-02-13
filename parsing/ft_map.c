/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:06:42 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/13 19:13:52 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_clean_map(char *line, char **map, int *len, int *i)
{
	int j;

	j = 0;
	ft_printf("Je suis ici\n");
	while (line[*i] != '\0')
	{
		ft_printf("Hey toi\n");
		if (line[*i] == ' ')
			(*i)++;
		if (line[*i] == '1' || line[*i] == '2' || line[*i] == '0' ||
			line[*i] == 'N' || line[*i] == 'S' || line[*i] == 'W' || line[*i] == 'E')
			*map[j++] = line[(*i)++];
		//	ft_lstadd_back((t_list **)map, (t_list *)line);
	}
	return (*map);
}

int		ft_map_len(char *line, int *i, int *len)
{
	while (line[*i])
	{
		if (line[*i] == ' ')
			(*i)++;
		if (line[*i] == '1' || line[*i] == '2' || line[*i] == '0' ||
			line[*i] == 'N' || line[*i] == 'S' || line[*i] == 'W' || line[*i] == 'E')
			(*len)++;
	}
	ft_printf("Len :%d\n", *len);
	return (*len);
}

void	ft_map(char *map, char *line, t_map *info, t_image *image, int *i)
{
	int len;

	len = 0;
	ft_printf("%s\n", line);
	ft_jump(line, i);
	ft_printf("line :%s\n", line);
	if (line[*i] == '0' || line[*i] == '1' || line[*i] == '2' || line[*i] == 'N'
		|| line[*i] == 'S' || line[*i] == 'W' || line[*i] != 'E')
	{
		ft_map_len(line, i, &len);
		free(info->map);
		info->map = NULL;
		if (!(info->map = (char **)malloc(sizeof(char *) * (len + 1))))
			return ;
		ft_printf("This is my len :%d\n", len);
		ft_clean_map(line, info->map, &len, i);
	}
}