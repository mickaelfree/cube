/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:47:28 by mickmart          #+#    #+#             */
/*   Updated: 2026/01/30 19:18:48 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	init_line_data(t_line_data *data, t_line_params *params)
{
	data->dx = (int)ft_abs(params->x1 - params->x0);
	data->dy = (int)ft_abs(params->y1 - params->y0);
	if (params->x0 < params->x1)
		data->sx = 1;
	else
		data->sx = -1;
	if (params->y0 < params->y1)
		data->sy = 1;
	else
		data->sy = -1;
	data->err = data->dx - data->dy;
}

void	draw_line(t_texture *fb, t_line_params *params)
{
	t_line_data	data;

	init_line_data(&data, params);
	while (1)
	{
		put_pixel(fb, params->x0, params->y0, params->color);
		if (params->x0 == params->x1 && params->y0 == params->y1)
			break ;
		data.e2 = 2 * data.err;
		if (data.e2 > -data.dy)
		{
			data.err -= data.dy;
			params->x0 += data.sx;
		}
		if (data.e2 < data.dx)
		{
			data.err += data.dx;
			params->y0 += data.sy;
		}
	}
}
