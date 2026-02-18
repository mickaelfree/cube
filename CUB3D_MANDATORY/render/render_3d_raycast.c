/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_raycast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:30:00 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/16 15:19:49 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

static void	calc_wall_x(t_ray_data *ray, float perp_dist);
static void	calc_dist(t_ray_data *r, t_cast_ray_data *d, float pa, t_game *g);

void	cast_ray(t_game *g, t_ray_data *ray, float angle, float plane_angle)
{
	t_cast_ray_data	dda;

	ray->current_angle = angle;
	ray->ray_x = g->player.position.x;
	ray->ray_y = g->player.position.y;
	ray->dx = g->trig.cos_table[(int)((angle + M_PI) * 1800.0f / M_PI) % 3600];
	ray->dy = g->trig.sin_table[(int)((angle + M_PI) * 1800.0f / M_PI) % 3600];
	dda.map_x = (int)ray->ray_x;
	dda.map_y = (int)ray->ray_y;
	setup_dda(&dda, ray);
	if (!perform_dda(g, &dda, ray))
	{
		ray->distance = 1000.0f;
		return ;
	}
	calc_dist(ray, &dda, plane_angle, g);
}

static void	calc_wall_x(t_ray_data *ray, float perp_dist)
{
	if (ray->wall_direction == EAST || ray->wall_direction == WEST)
		ray->wall_x = ray->ray_y + perp_dist * ray->dy;
	else
		ray->wall_x = ray->ray_x + perp_dist * ray->dx;
	ray->wall_x -= floorf(ray->wall_x);
}

static void	calc_dist(t_ray_data *r, t_cast_ray_data *d, float pa, t_game *g)
{
	float	raw_dist;

	if (r->wall_direction == EAST || r->wall_direction == WEST)
		raw_dist = (d->map_x - r->ray_x + (1 - d->step_x) * 0.5f) / r->dx;
	else
		raw_dist = (d->map_y - r->ray_y + (1 - d->step_y) * 0.5f) / r->dy;
	if (raw_dist < 0.001f)
		raw_dist = 0.001f;
	r->distance = raw_dist * fast_cos(g, pa);
	calc_wall_x(r, raw_dist);
}
