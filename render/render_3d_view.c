/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:02:39 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/13 02:23:20 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

void	render_3d_view(t_game *g)
{
	t_render_data	d;

	d.plane_dist = (WIN_W / 2.0f) / tan(FOV / 2.0f);
	d.x = 0;
	while (d.x < WIN_W)
	{
		d.ray_angle = atan2((d.x - WIN_W / 2.0f), d.plane_dist);
		d.current_angle = g->player.angle + d.ray_angle;
		cast_ray(g, &d.ray, d.current_angle, d.ray_angle);
		d.params.x = d.x;
		d.params.distance = d.ray.distance;
		d.params.wall_direction = d.ray.wall_direction;
		d.params.wall_x = d.ray.wall_x;
		draw_3d_column(g, &d.params);
		d.x++;
	}
}
