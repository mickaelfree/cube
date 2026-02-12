/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_from_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 06:38:20 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/12 03:29:30 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "parsing.h"

static void	set_player_angle(t_game *game, char c);
static void	set_player_position(t_game *game, int x, int y, char c);

int	init_player_from_map(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->config.parse.raw_map[y]
			&& game->config.parse.raw_map[y][x])
		{
			c = game->config.parse.raw_map[y][x];
			if (is_player_char(c))
			{
				set_player_position(game, x, y, c);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

static void	set_player_position(t_game *game, int x, int y, char c)
{
	game->player.position.x = (float)x + 0.5f;
	game->player.position.y = (float)y + 0.5f;
	game->config.parse.player_dir = c;
	game->config.parse.player_x = x;
	game->config.parse.player_y = y;
	set_player_angle(game, c);
}

static void	set_player_angle(t_game *game, char c)
{
	if (c == 'N')
		game->player.angle = 3.0f * M_PI / 2.0f;
	else if (c == 'S')
		game->player.angle = M_PI / 2.0f;
	else if (c == 'E')
		game->player.angle = 0.0f;
	else if (c == 'W')
		game->player.angle = M_PI;
}
