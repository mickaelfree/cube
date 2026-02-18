/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inbound_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:54:36 by akarapkh          #+#    #+#             */
/*   Updated: 2025/12/11 23:08:23 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	check_point(t_game *g, int map_x, int map_y)
{
	if (map_x < 0 || map_x >= g->map.width || map_y < 0
		|| map_y >= g->map.height)
		return (0);
	if (g->map.grid[map_y][map_x] != 0)
		return (0);
	return (1);
}

int	inbound(t_game *g, float x, float y)
{
	if (!check_point(g, (int)(x + COLLISION_RADIUS), (int)(y
				+ COLLISION_RADIUS)))
		return (0);
	if (!check_point(g, (int)(x - COLLISION_RADIUS), (int)(y
				- COLLISION_RADIUS)))
		return (0);
	if (!check_point(g, (int)(x + COLLISION_RADIUS), (int)(y
				- COLLISION_RADIUS)))
		return (0);
	if (!check_point(g, (int)(x - COLLISION_RADIUS), (int)(y
				+ COLLISION_RADIUS)))
		return (0);
	return (1);
}
