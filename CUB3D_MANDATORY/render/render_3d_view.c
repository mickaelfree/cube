/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:02:39 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/19 15:45:06 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	render_column(t_game *g, t_render_data *d)
{
	d->ray_angle = g->trig.ray_angles[d->x];
	d->current_angle = g->player.angle + d->ray_angle;
	cast_ray(g, &d->ray, d->current_angle, d->ray_angle);
	d->params.x = d->x;
	d->params.distance = d->ray.distance;
	d->params.wall_direction = d->ray.wall_direction;
	d->params.wall_x = d->ray.wall_x;
	draw_3d_column(g, &d->params);
}

int	render_3d_view(t_game *g)
{
	t_render_data	d;

	d.x = 0;
	while (d.x < WIN_W)
	{
		render_column(g, &d);
		d.x++;
	}
	return (0);
}
