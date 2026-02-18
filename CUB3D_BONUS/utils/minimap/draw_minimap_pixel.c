/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:44:34 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/18 13:44:52 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

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
