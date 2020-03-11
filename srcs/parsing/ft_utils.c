/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:27:33 by jdussert          #+#    #+#             */
/*   Updated: 2020/03/11 14:32:11 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map	*ft_init(void)
{
	t_map	*info;

	if (!(info = (t_map *)malloc(sizeof(t_map) + 1)))
		return (NULL);
	if (!(info->map = (char **)malloc(sizeof(char *) + 1)))
		return (NULL);
	info->reso[0] = -1;
	info->reso[1] = -1;
	info->n_path = NULL;
	info->s_path = NULL;
	info->w_path = NULL;
	info->e_path = NULL;
	info->spr_path = NULL;
	info->f_path = -1;
	info->c_path = -1;
	info->pos_x = 0;
	info->pos_y = 0;
	return (info);
}

int		ft_error(char **map, char **line, t_map **info, char *message)
{
	if (*map)
	{
		free(*map);
		*map = NULL;
	}
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	if (*info)
	{
		free(*info);
		*info = NULL;
	}
	ft_printf("%s\n", message);
	return (-1);
}

void	ft_jump(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
}

int		ft_check_char(char *line, int i)
{
	if (line[i] == '1' || line[i] == '2' || line[i] == '0')
		return (1);
	else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
	|| line[i] == 'E')
		return (2);
	return (0);
}
