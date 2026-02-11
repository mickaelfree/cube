/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:08:20 by mickmart          #+#    #+#             */
/*   Updated: 2026/01/31 20:36:26 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_3d_column(t_game *g, int x, float distance, int wall_direction, float wall_x)
{
	int			wall_height;
	int			wall_start;
	int			wall_end;
	int			y;
	t_texture	*current_texture;
	int			tex_x;
	float		tex_step;
	float		tex_pos;
	uint32_t	*fb_pixel;
	int			*tex_data;

	if (wall_direction == NORTH)
		current_texture = &g->north_texture;
	else if (wall_direction == SOUTH)
		current_texture = &g->south_texture;
	else if (wall_direction == EAST)
		current_texture = &g->east_texture;
	else if (wall_direction == WEST)
		current_texture = &g->west_texture;
	else
		current_texture = &g->north_texture;
	if (distance == 0)
		distance = 0.1f;
	wall_height = (int)((float)WIN_H / distance);
	wall_start = (WIN_H - wall_height) / 2;
	wall_end = wall_start + wall_height;
	tex_x = (int)(wall_x * current_texture->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= current_texture->width)
		tex_x = current_texture->width - 1;
	if (wall_start < 0)
		wall_start = 0;
	if (wall_end > WIN_H)
		wall_end = WIN_H;
	y = 0;
	while (y < wall_start)
	{
		fb_pixel = (uint32_t *)(g->framebuffer.data + y * g->framebuffer.line_size + x * (g->framebuffer.bpp / 8));
		*fb_pixel = g->config.parse.ceiling_color;
		y++;
	}
	tex_x = (int)(wall_x * current_texture->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= current_texture->width)
		tex_x = current_texture->width - 1;
	y = wall_start;
	if (current_texture->data && current_texture->img)
	{
		tex_data = (int *)current_texture->data;
		tex_step = (float)current_texture->height / wall_height;
		if ((WIN_H - wall_height) / 2 < 0)
			tex_pos = -((WIN_H - wall_height) / 2) * tex_step;
		else
			tex_pos = 0;
		while (y < wall_end)
		{
			int tex_y = (int)tex_pos;
			if (tex_y >= current_texture->height)
				tex_y = current_texture->height - 1;
			fb_pixel = (uint32_t *)(g->framebuffer.data + y * g->framebuffer.line_size + x * (g->framebuffer.bpp / 8));
			*fb_pixel = tex_data[(tex_y * current_texture->line_size / 4) + tex_x];
			tex_pos += tex_step;
			y++;
		}
	}
	else
		return ;
	y = wall_end;
	while (y < WIN_H)
	{
		fb_pixel = (uint32_t *)(g->framebuffer.data + y * g->framebuffer.line_size + x * (g->framebuffer.bpp / 8));
		*fb_pixel = g->config.parse.floor_color;
		y++;
	}
}
