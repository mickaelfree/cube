/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:15:00 by akarapkh          #+#    #+#             */
/*   Updated: 2026/01/29 20:28:41 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

int	is_in_fov(t_game *g, float mx, float my, float radius)
{
	float	dx;
	float	dy;
	float	dist;

	dx = mx - g->player.position.x;
	dy = my - g->player.position.y;
	dist = sqrtf(dx * dx + dy * dy);
	if (dist > radius)
		return (0);
	return (1);
}

void	draw_minimap_pixel(t_game *g, int *pos, int *center)
{
	int	dx;
	int	dy;
	int	color;

	dx = pos[0] - center[0];
	dy = pos[1] - center[1];
	if (dx * dx + dy * dy <= center[2] * center[2])
	{
		if (g->map.grid[pos[3]][pos[2]] > 0)
			color = 0x808080;
		else
			color = 0x202020;
		put_pixel(&g->framebuffer, pos[0], pos[1], color);
	}
}

void	get_minimap_center(int *result)
{
	result[0] = WIN_W - 80 - 20;
	result[1] = 80 + 20;
	result[2] = 80;
}
