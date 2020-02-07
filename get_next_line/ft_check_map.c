#include "get_next_line.h"
#include "../cub3d.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

char    *ft_error(char **map, char **line, t_map **info, char *message)
{
    if(*map)
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
    return(message);
}

void    ft_check_info(char **line, char **map, t_map info)
{

}

char    *ft_new_line(char **line, char **map, t_map **info)
{
    char *tmp;

    if(!(tmp = ft_substr(*map, 0, ft_strlen(*map))))
        return(ft_error(map, line, info, "[ERROR]\nProbleme d'allocation de memoire."));
    free(*map);
    *map = NULL;
    if(!(*map = ft_strjoin(tmp, *line)))
        return(ft_error(map, line, info, "[ERROR]\nProbleme de gestion de la map."));
    free(*line);
    *line = NULL;
    free(tmp);
    tmp = NULL;
    return(*map);
}

char    *ft_check(char *map)
{
    t_map   *info;
    char    *line;
    char    *tmp;
    int     n;
    int     fd;

    if(!(info = (t_map *)malloc(sizeof(t_map) + 1)))
        return(ft_error(&map, &line, &info, "[ERROR]\nProbleme d'allocation de memoire"));
    if(!(map = (char *)malloc(sizeof(char) + 1)))
        return(ft_error(&map, &line, &info, "[ERROR]\nProbleme d'allocation de memoire."));
    if(!(fd = open("map.cub", O_RDONLY)))
        return(ft_error(&map, &line, &info, "[ERROR]\nProbleme a l'ouverture du fichier."));
    n = get_next_line(fd, &line);
    while(n == 1)
    {
        ft_new_line(&line, &map, &info);
        tmp = ft_substr(map, 0, ft_strlen(map));
        free(map);
        map = NULL;
        map = ft_strjoin(tmp, "\n");
        free(tmp);
        tmp = NULL;
        n = get_next_line(fd, &line);
    }
    ft_new_line(&line, &map, &info);
    return(map);
}

int     main(int argc, char **argv)
{
    char    *map = NULL;

    if(argc > 1 && argc < 4)
    {
        if (!(ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))
            return("[ERROR]\nWrong filename.")
        map = ft_check(map);
        ft_printf("%s\n", map);
    }
    return(0);
}