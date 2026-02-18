/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:59:26 by mickmart          #+#    #+#             */
/*   Updated: 2026/02/12 02:55:29 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

long	get_time_ms(void)
{
	t_timer	t;

	gettimeofday(&t.timer, NULL);
	return ((t.timer.tv_sec * 1000) + (t.timer.tv_usec / 1000));
}
