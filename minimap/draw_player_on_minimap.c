/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_on_minimap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:45:01 by akarapkh          #+#    #+#             */
/*   Updated: 2026/01/30 18:45:33 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

void	draw_player_on_minimap(t_game *g, int *center)
{
	int	i;
	int	j;
	int	ray[2];

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
	ray[0] = center[0] + (int)(cosf(g->player.angle) * 15);
	ray[1] = center[1] + (int)(sinf(g->player.angle) * 15);
	draw_line(&g->framebuffer, center[0], center[1], ray[0], ray[1], 0xFF0000);
}
