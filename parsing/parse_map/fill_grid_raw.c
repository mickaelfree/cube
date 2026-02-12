/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid_raw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:01:27 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/12 03:29:30 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	fill_grid_row(char *line, int *row, int width)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == '1')
			row[x] = 1;
		else if (is_player_char(line[x]) || line[x] == '0')
			row[x] = 0;
		else if (line[x] == ' ')
			row[x] = -1;
		else
			return (-1);
		x++;
	}
	while (x < width)
		row[x++] = -1;
	return (0);
}
