/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:52:39 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/22 14:10:54 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

static int	close_hook(t_game *game);

void	init_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_hook(game->win, 17, 0, close_hook, game);
	mlx_hook(game->win, 4, 1L << 2, mouse_click, game);
	mlx_hook(game->win, 5, 1L << 3, mouse_release, game);
	mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
	mlx_loop_hook(game->mlx, game_loop, game);
}

static int	close_hook(t_game *game)
{
	game->input.quit = 1;
	return (0);
}
