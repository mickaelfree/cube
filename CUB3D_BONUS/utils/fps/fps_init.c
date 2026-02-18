/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:27:40 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/18 13:28:02 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	fps_init(t_fps_counter *fps)
{
	fps->frame_count = 0;
	fps->last_update = get_time_ms();
	fps->current_fps = 0.0f;
}
