/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_crosshair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:00:53 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/22 14:16:36 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_crosshair(t_game *game)
{
	int				cx;
	int				cy;
	int				i;
	unsigned int	color;

	cx = WIN_W / 2;
	cy = WIN_H / 2;
	i = CROSSHAIR_GAP;
	color = game->input.crosshair_color;
	if (!color)
		color = CROSSHAIR_COLOR;
	while (i <= CROSSHAIR_SIZE)
	{
		put_pixel(&game->framebuffer, cx + i, cy, color);
		put_pixel(&game->framebuffer, cx - i, cy, color);
		put_pixel(&game->framebuffer, cx, cy + i, color);
		put_pixel(&game->framebuffer, cx, cy - i, color);
		i++;
	}
}
