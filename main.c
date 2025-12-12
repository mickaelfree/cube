/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:17:44 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/11 23:23:22 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "cube.h"
#include "parsing.h"
#include <stdio.h>

// int	**malloc_grid(int width, int height)
// {
// 	int	**grid;
// 	int	i;

// 	grid = malloc(sizeof(int *) * height);
// 	if (!grid)
// 		return (NULL);
// 	i = 0;
// 	while (i < height)
// 	{
// 		grid[i] = malloc(sizeof(int) * width);
// 		if (!grid[i])
// 		{
// 			while (i--)
// 				free(grid[i]);
// 			free(grid);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	return (grid);
// }
// int	load_test_map(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	test_grid[16][16] = {
// 		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1},
// 		{1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
// 		{1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
// 		{1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
// 		{1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
// 		{1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
// 		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
// 	};

// 	map->width = 16;
// 	map->height = 16;
// 	map->grid = malloc_grid(16, 16);
// 	if (!map->grid)
// 		return (0);

// 	i = 0;
// 	while (i < 16)
// 	{
// 		j = 0;
// 		while (j < 16)
// 		{
// 			map->grid[i][j] = test_grid[i][j];
// 			j++;
// 		}
// 		i++;
// 	}
//         return (1);
// }

// void init_player(t_game *g)
// {
// 	g->player.position.x = 8.5;
// 	g->player.position.y = 8.5;
// 	g->player.angle = 0.1f;
// }

int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Usage: %s <map.cub>\n", argv[0]);
		return (1);
	}
	game.mlx = NULL;
	memset(&game.input, 0, sizeof(t_input));
	if (parse_file(argv[1], &game) == -1)
	{
		printf("Error: Failed to parse map file\n");
		return (1);
	}
	run_game(&game);
	return (0);
}
