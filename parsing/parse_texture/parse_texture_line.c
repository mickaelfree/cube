/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 04:49:22 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/11 18:33:32 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "ft_dprintf.h"

static int	get_texture_id(char *line);

int	parse_texture_line(char *line, t_parse *parse, t_parser *parser)
{
	int	id;

	id = get_texture_id(line);
	if (id == -1)
		return (-1);
	if (set_texture_path(line, parse, id) == -1)
	{
		ft_dprintf(2, "Failed to set texture path for ID %d\n", id);
		return (-1);
	}
	parser->textures_set++;
	return (0);
}

static int	get_texture_id(char *line)
{
	int				i;
	const char *const	ids[] = {
	[ID_NO] = "NO",
	[ID_SO] = "SO",
	[ID_WE] = "WE",
	[ID_EA] = "EA",
	};

	if (!line)
		return (-1);
	i = 1;
	while (i < ID_COUNT)
	{
		if (ids[i] && ft_strncmp(line, ids[i], 2) == 0)
		{
			// Vérifier que le caractère suivant est un whitespace
			if (line[2] == ' ' || line[2] == '\t')
				return (i);
		}
		i++;
	}
	return (-1);
}
