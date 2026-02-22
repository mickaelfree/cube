/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:15:59 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/22 15:39:56 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int	get_target_wall(t_game *g, int *hit_x, int *hit_y);

int	remove_block(t_game *game)
{
	int	hit_x;
	int	hit_y;

	if (get_target_wall(game, &hit_x, &hit_y) == -1)
		return (-1);
	game->map.grid[hit_y][hit_x] = 0;
	if (is_map_closed(game) == -1)
	{
		game->map.grid[hit_y][hit_x] = 1;
		return (-1);
	}
	return (0);
}

static int	get_target_wall(t_game *g, int *hit_x, int *hit_y)
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
	return (0);
}
