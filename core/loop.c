/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:39:58 by mickmart          #+#    #+#             */
/*   Updated: 2025/10/06 15:40:02 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define WIN_W 1280
#define WIN_H 720

# include "../libs/mlx/mlx.h"
#include "../include/cube.h"
void	run_game(t_game *g)
{
	g->mlx = mlx_init();
        if (!g->mlx )
                exit(1);
        g->win = mlx_new_window(g->mlx,WIN_W, WIN_H,"cube");
}
