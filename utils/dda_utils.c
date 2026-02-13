/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 00:42:04 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/13 02:03:54 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	setup_dda_x(t_cast_ray_data *dda, t_ray_data *ray)
{
	if (fabsf(ray->dx) < 0.0001f)
		dda->delta_x = 1e30f;
	else if (ray->dx < 0)
		dda->delta_x = -1.0f / ray->dx;
	else
		dda->delta_x = 1.0f / ray->dx;
	if (ray->dx < 0)
	{
		dda->step_x = -1;
		dda->side_x = (ray->ray_x - dda->map_x) * dda->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_x = (dda->map_x + 1.0f - ray->ray_x) * dda->delta_x;
	}
}

static void	setup_dda_y(t_cast_ray_data *dda, t_ray_data *ray)
{
	if (fabsf(ray->dy) < 0.0001f)
		dda->delta_y = 1e30f;
	else if (ray->dy < 0)
		dda->delta_y = -1.0f / ray->dy;
	else
		dda->delta_y = 1.0f / ray->dy;
	if (ray->dy < 0)
	{
		dda->step_y = -1;
		dda->side_y = (ray->ray_y - dda->map_y) * dda->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_y = (dda->map_y + 1.0f - ray->ray_y) * dda->delta_y;
	}
}

void	setup_dda(t_cast_ray_data *dda, t_ray_data *ray)
{
	setup_dda_x(dda, ray);
	setup_dda_y(dda, ray);
}

int	perform_dda(t_game *g, t_cast_ray_data *dda, t_ray_data *ray)
{
	while (1)
	{
		if (dda->side_x < dda->side_y)
		{
			dda->side_x += dda->delta_x;
			dda->map_x += dda->step_x;
			if (dda->step_x < 0)
				ray->wall_direction = EAST;
			else
				ray->wall_direction = WEST;
		}
		else
		{
			dda->side_y += dda->delta_y;
			dda->map_y += dda->step_y;
			if (dda->step_y < 0)
				ray->wall_direction = SOUTH;
			else
				ray->wall_direction = NORTH;
		}
		if (dda->map_x < 0 || dda->map_x >= g->map.width || dda->map_y < 0
			|| dda->map_y >= g->map.height)
			return (0);
		if (g->map.grid[dda->map_y][dda->map_x] == 1)
			return (1);
	}
}
