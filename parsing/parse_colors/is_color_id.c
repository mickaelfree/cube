/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_color_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 05:38:43 by akarapkh          #+#    #+#             */
/*   Updated: 2025/11/27 05:46:19 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "parsing.h"

int	is_color_id(char *line)
{
    if (!line || !*line)
        return (-1);
    if (*line == 'F' && (line[1] == ' ' || line[1] == '\t'))
        return (ID_F);
    if (*line == 'C' && (line[1] == ' ' || line[1] == '\t'))
        return (ID_C);
    return (-1);
}
