/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:45:59 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/21 10:59:17 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
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
	t_list		*map;
	char		ori;
	int			map_len;
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
int				ft_error(char **map, char **line, t_map **info, char *message);
void			ft_jump(char *line, int *i);
t_map			*ft_init(void);
void			ft_check_resolution(char *line, t_map *info, char *map, int *i);
int				ft_colors(char *line, int *color, int *i);
void			ft_text(char *line, t_map *info);
t_list			*ft_map(char *line, int n, int fd, t_map *info);
int				ft_check_char(char *line, int i);
int				ft_check_text(char *line, int i);
void			ft_print(t_map *info);

#endif
