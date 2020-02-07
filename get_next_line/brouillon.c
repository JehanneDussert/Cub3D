#include "get_next_line.h"
#include "../cub3d.h"

int			ft_l_atoi(const char *str, int *i)
{
	unsigned int	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = (result * 10) + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

void    ft_saute(char *new_map, int *i)
{
    while(new_map[*i] == '\n')
        (*i)++;
}

void    ft_resolution(t_map *info, char *new_map, int *i)
{
    while(new_map[*i] != '\0')
    {
        if (new_map[*i] == 'R')
        {
            ++(*i);
            while(new_map[*i] == ' ')
                (*i)++;
            if (new_map[*i] >= '0' && new_map[*i] <= '9')
            {
                info->reso[0] = ft_l_atoi(new_map, i);
                while(new_map[*i] == ' ')
                    (*i)++;
                if (new_map[*i] >= '0' && new_map[*i] <= '9')
                    info->reso[1] = ft_l_atoi(new_map, i);
            }
        }
        (*i)++;
    }
}
/*
char    *ft_ori_path()
{

}

char    *ft_sprite_path()
{

}

char    *ft_fc()
{

}
*/

int     ft_check_walls(t_map *info, char **new_map, int *i)
{
    int     j;
    int     k;
    int     l;
    int     c;

    j = *i;
    k = 0;
    l = 0;
    c = 0;
    printf("HEYYYY\n");
    printf("%c\n", new_map[j][k]);
    if (!())
    while((new_map[j][k] == '0' || new_map[j][k] == '1' || new_map[j][k] == '2' || new_map[j][k] == ' '
            || new_map[j][k] == 'N' || new_map[j][k] == 'S' || new_map[j][k] == 'E'
            || new_map[j][k] == 'W') && new_map[j][k] != '\0')
    {
        printf("yo\n");
        while(new_map[j][k] == ' ')
            j++;
        if(new_map[j][k] == '\n')
        {
            printf("hey\n");
            j++;
            l++;
            k = 0;
            c = 0;
        }
        while((new_map[j][k] == '0' || new_map[j][k] == '1' || new_map[j][k] == '2' || new_map[j][k] == 'N'
                || new_map[j][k] == 'S' || new_map[j][k] == 'E'
                || new_map[j][k] == 'W') && new_map[j][k] != '\0')
        {
            printf("wewe\n");
            info->map[l][c++] = new_map[j][k++];
        }
        /* Checker ligne[0][i++] == 1 */
        /* Checker ligne[i++][0] == 1 */
        /* Checker ligne[max][i++] == 1 */
        /* Checker ligne[i++][max] == 1 */
        return(1);
    }
    while(new_map[j][k] != '1')
        {
            printf("ICI\n");
            k++;
            if (new_map[j][k] == '\n')
            {
                printf("lol\n");
                j++;
                k = 0;
            }
        }
    
    return(0);
}

char    *ft_verify(void)
{
    int     i;
    int     j;
    int     k = 0;
    t_map   *info;
    char    *map = NULL;
    char    **new_map;

    i = 0;
    j = 0;
    if (!(info = (t_map *)malloc(sizeof(t_map))))
        return(NULL);
    map = ft_check(map);
    new_map = ft_split(map, '\n');
    while (new_map[i] != '\0')
    {
  /*      if (new_map[i][j++] == '\n')
            ft_saute(new_map[i], &i);
        ft_resolution(info, new_map[i], &i);
    */    if ((new_map[j][k] == '0' || new_map[j][k] == '1' || new_map[j][k] == '2' || new_map[j][k] == ' '
            || new_map[j][k] == 'N' || new_map[j][k] == 'S' || new_map[j][k] == 'E'
            || new_map[j][k] == 'W') && new_map[j][k] != '\0')
            {
                if (ft_check_walls(info, new_map, &i) == 0)
                {
                    printf("ERROR");
                    break ;
                }
                else
                    printf("SUCCESS");
            }
        else
        {
            if(new_map[j][k] != '\n')
                k++;
            else
            {
                k = 0;
                j++;
            }
            
        }

    }
  /*  printf("%d\n", info->reso[0]);
    printf("%d\n", info->reso[1]);
    */return(*new_map);
}

int     main(void)
{
    ft_verify();
    return(0);
}g