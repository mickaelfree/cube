/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:07:56 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/11 23:16:34 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_grid(t_game *g)
{
	int			mx;
	int			my;
	int			px;
	int			py;
	int			size;
	uint32_t	wall_color;
	uint32_t	floor_color;

	size = WIN_W / 100;
	wall_color = 0xFFFFFF;
	floor_color = 0x0000FF;
	my = 0;
	while (my < g->map.height)
	
	{
		mx = 0;
		while (mx < g->map.width)
		{
			px = 20 + mx * size;
			py = WIN_H - 20 - (g->map.height - my) * size;
			if (g->map.grid[my][mx] > 0)
				draw_rect(&g->framebuffer, px, py, size, size, wall_color);
			else if (g->map.grid[my][mx] == -1)
				draw_rect(&g->framebuffer, px, py, size, size, wall_color);
			else
				draw_rect(&g->framebuffer, px, py, size, size, floor_color);
			mx++;
		}
		my++;
	}
}
