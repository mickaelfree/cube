/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:39:58 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/06 19:45:57 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdint.h>
#include "../include/draw.h"
static void	render_3d_view(t_game *g)
{
	float	fov;
	float	half_fov;
	int		x;
	float	angle_step;
	float	current_angle;
	float	step;
	float	ray_x;
	float	ray_y;
	float	dx;
	float	dy;
	float	distance;

	fov = M_PI / 3.0f;
	half_fov = fov / 2.0f;
	angle_step = fov / WIN_W;
	x = 0;
	while (x < WIN_W)
	{
		current_angle = g->player.angle - half_fov + (x * angle_step);
		step = 0.01f;
		ray_x = g->player.position.x;
		ray_y = g->player.position.y;
		dx = cos(current_angle) * step;
		dy = sin(current_angle) * step;
		distance = 0;
		while (ray_x >= 0 && ray_x < g->map.width && ray_y >= 0
			&& ray_y < g->map.height)
		{
			if (g->map.grid[(int)ray_y][(int)ray_x] == 1)
				break ;
			ray_x += dx;
			ray_y += dy;
			distance += step;
		}
		draw_3d_column(g, x, distance);
		x++;
	}
}
static void	draw_fov_cone(t_game *g)
{
	int		size;
	int		px;
	int		py;
	float	fov;
	float	half_fov;
	int		num_rays;
	float	angle_step;
	int		i;
	float	current_angle;
	float	step;
	float	ray_x;
	float	ray_y;
	float	dx;
	float	dy;
	int		end_x;
	int		end_y;

	size = WIN_W / 100;
	px = 20 + (int)(g->player.position.x * size);
	py = WIN_H - 20 - (int)((g->map.height - g->player.position.y) * size);
	fov = M_PI / 3.0f;
	half_fov = fov / 2.0f;
	num_rays = 50;
	angle_step = fov / (num_rays - 1);
	i = 0;
	while (i < num_rays)
	{
		current_angle = g->player.angle - half_fov + (i * angle_step);
		step = 0.1f;
		ray_x = g->player.position.x;
		ray_y = g->player.position.y;
		dx = cos(current_angle) * step;
		dy = sin(current_angle) * step;
		// Avancer le rayon jusqu'à collision avec un mur
		while (ray_x >= 0 && ray_x < g->map.width && ray_y >= 0
			&& ray_y < g->map.height)
		{
			if (g->map.grid[(int)ray_y][(int)ray_x] == 1)
				break ;
			ray_x += dx;
			ray_y += dy;
		}
		end_x = 20 + (int)(ray_x * size);
		end_y = WIN_H - 20 - (int)((g->map.height - ray_y) * size);
		draw_line(&g->framebuffer, px, py, end_x, end_y, 0xFFFF00);
		i++;
	}
}

static void	draw_player_ray(t_game *g)
{
	int		size;
	int		px;
	int		py;
	float	step;
	float	ray_x;
	float	ray_y;
	float	dx;
	float	dy;
	int		end_x;
	int		end_y;

	size = WIN_W / 100;
	px = 20 + (int)(g->player.position.x * size);
	py = WIN_H - 20 - (int)((g->map.height - g->player.position.y) * size);
	step = 0.1f;
	ray_x = g->player.position.x;
	ray_y = g->player.position.y;
	dx = cos(g->player.angle) * step;
	dy = sin(g->player.angle) * step;
	while (ray_x >= 0 && ray_x < g->map.width && ray_y >= 0
		&& ray_y < g->map.height)
	{
		if (g->map.grid[(int)ray_y][(int)ray_x] == 1)
			break ;
		ray_x += dx;
		ray_y += dy;
	}
	end_x = 20 + (int)(ray_x * size);
	end_y = WIN_H - 20 - (int)((g->map.height - ray_y) * size);
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

	size = WIN_W / 100;
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
	draw_fov_cone(g);
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
int	game_loop(t_game *game)
{
	if (game->input.quit == 1)
	{
		printf("input.quit = %d \n", game->input.quit);
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	process_input(game);
	// jeux s'arrete
	// jeux continue
	// jeux pause
	// render la minimaps
	render_3d_view(game);
        if (game->input.togle_minimap== 1)
	        render_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->framebuffer.img, 0, 0);
	return (1);
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
	g->framebuffer.data = mlx_get_data_addr(g->framebuffer.img,
			&g->framebuffer.bpp, &g->framebuffer.line_size,
			&g->framebuffer.endian);
	if (!g->framebuffer.data)
		exit(1);
	init_hooks(g);
	mlx_loop(g->mlx);
}
