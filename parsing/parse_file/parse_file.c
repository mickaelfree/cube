/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 04:09:57 by akarapkh          #+#    #+#             */
/*   Updated: 2025/12/10 02:57:48 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "parsing.h"
#include "vectors.h"

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

static int	parse_file_content(t_parser *parser, t_game *game)
{
	if (parse_lines(parser, &game->config) == -1)
	{
		printf("could not parse lines\n");
		return (-1);
	}
	if (parse_map(parser, game) == -1)
		return (-1);
	if (validate_map(game) == -1) 
		return (-1);
	return (0);
}

static void	init_parser(t_parser *parser)
{
	init_vector(&parser->lines, sizeof(char *));
	init_vector(&parser->map_lines, sizeof(char *));
	parser->colors_set = 0;
	parser->textures_set = 0;
}
