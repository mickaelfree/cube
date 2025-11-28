/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 23:44:19 by akarapkh          #+#    #+#             */
/*   Updated: 2025/11/28 05:01:03 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cube.h"
# include "vectors.h"
# include <fcntl.h>

typedef enum s_texture_id
{
	ID_NO = 1,
	ID_SO = 1 << 1,
	ID_WE = 1 << 2,
	ID_EA = 1 << 3,
	ID_COUNT = 1 << 4
}				t_texture_id;

typedef enum s_color_id
{
	ID_C = 1,
	ID_F = 1 << 1,
}				t_color_id;

typedef struct s_parser
{
	t_vector	lines;
	t_vector	map_lines;
	int			textures_set;
	int			colors_set;
}				t_parser;

// UTILS
char			*skip_spaces(char *str);
int				is_empty_line(char *line);

// PARSE MAP
int				is_map_char(char c);
int				store_map_line(char *line, t_vector *map_lines);

// PARSE TEXTURE
int				is_texture_id(char *line);
int				set_texture_path(char *line, t_parse *parse, size_t id);
int				parse_texture_line(char *line, t_parse *parse,
					t_parser *parser);

// PARSE COLORS
int				is_color_id(char *line);
int				parse_color_line(char *line, t_config *config,
					t_parser *parser);

// PARSE FILE
int				parse_lines(t_parser *parser, t_config *config);

// READ FILE
int				validate_extension(const char *filename);

#endif