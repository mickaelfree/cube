/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:01:08 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/17 15:04:01 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx.h"
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
		cleanup_game(game);
		exit(0);
	}
	process_input(game);
	if (render_3d_view(game) != 0)
		return (-1);
	if (game->input.togle_minimap == 1)
		render_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->framebuffer.img, 0, 0);
	draw_fps_on_screen(game);
	return (1);
}
