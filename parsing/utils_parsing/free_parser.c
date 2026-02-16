/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 00:55:33 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/16 17:18:41 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "vectors.h"
#include <stdlib.h>

static void	free_lines_vector(t_vector *vec);

void	free_parse(t_parse *parse)
{
	if (parse->no_texture)
		free(parse->no_texture);
	if (parse->so_texture)
		free(parse->so_texture);
	if (parse->we_texture)
		free(parse->we_texture);
	if (parse->ea_texture)
		free(parse->ea_texture);
	if (parse->raw_map)
		free(parse->raw_map);
	parse->no_texture = NULL;
	parse->so_texture = NULL;
	parse->we_texture = NULL;
	parse->ea_texture = NULL;
	parse->raw_map = NULL;
}

void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
}

void	free_parser(t_parser *parser)
{
	free_lines_vector(&parser->lines);
	free_lines_vector(&parser->map_lines);
}

static void	free_lines_vector(t_vector *vec)
{
	size_t	i;
	char	**line;

	i = 0;
	while (i < vec->size)
	{
		line = (char **)at_vector(vec, i);
		if (*line)
			free(*line);
		i++;
	}
	free_vector(vec);
}
