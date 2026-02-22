/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_block_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:17:50 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/22 15:40:02 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

void	init_block_ray(t_game *g, t_ray_data *ray, t_cast_ray_data *dda)
{
	int	idx;

	ray->ray_x = g->player.position.x;
	ray->ray_y = g->player.position.y;
	idx = (int)((g->player.angle + M_PI) * 1800.0f / M_PI) % 3600;
	ray->dx = g->trig.cos_table[idx];
	ray->dy = g->trig.sin_table[idx];
	dda->map_x = (int)ray->ray_x;
	dda->map_y = (int)ray->ray_y;
	setup_dda(dda, ray);
}
