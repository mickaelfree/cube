/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:26:18 by akarapkh          #+#    #+#             */
/*   Updated: 2025/12/11 23:09:49 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

static int	process_line(char *line, t_parser *p, t_config *cfg, int *in_map);
static void	trim_newline(char *line);
static int	validate_parser(t_parser *parser);

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
		trim_newline(*line_ptr);
		if (process_line(*line_ptr, parser, config, &in_map))
			return (-1);
		i++;
	}
	return (validate_parser(parser));
}

static void	trim_newline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static int	validate_parser(t_parser *parser)
{
	if (parser->textures_set != 4)
		return (-1);
	if (parser->colors_set != (ID_F | ID_C))
		return (-1);
	if (parser->map_lines.size == 0)
		return (-1);
	return (0);
}

static int	process_line(char *line, t_parser *p, t_config *cfg, int *in_map)
{
	char	*trimmed;
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	trimmed = skip_spaces(line);
	if (is_empty_line(line))
	{
		if (*in_map)
			return (-1);
		return (0);
	}
	if (is_texture_id(trimmed))
		return (parse_texture_line(trimmed, &cfg->parse, p));
	if (is_color_id(trimmed) != -1)
		return (parse_color_line(trimmed, cfg, p));
	if (*in_map || is_map_char(*trimmed))
	{
		*in_map = 1;
		return (store_map_line(line, &p->map_lines));
	}
	return (-1);
}
