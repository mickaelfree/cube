/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:09:57 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/12 00:10:48 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

void	draw_player_ray(t_game *g)
{
	int		size;
	int		px;
	int		py;
	float	step;
	float	ray_x;
	float	ray_y;
	float	dx;
	float	dy;
	int		end_x;
	int		end_y;

	size = WIN_W / 100;
	px = 20 + (int)(g->player.position.x * size);
	py = WIN_H - 20 - (int)((g->map.height - g->player.position.y) * size);
	step = 0.1f;
	ray_x = g->player.position.x;
	ray_y = g->player.position.y;
	dx = cos(g->player.angle) * step;
	dy = sin(g->player.angle) * step;
	while (ray_x >= 0 && ray_x < g->map.width && ray_y >= 0
		&& ray_y < g->map.height)
	{
		if (g->map.grid[(int)ray_y][(int)ray_x] == 1)
			break ;
		ray_x += dx;
		ray_y += dy;
	}
	end_x = 20 + (int)(ray_x * size);
	end_y = WIN_H - 20 - (int)((g->map.height - ray_y) * size);
	draw_line(&g->framebuffer, px, py, end_x, end_y, 0xFF0000);
}
