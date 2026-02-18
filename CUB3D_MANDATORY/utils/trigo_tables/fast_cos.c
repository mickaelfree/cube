/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_cos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:33:55 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/18 13:37:27 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

float	fast_cos(t_game *game, float angle)
{
	return (game->trig.cos_table[angle_to_index(angle)]);
}
