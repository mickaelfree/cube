/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:44:32 by akarapkh          #+#    #+#             */
/*   Updated: 2025/12/10 06:37:56 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "parsing.h"

static int	parse_rgb(char *str, int *r, int *g, int *b);
static int	parse_single_value(char *str, int *value);
static int	set_floor_color(t_config *cfg, int r, int g, int b);
static int	set_ceiling_color(t_config *cfg, int r, int g, int b);

int	parse_color_line(char *line, t_config *config, t_parser *parser)
{
	char	type;
	int		r;
	int		g;
	int		b;
	int		color_id;

	type = *line;
	if (type == 'F')
		color_id = ID_F;
	else
		color_id = ID_C;
	if (parser->colors_set & color_id)
		return (-1);
	if (parse_rgb(line + 1, &r, &g, &b) == -1)
		return (-1);
	if (type == 'F')
		set_floor_color(config, r, g, b);
	else
		set_ceiling_color(config, r, g, b);
	parser->colors_set |= color_id;
	return (0);
}

static int	parse_rgb(char *str, int *r, int *g, int *b)
{
	int	offset;
	int i;

	i = 0;
	str = skip_spaces(str);
	offset = parse_single_value(str, r);
	if (offset == -1 || str[offset] != ',')
		return (-1);
	str = skip_spaces(str + offset + 1);
	offset = parse_single_value(str, g);
	if (offset == -1 || str[offset] != ',')
		return (-1);
	str = skip_spaces(str + offset + 1);
	offset = parse_single_value(str, b);
	if (offset == -1)
		return (-1);
	i = offset;
	str = skip_spaces(str + i);
	if (*str != '\0')
		return (-1);
	return (0);
}

static int	parse_single_value(char *str, int *value)
{
	int	i;

	i = 0;
	*value = 0;
	while (str[i] && str[i] != ',')
	{
		if (str[i] >= '0' && str[i] <= '9')
			*value = *value * 10 + (str[i] - '0');
		else if (str[i] != ' ' && str[i] != '\t')
			return (-1);
		i++;
	}
	if (*value < 0 || *value > 255)
		return (-1);
	return (i);
}

static int	set_floor_color(t_config *cfg, int r, int g, int b)
{
	cfg->floor_r = r;
	cfg->floor_g = g;
	cfg->floor_b = b;
	cfg->parse.floor_color = (r << 16) | (g << 8) | b;
	return (0);
}

static int	set_ceiling_color(t_config *cfg, int r, int g, int b)
{
	cfg->ceiling_r = r;
	cfg->ceiling_g = g;
	cfg->ceiling_b = b;
	cfg->parse.ceiling_color = (r << 16) | (g << 8) | b;
	return (0);
}
