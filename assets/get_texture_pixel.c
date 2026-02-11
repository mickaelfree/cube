/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:52:38 by mickmart          #+#    #+#             */
/*   Updated: 2026/01/30 18:58:26 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_texture_pixel(t_texture *texture, int x, int y)
{
	int	*data;
	int	index;

	if (!texture || !texture->data || !texture->img)
		return (0x8B4513);
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0x8B4513);
	data = (int *)texture->data;
	index = (y * texture->line_size / 4) + x;
	return (data[index]);
}
