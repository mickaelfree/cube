/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:56:05 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/12 01:17:24 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_ceiling(t_game *g, t_column_data *data, int x)
{
	data->y = 0;
	while (data->y < data->wall_start)
	{
		data->fb_pixel = (uint32_t *)(g->framebuffer.data + data->y
				* g->framebuffer.line_size + x * (g->framebuffer.bpp / 8));
		*data->fb_pixel = g->config.parse.ceiling_color;
		data->y++;
	}
}
