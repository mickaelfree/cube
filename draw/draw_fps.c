/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:15:45 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/12 01:17:32 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <stdio.h>

void	draw_fps_on_screen(t_game *g)
{
	char	fps_text[32];
	int		color;

	snprintf(fps_text, sizeof(fps_text), "FPS: %.0f", g->fps.current_fps);
	if (g->fps.current_fps >= 60)
		color = 0x00FF00;
	else if (g->fps.current_fps >= 30)
		color = 0xFFFF00;
	else
		color = 0xFF0000;
	mlx_string_put(g->mlx, g->win, 10, 20, color, fps_text);
}
