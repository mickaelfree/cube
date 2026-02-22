/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:21:13 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/22 15:39:53 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	get_adjacent_block(int hit_x, int hit_y, int wall_dir, int *out);
static int	get_target_wall(t_game *g, int *hit_x, int *hit_y, int *wall_dir);

int	place_block(t_game *game)
{
	int	hit_x;
	int	hit_y;
	int	wall_dir;
	int	target[2];

	if (get_target_wall(game, &hit_x, &hit_y, &wall_dir) == -1)
		return (-1);
	get_adjacent_block(hit_x, hit_y, wall_dir, target);
	if (target[0] < 0 || target[0] >= game->map.width || target[1] < 0
		|| target[1] >= game->map.height)
		return (-1);
	if (game->map.grid[target[1]][target[0]] != 0)
		return (-1);
	game->map.grid[target[1]][target[0]] = 1;
	if (!inbound(game, game->player.position.x, game->player.position.y))
	{
		game->map.grid[target[1]][target[0]] = 0;
		return (-1);
	}
	return (0);
}

static void	get_adjacent_block(int hit_x, int hit_y, int wall_dir, int *out)
{
	out[0] = hit_x;
	out[1] = hit_y;
	if (wall_dir == EAST)
		out[0] = hit_x + 1;
	else if (wall_dir == WEST)
		out[0] = hit_x - 1;
	else if (wall_dir == SOUTH)
		out[1] = hit_y + 1;
	else if (wall_dir == NORTH)
		out[1] = hit_y - 1;
}

static int	get_target_wall(t_game *g, int *hit_x, int *hit_y, int *wall_dir)
{
	t_ray_data		ray;
	t_cast_ray_data	dda;
	float			dx;
	float			dy;

	init_block_ray(g, &ray, &dda);
	if (!perform_dda(g, &dda, &ray))
		return (-1);
	dx = dda.map_x - ray.ray_x;
	dy = dda.map_y - ray.ray_y;
	if (dx * dx + dy * dy > 25.0f)
		return (-1);
	*hit_x = dda.map_x;
	*hit_y = dda.map_y;
	*wall_dir = ray.wall_direction;
	return (0);
}
