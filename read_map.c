/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:16:31 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/09 15:49:27 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    *split_map_name(char *map_path)
{
    // char    *map_name;
    char    **splited_path;

    splited_path = ft_split(map_path, '/');
    return (splited_path[1]);
}

char    *map_to_array(char *map_path)
{
    int fd_map;
    // char    *map_name;
    char    *line;
    char    *readed_map;
    char    *tmp;
    
    readed_map = NULL;
    // map_name = split_map_name(map_path);
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

// int main(int ac, char **av)
// {
//     char *s;
//     int i = 0;
//     if (ac == 2)
//     {
//         s = map_to_array(av[1]);
//         if (s == NULL)
//             return (0); 
//         while (s[i])
//         {
//             printf("%c", s[i]);
//             i++;
//         }   
//     }   
// }