/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:59:56 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/16 13:02:06 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "draw.h"
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
	cos_a = fast_cos(game, game->player.angle);
	sin_a = fast_sin(game, game->player.angle);
	process_movement(game, cos_a, sin_a);
}

static void	process_movement(t_game *game, float cos_a, float sin_a)
{
	float	speed;

	speed = MOVE_SPEED * game->delta_time;
	if (game->input.forward == 1)
		try_move(game, cos_a * speed, sin_a * speed);
	if (game->input.backward == 1)
		try_move(game, -cos_a * speed, -sin_a * speed);
	if (game->input.left == 1)
		try_move(game, sin_a * speed, -cos_a * speed);
	if (game->input.right == 1)
		try_move(game, -sin_a * speed, cos_a * speed);
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
	float	rot_speed;

	rot_speed = ROTATION_SPEED * game->delta_time;
	if (game->input.rotate_left == 1)
		game->player.angle += rot_speed;
	if (game->input.rotate_right == 1)
		game->player.angle -= rot_speed;
	if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	if (game->player.angle >= 2 * M_PI)
		game->player.angle -= 2 * M_PI;
}
