/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:59:56 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/11 23:21:54 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>

static void	process_rotation(t_game *game);
static void	try_move(t_game *game, float dx, float dy);
static void	process_movement(t_game *game, float cos_a, float sin_a);

void	process_input(t_game *game)
{
	float	cos_a;
	float	sin_a;

	process_rotation(game);
	cos_a = cos(game->player.angle);
	sin_a = sin(game->player.angle);
	process_movement(game, cos_a, sin_a);
}

static void	process_movement(t_game *game, float cos_a, float sin_a)
{
	if (game->input.forward == 1)
		try_move(game, cos_a * MOVE_SPEED, sin_a * MOVE_SPEED);
	if (game->input.backward == 1)
		try_move(game, -cos_a * MOVE_SPEED, -sin_a * MOVE_SPEED);
	if (game->input.left == 1)
		try_move(game, sin_a * MOVE_SPEED, -cos_a * MOVE_SPEED);
	if (game->input.right == 1)
		try_move(game, -sin_a * MOVE_SPEED, cos_a * MOVE_SPEED);
}

static void	try_move(t_game *game, float dx, float dy)
{
	float	new_x;
	float	new_y;

	new_x = game->player.position.x + dx;
	new_y = game->player.position.y + dy;
	if (inbound(game, new_x, game->player.position.y))
		game->player.position.x = new_x;
	if (inbound(game, game->player.position.x, new_y))
		game->player.position.y = new_y;
}

static void	process_rotation(t_game *game)
{
	if (game->input.rotate_left == 1)
		game->player.angle += ROTATION_SPEED;
	if (game->input.rotate_right == 1)
		game->player.angle -= ROTATION_SPEED;
	if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	if (game->player.angle >= 2 * M_PI)
		game->player.angle -= 2 * M_PI;
}
