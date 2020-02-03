#include "get_next_line.h"
#include "../cub3d.h"

char    *ft_new_line(char **line, char **map)
{
    char *tmp;
    if(!(tmp = ft_substr(*map, 0, ft_strlen(*map))))
        return(NULL);
    free(*map);
    *map = NULL;
    if(!(*map = ft_strjoin(tmp, *line)))
        return(NULL);
    free(*line);
    *line = NULL;
    free(tmp);
    tmp = NULL;
    return(*map);
}

char    *ft_check(char *map)
{
    char    *line;
    int     n;
    int     fd;

    if(!(map = (char *)malloc(sizeof(char) + 1)))
        return(NULL);
    fd = open("map.cub", O_RDONLY);
    n = get_next_line(fd, &line);
    while(n == 1)
    {
        ft_new_line(&line, &map);
        n = get_next_line(fd, &line);
    }
    ft_new_line(&line, &map);
    return(map);
}

int     main(void)
{
    char    *map = NULL;
    map = ft_check(map);
    printf("%s\n", map);
    return(0);
}