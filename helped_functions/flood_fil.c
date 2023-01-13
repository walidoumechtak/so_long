/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:22:20 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/13 18:46:17 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void  flood_fill(t_long *ptr, t_player start)
{
    if (ptr->flood == 9)
    {
        ptr->flood_arr[ptr->p.z][ptr->p.y] = '0';
        ptr->flood = 1;
    }
    if ((ptr->p.y < 0 || ptr->p.y >= ptr->width || ptr->p.z < 0 || ptr->p.z >= ptr->height 
    || ptr->flood_arr[ptr->p.z][ptr->p.y] == 'W' || ptr->flood_arr[ptr->p.z][ptr->p.y] != '0'))
    {
        return ;
    }
    ptr->flood_arr[start.z][start.y] = 'W';
    flood_fill(ptr, (t_player){(start.y) + 1, start.z, start.steps, start.is_step});
    flood_fill(ptr, (t_player){(start.y) - 1, start.z, start.steps, start.is_step});
    flood_fill(ptr, (t_player){start.y, (start.z) + 1, start.steps, start.is_step});
    flood_fill(ptr, (t_player){start.y, (start.z) - 1, start.steps, start.is_step});
}
