/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:02:39 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/16 19:25:12 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <pthread.h>
#include <unistd.h>

static void	init_thread_data(t_thread_data *td, t_game *g, int i, int slice);
static void	*render_thread(void *arg);
static int	get_num_threads(void);

static int	join_all_threads(pthread_t *threads, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	render_3d_view(t_game *g)
{
	pthread_t		threads[MAX_THREADS];
	t_thread_data	td[MAX_THREADS];
	int				i;
	int				slice;
	int				num_threads;

	num_threads = get_num_threads();
	slice = WIN_W / num_threads;
	i = 0;
	while (i < num_threads)
	{
		td[i].num_threads = num_threads;
		init_thread_data(td, g, i, slice);
		if (pthread_create(&threads[i], NULL, render_thread, &td[i]) != 0)
		{
			join_all_threads(threads, i);
			return (-1);
		}
		i++;
	}
	return (join_all_threads(threads, num_threads));
}

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
	if (i == td[i].num_threads - 1)
		td[i].end_x = WIN_W;
	else
		td[i].end_x = (i + 1) * slice;
}

static int	get_num_threads(void)
{
	long	num_cores;

	num_cores = sysconf(_SC_NPROCESSORS_ONLN);
	if (num_cores <= 0)
		return (4);
	if (num_cores > MAX_THREADS)
		return (MAX_THREADS);
	return ((int)num_cores);
}
