/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:22:20 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/13 10:51:36 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void  flood_fill(t_long *ptr, char **arr, t_long start)
{
    
    if (ptr->p.y < 0 || ptr->p.y > ptr->width || ptr->p.z < 0 || ptr->p.z > ptr->height 
    || arr[ptr->p.z][ptr->p.y] == 'F' || arr[ptr->p.z][ptr->p.y] != '1')
        return ;

    arr[start.y][start.x] = 'F';

    flood_fill(arr, (t_long){ptr->p.y-1, ptr->p.z});
    flood_fill(arr, (t_long){ptr->p.y+1, ptr->p.z});
    flood_fill(arr, (t_long){ptr->p.y, ptr->p.z-1});
    flood_fill(arr, (t_long){ptr->p.y, ptr->p.z+1});
}
