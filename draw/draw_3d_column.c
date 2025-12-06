/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:08:20 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/06 19:16:44 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/draw.h"

void	draw_3d_column(t_game *g, int x, float distance)
{
	int	wall_height;
	int	wall_start;
	int	wall_end;
	int	y;

	if (distance == 0)
		distance = 0.1f;
	wall_height = (int)(WIN_H / distance);
	wall_start = (WIN_H - wall_height) / 2;
	wall_end = wall_start + wall_height;
	y = 0;
	while (y < wall_start)
	{
		put_pixel(&g->framebuffer, x, y, 0x87CEEB);
		y++;
	}
	y = wall_start;
	while (y < wall_end && y < WIN_H)
	{
		put_pixel(&g->framebuffer, x, y, 0x8B4513);
		y++;
	}
	y = wall_end;
	while (y < WIN_H)
	{
		put_pixel(&g->framebuffer, x, y, 0x228B22);
		y++;
	}
}
