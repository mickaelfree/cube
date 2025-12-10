/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:26:18 by akarapkh          #+#    #+#             */
/*   Updated: 2025/12/10 03:29:31 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "vectors.h"
#include "libft.h"

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
		size_t len = ft_strlen(*line_ptr);
        if (len > 0 && (*line_ptr)[len - 1] == '\n')
            (*line_ptr)[len - 1] = '\0';
		printf("Processing line: '%s'\n", *line_ptr);
		if (process_line(*line_ptr, parser, config, &in_map))
		{
			printf("could not process line\n");
			return (-1);
		}
		i++;
	}
	printf("Textures set: %d, Colors set: %d\n", parser->textures_set, parser->colors_set);
	if (parser->textures_set != 4 || parser->colors_set != 2)
	{
		printf("textures or colors not set correctly\n");
		return (-1);
	}
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
    
    printf("  → trimmed: '%s'\n", trimmed);
    printf("  → is_texture_id: %d\n", is_texture_id(trimmed));
    printf("  → is_color_id: %d\n", is_color_id(trimmed));
    
    if (*in_map || is_map_char(*trimmed))
    {
        *in_map = 1;
        return (store_map_line(line, &p->map_lines));
    }
    if (is_empty_line(line))
        return (0);
    if (is_texture_id(trimmed))
    {
        printf("  → Calling parse_texture_line\n");
        return (parse_texture_line(trimmed, &cfg->parse, p));
    }
    if (is_color_id(trimmed))
    {
        printf("  → Calling parse_color_line\n");
        return (parse_color_line(trimmed, cfg, p));
    }
    printf("  → Line not recognized!\n");
    return (-1);
}
