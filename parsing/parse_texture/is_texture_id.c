/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:39:16 by akarapkh          #+#    #+#             */
/*   Updated: 2025/11/27 05:48:38 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

int	is_texture_id(char *line)
{
	size_t						i;
	static const char *const	ids[] = {
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
			return (1);
		i++;
	}
	return (0);
}
