/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:24:31 by akarapkh          #+#    #+#             */
/*   Updated: 2025/12/10 03:33:53 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "vectors.h"

static int	alloc_grid(t_map *map);
static int	build_grid_map(t_parse *parse, t_map *map);
static int	build_raw_map(t_parser *parser, t_parse *parse);
static int	get_map_width(t_vector *map_lines);

int	parse_map(t_parser *parser, t_game *game)
{
	if (parser->map_lines.size == 0)
		return (-1);
	game->map.height = (int)parser->map_lines.size;
	game->map.width = get_map_width(&parser->map_lines);
	if (build_raw_map(parser, &game->config.parse) == -1)
		return (-1);
	if (build_grid_map(&game->config.parse, &game->map) == -1)
		return (-1);
	return (0);
}

static int	build_grid_map(t_parse *parse, t_map *map)
{
	int	y;

	if (alloc_grid(map) == -1)
		return (-1);
	y = 0;
	while (y < map->height)
	{
		if (fill_grid_row(parse->raw_map[y], map->grid[y], map->width) == -1)
			return (-1);
		y++;
	}
	return (0);
}

static int	alloc_grid(t_map *map)
{
	int	i;

	map->grid = malloc(sizeof(int *) * map->height);
	if (!map->grid)
		return (-1);
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = malloc(sizeof(int) * map->width);
		if (!map->grid[i])
			return (-1);
		ft_memset(map->grid[i], -1, sizeof(int) * map->width);
		i++;
	}
	return (0);
}

static int	build_raw_map(t_parser *parser, t_parse *parse)
{
	size_t	i;
	char	**line;

	parse->raw_map = malloc(sizeof(char *) * (parser->map_lines.size + 1));
	if (!parse->raw_map)
		return (-1);
	i = 0;
	while (i < parser->map_lines.size)
	{
		line = (char **)at_vector(&parser->map_lines, i);
		parse->raw_map[i] = ft_strtrim(*line, "\n");
		if (!parse->raw_map[i])
			return (-1);
		i++;
	}
	parse->raw_map[i] = NULL;
	return (0);
}

static int	get_map_width(t_vector *map_lines)
{
	size_t	i;
	size_t	len;
	size_t	max_w;
	char	**line;

	i = 0;
	max_w = 0;
	while (i < map_lines->size)
	{
		line = (char **)at_vector(map_lines, i);
		len = ft_strlen(*line);
		if (len > 0 && (*line)[len - 1] == '\n')
			len--;
		if (len > max_w)
			max_w = len;
		i++;
	}
	return ((int)max_w);
}
