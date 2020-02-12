/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:29:55 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/12 18:34:38 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSING_H
# define PARSING_H

# include <mlx.h>

typedef struct	s_map
{
	int			reso[2];
	void		*n_path;
	void		*s_path;
	void		*e_path;
	void		*w_path;
	void		*spr_path;
	int			f_path;
	int			c_path;
	char		**map;
}				t_map;

void			ft_check(char *map, char *title);
char			*ft_error(char **map, char **line, t_map **info, t_image **image, char *message);
void			ft_jump(char *line, int *i);
void			ft_init(t_map *info);
void			ft_check_resolution(char *line, t_map *info, t_image *image, char *map, int *i);
int				ft_colors(char *line, int *color, int *i);
char			*ft_text(char *line, t_map *info, t_image *image, int *i);

#endif