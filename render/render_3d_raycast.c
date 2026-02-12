/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_raycast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:30:00 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/12 02:54:42 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

static void	calc_wall_x(t_ray_data *ray, float perp_wall_dist);
static void	init_dda(t_ray_data *ray, t_game *g, float angle,
				float plane_angle);

void	cast_ray(t_game *g, t_ray_data *ray, float angle, float plane_angle)
{
  t_cast_ray_data	data;

	init_dda(ray, g, angle, plane_angle);
	data.map_x = (int)ray->ray_x;
	data.map_y = (int)ray->ray_y;
	if (ray->dx == 0)
		delta_x = 1e30;
	else
		delta_x = fabs(1 / ray->dx);
	if (ray->dy == 0)
		delta_y = 1e30;
  else
    delta_y = fabs(1 / ray->dy);
	if (ray->dx < 0)
	{
		step_x = -1;
		side_x = (ray->ray_x - map_x) * delta_x;
	}
	else
	{
		step_x = 1;
		side_x = (map_x + 1.0 - ray->ray_x) * delta_x;
	}
	if (ray->dy < 0)
	{
		step_y = -1;
		side_y = (ray->ray_y - map_y) * delta_y;
	}
	else
	{
		step_y = 1;
		side_y = (map_y + 1.0 - ray->ray_y) * delta_y;
	}
	hit = 0;
	while (hit == 0)
	{
		if (side_x < side_y)
		{
			side_x += delta_x;
			map_x += step_x;
			if (step_x < 0)
				ray->wall_direction = EAST;
			else
				ray->wall_direction = WEST;
		}
		else
		{
			side_y += delta_y;
			map_y += step_y;
			if (step_y < 0)
				ray->wall_direction = SOUTH;
			else
				ray->wall_direction = NORTH;
		}
		if (map_x < 0 || map_x >= g->map.width || map_y < 0
			|| map_y >= g->map.height)
			break ;
		if (g->map.grid[map_y][map_x] == 1)
			hit = 1;
	}
	if (ray->wall_direction == EAST || ray->wall_direction == WEST)
	{
		ray->distance = (map_x - ray->ray_x + (1 - step_x) / 2) / ray->dx;
		if (ray->distance < 0)
			ray->distance = 0.001f;
	}
	else
	{
		ray->distance = (map_y - ray->ray_y + (1 - step_y) / 2) / ray->dy;
		if (ray->distance < 0)
			ray->distance = 0.001f;
	}
	calc_wall_x(ray, ray->distance);
	ray->distance = ray->distance * cos(plane_angle);
}

static void	init_dda(t_ray_data *ray, t_game *g, float angle, float plane_angle)
{
	ray->current_angle = angle;
	ray->ray_x = g->player.position.x;
	ray->ray_y = g->player.position.y;
	ray->dx = cos(angle);
	ray->dy = sin(angle);
	(void)plane_angle;
}

static void	calc_wall_x(t_ray_data *ray, float perp_wall_dist)
{
	float	wall_hit_x;
	float	wall_hit_y;

	wall_hit_x = ray->ray_x + ray->dx * perp_wall_dist;
	wall_hit_y = ray->ray_y + ray->dy * perp_wall_dist;
	if (ray->wall_direction == NORTH || ray->wall_direction == SOUTH)
		ray->wall_x = wall_hit_x - floor(wall_hit_x);
	else
		ray->wall_x = wall_hit_y - floor(wall_hit_y);
}
