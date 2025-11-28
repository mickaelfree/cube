/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 04:49:22 by akarapkh          #+#    #+#             */
/*   Updated: 2025/11/28 04:07:08 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

static int	get_texture_id(char *line);

int	parse_texture_line(char *line, t_parse *parse, t_parser *parser)
{
	size_t	id;

	id = get_texture_id(line);
	if (!id)
		return (-1);
	if (set_texture_path(line, parse, id) == -1)
		return (-1);
	parser->textures_set++;
	return (0);
}

static int	get_texture_id(char *line)
{
	size_t				i;
	const char *const	ids[] = {
	[ID_NO] = "NO ",
	[ID_SO] = "SO ",
	[ID_WE] = "WE ",
	[ID_EA] = "EA ",
	};

	if (!line)
		return (-1);
	i = 0;
	while (i < ID_COUNT)
	{
		if (ft_strncmp(line, ids[i], 3) == 0)
			return (i);
		i++;
	}
	return (0);
}
