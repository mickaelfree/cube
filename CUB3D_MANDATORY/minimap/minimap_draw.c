/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:15:00 by akarapkh          #+#    #+#             */
/*   Updated: 2026/01/30 18:49:42 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	draw_pixel_grid(t_game *g, int *data);
static void	process_cell(t_game *g, int *vars);

void	draw_circular_grid(t_game *g, int *center)
{
	int	mx;
	int	my;
	int	vars[5];

	my = 0;
	while (my < g->map.height)
	{
		mx = 0;
		while (mx < g->map.width)
		{
			vars[0] = mx;
			vars[1] = my;
			vars[2] = center[0];
			vars[3] = center[1];
			vars[4] = center[2];
			process_cell(g, vars);
			mx++;
		}
		my++;
	}
}

static void	draw_pixel_grid(t_game *g, int *data)
{
	int	i;
	int	j;
	int	pos[4];

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			pos[0] = data[0] + i;
			pos[1] = data[1] + j;
			pos[2] = data[4];
			pos[3] = data[5];
			draw_minimap_pixel(g, pos, &data[6]);
			j++;
		}
		i++;
	}
}

static void	process_cell(t_game *g, int *vars)
{
	int	data[9];

	if (is_in_fov(g, (float)vars[0] + 0.5f, (float)vars[1] + 0.5f, 10.0f))
	{
		data[0] = vars[2] + (vars[0] - (int)g->player.position.x) * 8;
		data[1] = vars[3] + (vars[1] - (int)g->player.position.y) * 8;
		data[4] = vars[0];
		data[5] = vars[1];
		data[6] = vars[2];
		data[7] = vars[3];
		data[8] = vars[4];
		draw_pixel_grid(g, data);
	}
}
