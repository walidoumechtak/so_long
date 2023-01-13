/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:16:31 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/13 08:55:51 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_to_array(char *map_path)
{
	int		fd_map;
	char	*line;
	char	*readed_map;
	char	*tmp;

	readed_map = NULL;
	fd_map = open(map_path, O_RDONLY);
	if (fd_map < 0)
		return (NULL);
	line = get_next_line(fd_map);
	while (line != NULL)
	{
		tmp = ft_strjoin(readed_map, line);
		free(readed_map);
		readed_map = tmp;
		free(line);
		line = get_next_line(fd_map);
	}
	free(line);
	close(fd_map);
	return (readed_map);
}
