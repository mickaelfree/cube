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

// #include <stdio.h>
// #include "include/cube.h"
// static int	**malloc_grid(int width, int height)
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
// 			while (--i >= 0)
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
// 	int	test_grid[8][8] = {
// 		{1, 1, 1, 1, 1, 1, 1, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 1, 1, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 1, 1, 1, 1, 1, 1, 1}
// 	};

// 	map->width = 8;
// 	map->height = 8;
// 	map->grid = malloc_grid(8, 8);
// 	if (!map->grid)
// 		return (0);

// 	i = 0;
// 	while (i < 8)
// 	{
// 		j = 0;
// 		while (j < 8)
// 		{
// 			map->grid[i][j] = test_grid[i][j];
// 			j++;
// 		}
// 		i++;
// 	}

// 	return (1);
// }

// int main(int argc,char **argv)
// {
//         t_game game;


//         //TODO: faire la struct du jeux et toute les struct qui en decoule 
//         //TODO: parser la map
//         //parser(&game.map)

//         //TODO: init le jeux
//         game.mlx = NULL;

// 	load_test_map(&game.map);
//         run_game(&game);
//         (void)argc;
//         (void)argv;

// }


#include "cube.h"
#include "parsing.h"
#include "libft.h"

static void	print_textures(t_parse *parse)
{
    printf("\n=== TEXTURES ===\n");
    printf("NO: %s\n", parse->no_texture ? parse->no_texture : "(null)");
    printf("SO: %s\n", parse->so_texture ? parse->so_texture : "(null)");
    printf("WE: %s\n", parse->we_texture ? parse->we_texture : "(null)");
    printf("EA: %s\n", parse->ea_texture ? parse->ea_texture : "(null)");
}

static void	print_colors(t_config *config)
{
	printf("\n=== COLORS ===\n");
	printf("Floor:   R=%d G=%d B=%d (0x%06X)\n",
		config->floor_r, config->floor_g, config->floor_b,
		config->parse.floor_color);
	printf("Ceiling: R=%d G=%d B=%d (0x%06X)\n",
		config->ceiling_r, config->ceiling_g, config->ceiling_b,
		config->parse.ceiling_color);
}

static void	print_player(t_parse *parse)
{
	printf("\n=== PLAYER ===\n");
	printf("Position: x=%d, y=%d\n", parse->player_x, parse->player_y);
	printf("Direction: %c\n", parse->player_dir);
}

static void	print_map(t_map *map)
{
	int	x;
	int	y;

	printf("\n=== MAP (%dx%d) ===\n", map->width, map->height);
	printf("raw grid:\n");
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == -1)
				printf(" ");
			else
				printf("%d", map->grid[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

static void	free_game(t_game *game)
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
	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.height)
			free(game->map.grid[i++]);
		free(game->map.grid);
	}
}

int	main(int ac, char **av)
{
	t_game	game;

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
