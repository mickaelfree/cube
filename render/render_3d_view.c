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
#include <pthread.h>

typedef struct s_thread_data
{
	t_game	*game;
	int		start_x;
	int		end_x;
}	t_thread_data;

static void	*render_thread(void *arg)
{
	t_thread_data	*td;
	t_render_data	d;

	td = (t_thread_data *)arg;
	d.x = td->start_x;
	while (d.x < td->end_x)
	{
		d.ray_angle = td->game->trig.ray_angles[d.x];
		d.current_angle = td->game->player.angle + d.ray_angle;
		cast_ray(td->game, &d.ray, d.current_angle, d.ray_angle);
		d.params.x = d.x;
		d.params.distance = d.ray.distance;
		d.params.wall_direction = d.ray.wall_direction;
		d.params.wall_x = d.ray.wall_x;
		draw_3d_column(td->game, &d.params);
		d.x++;
	}
	return (NULL);
}

static void	init_thread_data(t_thread_data *td, t_game *g, int i, int slice)
{
	td[i].game = g;
	td[i].start_x = i * slice;
	if (i == 3)
		td[i].end_x = WIN_W;
	else
		td[i].end_x = (i + 1) * slice;
}

void	render_3d_view(t_game *g)
{
	pthread_t		threads[4];
	t_thread_data	td[4];
	int				i;
	int				slice;

	slice = WIN_W / 4;
	i = 0;
	while (i < 4)
	{
		init_thread_data(td, g, i, slice);
		pthread_create(&threads[i], NULL, render_thread, &td[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
