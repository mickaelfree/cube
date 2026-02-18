/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:39:58 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/16 19:54:11 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <stdlib.h>

static void	exit_with_cleanup(t_game *g)
{
	cleanup_game(g);
	exit(1);
}

void	run_game(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		exit_with_cleanup(g);
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cube");
	if (!g->win)
		exit_with_cleanup(g);
	g->framebuffer.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	if (!g->framebuffer.img)
		exit_with_cleanup(g);
	g->framebuffer.data = mlx_get_data_addr(g->framebuffer.img,
			&g->framebuffer.bpp, &g->framebuffer.line_size,
			&g->framebuffer.endian);
	fps_init(&g->fps);
	g->delta_time = 0.016f;
	g->last_frame_time = get_time_ms();
	if (load_all_textures(g) != 0)
		exit_with_cleanup(g);
	init_trig_tables(g);
	init_hooks(g);
	mlx_loop(g->mlx);
}
