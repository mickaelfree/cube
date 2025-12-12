/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:39:58 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/11 23:20:36 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "draw.h"
#include <stdlib.h>

void	run_game(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		exit(1);
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cube");
	if (!g->win)
		exit(1);
	g->framebuffer.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	if (!g->framebuffer.img)
		exit(1);
	g->framebuffer.data = mlx_get_data_addr(g->framebuffer.img,
											&g->framebuffer.bpp,
											&g->framebuffer.line_size,
											&g->framebuffer.endian);
	load_all_textures(g);
	init_hooks(g);
	mlx_loop(g->mlx);
}
