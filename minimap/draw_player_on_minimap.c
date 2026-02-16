/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_on_minimap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:45:01 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/16 12:53:51 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_player_on_minimap(t_game *g, int *center)
{
	int				i;
	int				j;
	t_line_params	params;

	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			put_pixel(&g->framebuffer, center[0] + i, center[1] + j, 0x00FF00);
			j++;
		}
		i++;
	}
	params.x0 = center[0];
	params.y0 = center[1];
	params.x1 = center[0] + (int)(fast_cos(g, g->player.angle) * 15);
	params.y1 = center[1] + (int)(fast_sin(g, g->player.angle) * 15);
  params.color = 0x0000FF;
	draw_line(&g->framebuffer, &params);
}
