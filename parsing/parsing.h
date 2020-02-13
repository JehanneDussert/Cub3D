/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:45:59 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/13 14:48:51 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSING_H
# define PARSING_H

# include <mlx.h>
# include "../cub3d.h"

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

typedef struct	s_image
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	int			width;
	int			height;
	char		*title;
}				t_image;

void			ft_check(char *map, char *title);
char			*ft_error(char **map, char **line, t_map **info, t_image **image, char *message);
void			ft_jump(char *line, int *i);
void			ft_init(t_map *info);
void			ft_check_resolution(char *line, t_map *info, t_image *image, char *map, int *i);
int				ft_colors(char *line, int *color, int *i);
void			ft_text(char *line, t_map *info, t_image *image, int *i);

#endif