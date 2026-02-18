/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:57:38 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/12 01:17:28 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_floor(t_game *g, t_column_data *data, int x)
{
	data->y = data->wall_end;
	while (data->y < WIN_H)
	{
		data->fb_pixel = (uint32_t *)(g->framebuffer.data + data->y
				* g->framebuffer.line_size + x * (g->framebuffer.bpp / 8));
		*data->fb_pixel = g->config.parse.floor_color;
		data->y++;
	}
}
