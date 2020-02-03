#include "get_next_line.h"
#include "../cub3d.h"

void    ft_check(void)
{
    char    *line;
    int     n;
    int     fd;

    fd = open("map.cub", O_RDONLY);
    n = get_next_line(fd, &line);
    while(n == 1)
    {
        printf("%s\n", line);
        free(line);
        line = NULL;
        n = get_next_line(fd, &line);
    }
    printf("%s\n", line);
    free(line);
    line = NULL;
}

int     main(void)
{
    ft_check();
    return(0);
}