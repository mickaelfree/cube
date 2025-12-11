/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 04:09:57 by akarapkh          #+#    #+#             */
/*   Updated: 2025/12/11 04:36:32 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "parsing.h"

static int	parse_file_content(t_parser *parser, t_game *game);
static void	init_parser(t_parser *parser);

int	parse_file(const char *filename, t_game *game)
{
	t_parser	parser;

	if (validate_extension(filename) == -1)
	{
		printf("invalid extensuin\n");
		return (-1);
	}
	init_parser(&parser);
	if (read_file(filename, &parser.lines) == -1)
	{
		printf("could not read file\n");
		free_parser(&parser);
		return (-1);
	}
	if (parse_file_content(&parser, game) == -1)
	{
		printf("could not parse file content\n");
		free_parser(&parser);
		return (-1);
	}
	free_parser(&parser);
	return (0);
}

static void	init_parse(t_parse *parse)
{
	parse->no_texture = NULL;
	parse->so_texture = NULL;
	parse->we_texture = NULL;
	parse->ea_texture = NULL;
	parse->ceiling_color = -1;
	parse->floor_color = -1;
	parse->raw_map = NULL;
	parse->map_start = 0;
	parse->player_x = 15;
	parse->player_y = 10;
	parse->player_dir = '\0';
}

static int	parse_file_content(t_parser *parser, t_game *game)
{
    init_parse(&game->config.parse);
    if (parse_lines(parser, &game->config) == -1)
    {
        printf("could not parse lines\n");
        return (-1);
    }
    if (parse_map(parser, game) == -1)
        return (-1);
    if (validate_map(game) == -1) 
        return (-1);
    
    printf("Map dimensions: %d x %d\n", game->map.width, game->map.height);
    printf("Player position: (%.2f, %.2f)\n", game->player.position.x, game->player.position.y);
    printf("Player angle: %.2f\n", game->player.angle);
    printf("Textures: NO=%s, SO=%s, WE=%s, EA=%s\n",
        game->config.parse.no_texture,
        game->config.parse.so_texture,
        game->config.parse.we_texture,
        game->config.parse.ea_texture);
    
    printf("\nMap grid:\n");
    for (int y = 0; y < game->map.height; y++)
    {
        for (int x = 0; x < game->map.width; x++)
            printf("%d", game->map.grid[y][x]);
        printf("\n");
    }
    
    return (0);
}

static void	init_parser(t_parser *parser)
{
	init_vector(&parser->lines, sizeof(char *));
	init_vector(&parser->map_lines, sizeof(char *));
	parser->colors_set = 0;
	parser->textures_set = 0;
}
