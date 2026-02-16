/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:08:20 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/16 15:14:11 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"

static void	select_texture(t_column_data *data, t_game *g, int wall_dir);
static void	draw_wall(t_game *g, t_column_data *data, int x);

void	draw_3d_column(t_game *g, t_column_params *params)
{
	t_column_data	data;

	ft_memset(&data, 0, sizeof(t_column_data));
	select_texture(&data, g, params->wall_direction);
	if (params->distance == 0)
		params->distance = 0.1f;
	data.wall_height = (int)((float)WIN_H / params->distance);
	data.wall_start = (WIN_H - data.wall_height) / 2;
	data.wall_end = data.wall_start + data.wall_height;
	data.tex_x = (int)(params->wall_x * data.current_texture->width);
	if (data.tex_x < 0)
		data.tex_x = 0;
	if (data.tex_x >= data.current_texture->width)
		data.tex_x = data.current_texture->width - 1;
	if (data.wall_start < 0)
		data.wall_start = 0;
	if (data.wall_end > WIN_H)
		data.wall_end = WIN_H;
	draw_ceiling(g, &data, params->x);
	if (data.current_texture->data && data.current_texture->img)
		draw_wall(g, &data, params->x);
	draw_floor(g, &data, params->x);
}

static void	select_texture(t_column_data *data, t_game *g, int wall_dir)
{
	if (wall_dir == NORTH)
		data->current_texture = &g->north_texture;
	else if (wall_dir == SOUTH)
		data->current_texture = &g->south_texture;
	else if (wall_dir == EAST)
		data->current_texture = &g->east_texture;
	else if (wall_dir == WEST)
		data->current_texture = &g->west_texture;
	else
		data->current_texture = &g->north_texture;
}

static void	draw_wall(t_game *g, t_column_data *data, int x)
{
	int	tex_y;

	data->tex_data = (int *)data->current_texture->data;
	data->tex_step = (float)data->current_texture->height / data->wall_height;
	if ((WIN_H - data->wall_height) / 2 < 0)
		data->tex_pos = -((WIN_H - data->wall_height) / 2) * data->tex_step;
	else
		data->tex_pos = 0;
	data->y = data->wall_start;
	while (data->y < data->wall_end)
	{
		tex_y = (int)data->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= data->current_texture->height)
			tex_y = data->current_texture->height - 1;
		data->fb_pixel = (uint32_t *)(g->framebuffer.data + data->y
				* g->framebuffer.line_size + x * (g->framebuffer.bpp / 8));
		*data->fb_pixel = data->tex_data[(tex_y
				* (data->current_texture->line_size / 4)) + data->tex_x];
		data->tex_pos += data->tex_step;
		data->y++;
	}
}
