/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:08:20 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/13 00:19:24 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_3d_column(t_game *g, int x, float distance, int wall_direction)
{
	int	wall_height;
	int	wall_start;
	int	wall_end;
	int	y;
        t_texture *current_texture;

	if (wall_direction == NORTH)
		current_texture = &g->north_texture;
	else if (wall_direction == SOUTH)
		current_texture = &g->south_texture;
	else if (wall_direction == EAST)
		current_texture = &g->east_texture;
	else if (wall_direction == WEST)
		current_texture = &g->west_texture;
	else
		current_texture = &g->north_texture; // fallback
	if (distance == 0)
		distance = 0.1f;
	wall_height = (int)(WIN_H / distance);
	wall_start = (WIN_H - wall_height) / 2;
	wall_end = wall_start + wall_height;
	y = 0;
	while (y < wall_start)
	{
		put_pixel(&g->framebuffer, x, y, g->config.parse.ceiling_color);
		y++;
	}
	y = wall_start;
	while (y < wall_end && y < WIN_H)
	{
		if (current_texture->data && current_texture->img)
		{
			int tex_y = ((y - wall_start) * current_texture->height) / wall_height;
			int tex_x = x % current_texture->width;
			int color = get_texture_pixel(current_texture, tex_x, tex_y);
			put_pixel(&g->framebuffer, x, y, color);
		}
		else
		{
			put_pixel(&g->framebuffer, x, y, 0x8B4513);
		}
		y++;
	}
	y = wall_end;
	while (y < WIN_H)
	{
		put_pixel(&g->framebuffer, x, y, g->config.parse.floor_color);
		y++;
	}
}
