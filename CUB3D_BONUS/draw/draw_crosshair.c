/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_crosshair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:00:53 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/22 13:11:24 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_crosshair(t_game *game)
{
	int	cx;
	int	cy;
	int	i;

	cx = WIN_W / 2;
	cy = WIN_H / 2;
	i = CROSSHAIR_GAP;

	while (i <= CROSSHAIR_SIZE)
	{
		put_pixel(&game->framebuffer, cx + i, cy, CROSSHAIR_COLOR);
		put_pixel(&game->framebuffer, cx - i, cy, CROSSHAIR_COLOR);
		put_pixel(&game->framebuffer, cx, cy + i, CROSSHAIR_COLOR);
		put_pixel(&game->framebuffer, cx, cy - i, CROSSHAIR_COLOR);
		i++;
	}
}
