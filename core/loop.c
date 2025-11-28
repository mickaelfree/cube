/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:39:58 by mickmart          #+#    #+#             */
/*   Updated: 2025/11/06 12:19:09 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define WIN_W 1280
#define WIN_H 720


#include "../include/cube.h"
#include <stdint.h>

float	ft_absf(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}
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

static void	draw_line(t_texture *fb, int x0, int y0, int x1, int y1, uint32_t color)
{
	int dx = ft_absf(x1 - x0);
	int dy = ft_absf(y1 - y0);
	int sx, sy;
	
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	int err = dx - dy;
	
	while (1)
	{
		put_pixel(fb, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

static void	draw_player_ray(t_game *g)
{
	int size = WIN_W / 100;
	int px = 20 + (int)(g->player.position.x * size);
	int py = WIN_H - 20 - (int)((g->map.height - g->player.position.y) * size);
	
	float step = 0.1f;
	float ray_x = g->player.position.x;
	float ray_y = g->player.position.y;
	float dx = cos(g->player.angle) * step;
	float dy = sin(g->player.angle) * step;
	
	while (ray_x >= 0 && ray_x < g->map.width &&
		   ray_y >= 0 && ray_y < g->map.height)
	{
		if (g->map.grid[(int)ray_y][(int)ray_x] == 1)
			break;
		
		ray_x += dx;
		ray_y += dy;
	}
	
	int end_x = 20 + (int)(ray_x * size);
	int end_y = WIN_H - 20 - (int)((g->map.height - ray_y) * size);
	
	draw_line(&g->framebuffer, px, py, end_x, end_y, 0xFF0000);
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


static void	draw_player_dot(t_game *g)
{
	int			px;
	int			py;
	int			size;
	uint32_t	player_color;

	size =  WIN_W / 100;
	player_color = 0x00FF00;

	px = 20 + (int)(g->player.position.x * size);
	py = WIN_H - 20 - (int)((g->map.height - g->player.position.y) * size);

	draw_rect(&g->framebuffer, px - 2, py - 2, 4, 4, player_color);
}

void	render_minimap(t_game *g)
{
        draw_grid(g);
        draw_player_dot(g);
        draw_player_ray(g);
}
// void raycast_frame(t_game *g)
// {
//         int x = 0;
//
//         while(x < WIN_W)
//         {
//                // init_ray(g);
//                // cast_ray(g);
//                // draw_column(g, x);
//                // x++;
//         }
// }
// void init_ray(t_game *g)
// {
//         int x = 0;
//         float normalized = x / (float)WIN_W;
//         float camera_x = normalized * 2 - 1;
//
//
// }
int game_loop(t_game *game)
{
        if (game->input.quit == 1)
        {
                printf("input.quit = %d \n", game->input.quit);
                mlx_destroy_window(game->mlx, game->win);
                exit(0);
        }
        process_input(game);
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
