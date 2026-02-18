/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:00:00 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/18 18:37:47 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <math.h>

static void	recenter_mouse(t_game *game, int center_x, int center_y);
static void	update_angle(t_game *game, int delta_x, float sensitivity);

int	mouse_move(int x, int y, t_game *game)
{
	int		delta_x;
	int		center_x;
	int		center_y;

	(void)y;
	if (!game->input.mouse_enabled || game->input.mouse_warping)
	{
		game->input.mouse_warping = 0;
		return (0);
	}
	center_x = WIN_W / 2;
	center_y = WIN_H / 2;
	if (game->input.last_mouse_x == -1)
	{
		recenter_mouse(game, center_x, center_y);
		game->input.last_mouse_x = center_x;
		return (0);
	}
	delta_x = x - center_x;
	if (delta_x != 0)
	{
		update_angle(game, delta_x, 0.002f);
		recenter_mouse(game, center_x, center_y);
	}
	return (0);
}

static void	recenter_mouse(t_game *game, int center_x, int center_y)
{
	game->input.mouse_warping = 1;
	mlx_mouse_move(game->mlx, game->win, center_x, center_y);
}

static void	update_angle(t_game *game, int delta_x, float sensitivity)
{
	game->player.angle += delta_x * sensitivity;
	if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	if (game->player.angle >= 2 * M_PI)
		game->player.angle -= 2 * M_PI;
}
