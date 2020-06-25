#include "../../includes/cub3d.h"

void    ft_textures(t_all *all)
{
    //all->vec->tex_num = all->map->map[(int)(all->map->pos_y)][(int)(all->map->pos_x)] - '0';
    if (all->vec->side == 0)
        all->vec->wallx = all->map->pos_y + all->vec->dist * all->vec->raydir_y;
    else
        all->vec->wallx = all->map->pos_x + all->vec->dist * all->vec->raydir_x;
    all->vec->wallx -= floor(all->vec->wallx);
    all->vec->texx = (int)(all->vec->wallx * 64.0);
    if (all->vec->side == 0 && all->vec->raydir_x > 0)
        all->vec->texx = 64.0 - all->vec->texx - 1;
    if (all->vec->side == 1 && all->vec->raydir_y < 0)
        all->vec->texx = 64.0 - all->vec->texx - 1;
    //all->vec->step = 1.0 * 64.0 / all->vec->line_height;
    //all->vec->texPos = (all->vec->draw_start - all->map->reso[1] / 2 + all->vec->line_height / 2) * all->vec->step;
}

int    ft_draw_ns(int i, t_all *all)
{
    if (all->vec->raydir_y >= 0)
    {
        while (all->vec->draw_start < all->vec->draw_end)
        {
            all->vec->texy = abs((((all->vec->draw_start * 256 - all->map->reso[1] * 128
			+ all->vec->line_height * 128) * 64) / all->vec->line_height) / 256);
			ft_memcpy(all->image->data + 4 * all->map->reso[0] * all->vec->draw_start
			+ i * 4, &all->text[1].img[all->vec->texy % 64 * all->text[1].size_l +
			all->vec->texx % 64 * all->text[1].bpp / 8], sizeof(int));
			all->vec->draw_start++;
        }
    }
    else
    {
        while (all->vec->draw_start < all->vec->draw_end)
        {
            all->vec->texy = abs((((all->vec->draw_start * 256 - all->map->reso[1] * 128
			+ all->vec->line_height * 128) * 64) / all->vec->line_height) / 256);
			ft_memcpy(all->image->data + 4 * all->map->reso[0] * all->vec->draw_start
			+ i * 4, &all->text[0].img[all->vec->texy % 64 * all->text[0].size_l +
			all->vec->texx % 64 * all->text[0].bpp / 8], sizeof(int));
			all->vec->draw_start++;
        }
    }
    return (1);
}

int    ft_draw_ew(int i, t_all *all)
{
    if (all->vec->raydir_x >= 0)
    {
        while (all->vec->draw_start < all->vec->draw_end)
        {
            all->vec->texy = abs((((all->vec->draw_start * 256 - all->map->reso[1] * 128
			+ all->vec->line_height * 128) * 64) / all->vec->line_height) / 256);
			ft_memcpy(all->image->data + 4 * all->map->reso[0] * all->vec->draw_start
			+ i * 4, &all->text[3].img[all->vec->texy % 64 * all->text[3].size_l +
			all->vec->texx % 64 * all->text[3].bpp / 8], sizeof(int));
			all->vec->draw_start++;
        }
    }
    else
    {
        while (all->vec->draw_start < all->vec->draw_end)
        {
            all->vec->texy = abs((((all->vec->draw_start * 256 - all->map->reso[1] * 128
			+ all->vec->line_height * 128) * 64) / all->vec->line_height) / 256);
			ft_memcpy(all->image->data + 4 * all->map->reso[0] * all->vec->draw_start
			+ i * 4, &all->text[2].img[all->vec->texy % 64 * all->text[2].size_l +
			all->vec->texx % 64 * all->text[2].bpp / 8], sizeof(int));
			all->vec->draw_start++;
        }
    }
    return (1);
}

int     ft_draw_text(int i, t_all *all)
{
    ft_textures(all);
    //ft_draw_mode(all);
    if (all->vec->side == 1)
        ft_draw_ns(i, all);
    else
        ft_draw_ew(i, all);
    if (ft_draw_ns(i, all) != 1 || ft_draw_ew(i, all) != 1)
        return (-1);
    return (1);
}
