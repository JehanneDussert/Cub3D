/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:29:55 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/11 18:32:14 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSING_H
# define PARSING_H

typedef struct	s_map
{
	int			reso[2];
	char		*n_path;
	char		*s_path;
	char		*e_path;
	char		*w_path;
	char		*spr_path;
	char		*f_path;
	char		*c_path;
	char		**map;
}				t_map;

void			ft_check(char *map, char *title);
char			*ft_error(char **map, char **line, t_map **info, char *message);
void			ft_jump(char *line, int *i);
void			ft_init(t_map *info);

#endif