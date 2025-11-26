/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:39:58 by mickmart          #+#    #+#             */
/*   Updated: 2025/11/26 23:43:25 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIN_H 720
#define WIN_W 1280


#include "../include/cube.h"
#include <stdint.h>

static inline void	put_pixel(t_texture *fb, int x, int y, uint32_t color)
{
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return;
	*(uint32_t *)(fb->data + y * fb->line_size + x * (fb->bpp / 8)) = color;
}

static void	draw_rect(t_texture *fb, int x, int y, int w, int h, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			put_pixel(fb, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
static void	draw_grid(t_game *g)
{
	int			mx;
	int			my;
	int			px;
	int			py;
	int			size;
	uint32_t	wall_color;
	uint32_t	floor_color;

	size = WIN_W / 100;
	wall_color = 0xFFFFFF;
	floor_color = 0x0000FF;

	my = 0;
	while (my < g->map.height)
	{
		mx = 0;
		while (mx < g->map.width)
		{
			px = 20 + mx * size;
			py = WIN_H - 20 - (g->map.height - my) * size;

			if (g->map.grid[my][mx] > 0)
				draw_rect(&g->framebuffer, px, py, size, size, wall_color);
			else
				draw_rect(&g->framebuffer, px, py, size, size, floor_color);

			mx++;
		}
		my++;
	}
}


void	render_minimap(t_game *g)
{
        draw_grid(g);
}
void raycast_frame(t_game *g)
{
	(void)g; // unused
        int x = 0;

        while(x < WIN_W)
        {
               // init_ray(g);
               // cast_ray(g);
               // draw_column(g, x);
               // x++;
        }



}
int game_loop(t_game *game)
{
        if (game->input.quit == 1)
        {
                printf("input.quit = %d \n", game->input.quit);
                mlx_destroy_window(game->mlx, game->win);
                exit(0);
        }
        //jeux s'arrete
        //jeux continue
        //jeux pause
        //render la minimaps
	render_minimap(game);
        mlx_put_image_to_window(game->mlx, game->win, game->framebuffer.img, 0, 0);
        return 1;
}
void	run_game(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		exit(1);
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cube");
        if (!g->win)
                exit(1);
        g->framebuffer.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
        if (!g->framebuffer.img)
                exit(1);
        g->framebuffer.data = mlx_get_data_addr(g->framebuffer.img, &g->framebuffer.bpp, &g->framebuffer.line_size, &g->framebuffer.endian);
        if (!g->framebuffer.data)
                exit(1);
	init_hooks(g);
        mlx_loop(g->mlx);
}
