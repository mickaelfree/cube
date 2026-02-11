/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:01:08 by mickmart          #+#    #+#             */
/*   Updated: 2026/01/31 17:44:55 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	game_loop(t_game *game)
{
	long	current_time;

	current_time = get_time_ms();
	game->delta_time = (current_time - game->last_frame_time) / 1000.0f;
	if (game->delta_time > 0.1f)
		game->delta_time = 0.1f;
	game->last_frame_time = current_time;
	fps_update(&game->fps);
	if (game->input.quit == 1)
	{
		printf("input.quit = %d \n", game->input.quit);
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	process_input(game);
	render_3d_view(game);
	if (game->input.togle_minimap == 1)
		render_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->framebuffer.img, 0, 0);
	draw_fps_on_screen(game);
	return (1);
}
