/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_raycast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:30:00 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/13 02:06:10 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>


// void	cast_ray(t_game *g, t_ray_data *ray, float angle, float plane_angle)
// {
//   t_cast_ray_data	data;
//
// 	init_dda(ray, g, angle, plane_angle);
// 	data.map_x = (int)ray->ray_x;
// 	data.map_y = (int)ray->ray_y;
// 	if (ray->dx == 0)
// 		data.delta_x = 1e30;
// 	else
// 		data.delta_x = fabs(1 / ray->dx);
// 	if (ray->dy == 0)
// 		data.delta_y = 1e30;
//   else
//     data.delta_y = fabs(1 / ray->dy);
// 	if (ray->dx < 0)
// 	{
// 		data.step_x = -1;
// 		data.side_x = (ray->ray_x - data.map_x) * data.delta_x;
// 	}
// 	else { data.step_x = 1; data.side_x = (data.map_x + 1.0 - ray->ray_x) * data.delta_x;
// 	}
// 	if (ray->dy < 0)
// 	{
// 		data.step_y = -1;
// 		data.side_y = (ray->ray_y - data.map_y) * data.delta_y;
// 	}
// 	else
// 	{
// 		data.step_y = 1;
// 		data.side_y = (data.map_y + 1.0 - ray->ray_y) * data.delta_y;
// 	}
// 	data.hit = 0;
// 	while (data.hit == 0)
// 	{
// 		if (data.side_x < data.side_y)
// 		{
// 			data.side_x += data.delta_x;
// 			data.map_x += data.step_x;
// 			if (data.step_x < 0)
// 				ray->wall_direction = EAST;
// 			else
// 				ray->wall_direction = WEST;
// 		}
// 		else
// 		{
// 			data.side_y += data.delta_y;
// 			data.map_y += data.step_y;
// 			if (data.step_y < 0)
// 				ray->wall_direction = SOUTH;
// 			else
// 				ray->wall_direction = NORTH;
// 		}
// 		if (data.map_x < 0 || data.map_x >= g->map.width || data.map_y < 0
// 			|| data.map_y >= g->map.height)
// 			break ;
// 		if (g->map.grid[data.map_y][data.map_x] == 1)
// 			data.hit = 1;
// 	}
// 	if (ray->wall_direction == EAST || ray->wall_direction == WEST)
// 	{
// 		ray->distance = (data.map_x - ray->ray_x + (1 - data.step_x) / 2) / ray->dx;
// 		if (ray->distance < 0)
// 			ray->distance = 0.001f;
// 	}
// 	else
// 	{
// 		ray->distance = (data.map_y - ray->ray_y + (1 - data.step_y) / 2) / ray->dy;
// 		if (ray->distance < 0)
// 			ray->distance = 0.001f;
// 	}
// 	calc_wall_x(ray, ray->distance);
// 	ray->distance = ray->distance * cos(plane_angle);
// }
//

static void	init_ray(t_ray_data *ray, t_game *g, float angle)
{
	ray->current_angle = angle;
	ray->ray_x = g->player.position.x;
	ray->ray_y = g->player.position.y;
	ray->dx = fast_cos(g, angle);
	ray->dy = fast_sin(g, angle);
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
		raw_dist = (d->map_x - r->ray_x + (1 - d->step_x) / 2) / r->dx;
	else
		raw_dist = (d->map_y - r->ray_y + (1 - d->step_y) / 2) / r->dy;
	
	if (raw_dist < 0.001f)
		raw_dist = 0.001f;
	
	r->distance = raw_dist * fast_cos(g, pa);
	calc_wall_x(r, raw_dist);
}

void	cast_ray(t_game *g, t_ray_data *ray, float angle, float plane_angle)
{
	t_cast_ray_data	dda;

	init_ray(ray, g, angle);
	dda.map_x = (int)ray->ray_x;
	dda.map_y = (int)ray->ray_y;
	setup_dda(&dda, ray);
	dda.hit = 0;
	if (!perform_dda(g, &dda, ray))
	{
		ray->distance = 1000.0f;
		return ;
	}
	calc_dist(ray, &dda, plane_angle, g);
}
