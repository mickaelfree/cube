/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:26:18 by akarapkh          #+#    #+#             */
/*   Updated: 2025/11/27 02:04:34 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "vectors.h"

static int	process_line(char *line, t_parser *p, t_config *cfg, int *in_map);

int	parse_lines(t_parser *parser, t_config *config)
{
	size_t	i;
	char	**line_ptr;
	int		in_map;

	i = 0;
	in_map = 0;
	while (i < parser->lines.size)
	{
		line_ptr = (char **)at_vector(&parser->lines, i);
		if (process_line(*line_ptr, parser, config, &in_map))
			return (-1);
		i++;
	}
	if (parser->textures_set != 4 || parser->colors_set != 2)
		return (-1);
	return (0);
}

static int	process_line(char *line, t_parser *p, t_config *cfg, int *in_map)
{
	char	*trimmed;

	trimmed = skip_spaces(line);
	if (*in_map || is_map_char(*trimmed))
	{
		*in_map = 1;
		return (store_map_line(line, &p->map_lines));
	}
	if (is_empty_line(line))
		return (0);
	if (is_texture_id(trimmed))
		return (parse_texture_line(trimmed, &cfg->parse, p));
	if (is_color_id(trimmed))
		return (parse_color_line(trimmed, cfg, p));
	return (-1);
}
