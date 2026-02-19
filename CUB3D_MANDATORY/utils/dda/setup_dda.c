/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_dda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:16:19 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/19 15:45:44 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

static void	setup_dda_x(t_cast_ray_data *dda, t_ray_data *ray);
static void	setup_dda_y(t_cast_ray_data *dda, t_ray_data *ray);

void	setup_dda(t_cast_ray_data *dda, t_ray_data *ray)
{
	setup_dda_x(dda, ray);
	setup_dda_y(dda, ray);
}

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
