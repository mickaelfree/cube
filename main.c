/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:17:44 by mickmart          #+#    #+#             */
/*   Updated: 2025/12/10 02:53:20 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "include/cube.h"
static int	**malloc_grid(int width, int height)
{
	int	i;

	if (game->config.parse.no_texture)
		free(game->config.parse.no_texture);
	if (game->config.parse.so_texture)
		free(game->config.parse.so_texture);
	if (game->config.parse.we_texture)
		free(game->config.parse.we_texture);
	if (game->config.parse.ea_texture)
		free(game->config.parse.ea_texture);
	if (game->config.parse.raw_map)
	{
		i = 0;
		while (game->config.parse.raw_map[i])
			free(game->config.parse.raw_map[i++]);
		free(game->config.parse.raw_map);
	}
	return (grid);
}
int	load_test_map(t_map *map)
{
	int	i;
	int	j;
	int	test_grid[16][16] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	map->width = 16;
	map->height = 16;
	map->grid = malloc_grid(16, 16);
	if (!map->grid)
		return (0);

	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			map->grid[i][j] = test_grid[i][j];
			j++;
		}
		i++;
	}
}

void init_player(t_game *g)
{
	g->player.position.x = 8.5;
	g->player.position.y = 8.5;
	g->player.angle = 0.1f;
}

int main(int argc,char **argv)
{
        t_game game;


        //TODO: faire la struct du jeux et toute les struct qui en decoule 
        //TODO: parser la map
        //parser(&game.map)

        //TODO: init le jeux
        game.mlx = NULL;
        init_player(&game);
        memset(&game.input, 0, sizeof(t_input));

	load_test_map(&game.map);
        run_game(&game);
        (void)argc;
        (void)argv;

	if (ac != 2)
	{
		printf("Usage: %s <map.cub>\n", av[0]);
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (parse_file(av[1], &game) == -1)
	{
		printf("Error\n Invalid map file.\n");
		free_game(&game);
		return (1);
	}
	printf("=== PARSING OK ===\n");
	print_textures(&game.config.parse);
	print_colors(&game.config);
	print_player(&game.config.parse);
	print_map(&game.map);
	free_game(&game);
	return (0);
}
