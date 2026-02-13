/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 00:55:33 by akarapkh          #+#    #+#             */
/*   Updated: 2026/02/12 03:29:33 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "vectors.h"

static void	free_lines_vector(t_vector *vec);

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
