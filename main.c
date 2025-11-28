/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:17:44 by mickmart          #+#    #+#             */
/*   Updated: 2025/11/04 15:55:46 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/cube.h"
static int	**malloc_grid(int width, int height)
{
	int	**grid;
	int	i;

	grid = malloc(sizeof(int *) * height);
	if (!grid)
		return (NULL);

	i = 0;
	while (i < height)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}
int	load_test_map(t_map *map)
{
	int	i;
	int	j;
	int	test_grid[8][8] = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};

	map->width = 8;
	map->height = 8;
	map->grid = malloc_grid(8, 8);
	if (!map->grid)
		return (0);

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			map->grid[i][j] = test_grid[i][j];
			j++;
		}
		i++;
	}

	return (1);
}

int main(int argc,char **argv)
{
        t_game game;


        //TODO: faire la struct du jeux et toute les struct qui en decoule 
        //TODO: parser la map
        //parser(&game.map)

        //TODO: init le jeux
        game.mlx = NULL;
        game.player.position.x = 4.5f;
        game.player.position.y = 4.5f;


	load_test_map(&game.map);
        run_game(&game);
        (void)argc;
        (void)argv;

}
