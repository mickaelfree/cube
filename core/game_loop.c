/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:01:08 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/11 23:21:02 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

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
