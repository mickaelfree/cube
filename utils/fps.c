/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:04:44 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/16 16:45:22 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	fps_init(t_fps_counter *fps)
{
	fps->frame_count = 0;
	fps->last_update = get_time_ms();
	fps->current_fps = 0.0f;
}

void	fps_update(t_fps_counter *fps)
{
	long	current_time;
	float	delta_time;

	current_time = get_time_ms();
	fps->frame_count++;
	delta_time = (float)(current_time - fps->last_update) / 1000.0f;
	if (delta_time >= 0.5f)
	{
		fps->current_fps = fps->frame_count / delta_time;
		fps->frame_count = 0;
		fps->last_update = current_time;
		fps->should_update = 1;
	}
}

void	fps_reset_stats(t_fps_counter *fps)
{
	fps_init(fps);
}
