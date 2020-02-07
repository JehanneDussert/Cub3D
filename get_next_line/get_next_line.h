#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct  s_map
{
    int         reso[2];
    char        *n_path;
    char        *s_path;
    char        *e_path;
    char        *w_path;
    char        *spr_path;
    char        *f_path;
    char        *c_path;
    char        **map;
}               t_map;


int		get_next_line(int fd, char **line);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char    *ft_check(char * map);
char    **ft_split(char const *s, char c);

#endif