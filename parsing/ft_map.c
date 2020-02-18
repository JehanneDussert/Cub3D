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

t_list	*ft_map(char *line, int n, int fd)
{
	t_list	*lst;
	t_list	*tmp;
	char	*clean_line;
	int		i;
	int		j;
	int		map_len;
	int		s;

	j = 0;
	s = 0;
	while (n == 1)
	{
		i = 0;
		map_len = 0;
		while (line[i])
		{
			if (line[i] == ' ')
				i++;
			else if (ft_check_char(line, i) == 1)
			{
				map_len++;
				i++;
			}
			else
				return (NULL);
		}
		ft_printf("map_len :%d\n", map_len);
		if (!(clean_line = (char *)malloc(sizeof(char) * (map_len * 1))))
			return (NULL);
		i = 0;
		while (line[i])
		{
			if (ft_check_char(line, i) == 1)
			{
				clean_line[j] = line[i];
				j++;
			}
			i++;
		}
		clean_line[map_len] = '\0';
		ft_printf("clean line :%s\n", clean_line);
		if (s == 0)
		{
			tmp = ft_lstnew(clean_line);
			free(clean_line);
			clean_line = NULL;
			ft_printf("tmp :%s\n", tmp->content);
			s++;
		}
		else
		{
			ft_printf("line :%s\n", clean_line);
			ft_printf("tmp2 :%s\n", clean_line);
			lst = ft_lstnew(clean_line);
			free(clean_line);
			clean_line = NULL;
			ft_printf("lst :%s\n", lst->content);
			ft_lstadd_back(&tmp, lst);
			ft_printf("heeee\n");
		}
		n = get_next_line(fd, &line);
	}
	return (lst);
}
