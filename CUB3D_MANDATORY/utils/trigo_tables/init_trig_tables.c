/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_trig_tables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 00:18:26 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/18 13:39:48 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "draw.h"
#include <math.h>

void	init_trig_tables(t_game *game)
{
	int		i;
	float	angle;

	i = 0;
	while (i < 3600)
	{
		angle = (float)i * M_PI / 1800.0f;
		game->trig.cos_table[i] = cosf(angle);
		game->trig.sin_table[i] = sinf(angle);
		i++;
	}
	game->trig.plane_dist = (WIN_W / 2.0f) / tanf(FOV / 2.0f);
	i = 0;
	while (i < WIN_W)
	{
		game->trig.ray_angles[i] = atan2f((i - WIN_W / 2.0f),
				game->trig.plane_dist);
		i++;
	}
}
