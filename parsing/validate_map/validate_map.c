/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:14:22 by akarapkh          #+#    #+#             */
/*   Updated: 2025/12/11 06:03:44 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "parsing.h"
#include <stdio.h>

static int	check_cell_walls(t_map *map, int x, int y);
static int	check_walls(t_map *map);
static int	check_player(t_parse *parse);

int	validate_map(t_game *game)
{
	if (game->map.height < 3 || game->map.width < 3)
		return (-1);
	if (!check_player(&game->config.parse))
		return (-1);
	if (check_walls(&game->map) == -1)
		return (-1);
	return (0);
}

static int	check_player(t_parse *parse)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (parse->raw_map[y])
	{
		x = 0;
		while (parse->raw_map[y][x])
		{
			printf("check player : %c\n", parse->raw_map[y][x]);
			if (is_player_char(parse->raw_map[y][x]))
			{
				parse->player_x = x;
				parse->player_y = y;
				parse->player_dir = parse->raw_map[y][x];
				count++;
			}
			x++;
		}
		y++;
	}
	return (count == 1);
}

static int	check_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 0)
			{
				if (check_cell_walls(map, x, y) == -1)
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_cell_walls(t_map *map, int x, int y)
{
	if (x == 0 || y == 0 || x == map->width - 1 || y == map->height - 1)
		return (-1);
	if (map->grid[y - 1][x] == -1 || map->grid[y + 1][x] == -1)
		return (-1);
	if (map->grid[y][x - 1] == -1 || map->grid[y][x + 1] == -1)
		return (-1);
	return (0);
}
