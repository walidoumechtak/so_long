/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:22:20 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/13 09:58:52 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void  flood_fill(char **arr, t_long length, t_long start)
{
    
    if (start.x < 0 || start.x > length.x || start.y < 0 || start.y > length.y 
    || arr[start.y][start.x] == 'F' || arr[start.y][start.x] != '1')
        return ;

    arr[start.y][start.x] = 'F';

    flood_fill(arr,  length,  (t_point){start.x-1, start.y});
    flood_fill(arr,  length,  (t_point){start.x+1, start.y});
    flood_fill(arr,  length,  (t_point){start.x, start.y-1});
    flood_fill(arr,  length,  (t_point){start.x, start.y+1});
}
