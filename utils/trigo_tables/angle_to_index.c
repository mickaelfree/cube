/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_to_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:37:07 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/18 13:37:17 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	angle_to_index(float angle)
{
	int	index;

	index = (int)(angle * 1800.0f / M_PI);
	index = index % 3600;
	if (index < 0)
		index += 3600;
	return (index);
}
