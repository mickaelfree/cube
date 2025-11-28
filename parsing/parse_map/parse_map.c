/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:24:31 by akarapkh          #+#    #+#             */
/*   Updated: 2025/11/28 09:44:57 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "vectors.h"

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

static int	get_map_width(t_vector *map_lines)
{
	size_t i;
	size_t len;
	size_t max_w;
	char **line;

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
