/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:02:39 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/12 02:54:52 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

void	render_3d_view(t_game *g)
{
	t_ray_data		ray;
	t_column_params	params;
	int				x;
	float			plane_dist;
	float			current_angle;
	float			ray_angle;

	plane_dist = (WIN_W / 2.0f) / tan(FOV / 2.0f);
	x = 0;
	while (x < WIN_W)
	{
		ray_angle = atan2((x - WIN_W / 2.0f), plane_dist);
		current_angle = g->player.angle + ray_angle;
		cast_ray(g, &ray, current_angle, ray_angle);
		params.x = x;
		params.distance = ray.distance;
		params.wall_direction = ray.wall_direction;
		params.wall_x = ray.wall_x;
		draw_3d_column(g, &params);
		x++;
	}
}
