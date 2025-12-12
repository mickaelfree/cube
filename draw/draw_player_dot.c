/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_dot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:34:08 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/11 23:16:34 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_player_dot(t_game *g)
{
	int			px;
	int			py;
	int			size;
	uint32_t	player_color;

	size = WIN_W / 100;
	player_color = 0x00FF00;
	px = 20 + (int)(g->player.position.x * size);
	py = WIN_H - 20 - (int)((g->map.height - g->player.position.y) * size);
	draw_rect(&g->framebuffer, px - 2, py - 2, 4, 4, player_color);
}
