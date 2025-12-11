/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:39:58 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/09 23:15:00 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdint.h>
#include "../include/draw.h"
void	render_3d_view(t_game *g)
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
	load_all_textures(g);
	init_hooks(g);
	mlx_loop(g->mlx);
}
