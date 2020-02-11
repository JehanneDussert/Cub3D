/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:53:34 by jdussert          #+#    #+#             */
/*   Updated: 2020/02/11 17:23:26 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

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

int				get_next_line(int fd, char **line);
void			ft_check(char *map, char *title);

#endif
