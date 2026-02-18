/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarapkh <akarapkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 05:25:37 by akarapkh          #+#    #+#             */
/*   Updated: 2025/11/28 06:28:55 by akarapkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2064
# endif

# if BUFFER_SIZE >= 10000000
#  define MAX_FD 128
# else
#  define MAX_FD 1024
# endif

# include <unistd.h>

char		*get_next_line(int fd);

#endif