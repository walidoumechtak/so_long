/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:22:20 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/14 11:19:36 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void  flood_fill(t_long *ptr, t_player start)
{
    if((ptr->flood_arr[start.z][start.y] != '0' && ptr->flood_arr[start.z][start.y] != 'C' 
    && ptr->flood_arr[start.z][start.y] != 'E' && ptr->flood_arr[start.z][start.y] != 'P'))
        return ;
    ptr->flood_arr[start.z][start.y] = 'T';    
    flood_fill(ptr, (t_player){(start.y) + 1, start.z, 0, 0});
    flood_fill(ptr, (t_player){(start.y) - 1, start.z, 0, 0});
    flood_fill(ptr, (t_player){start.y, (start.z) + 1, 0, 0});
    flood_fill(ptr, (t_player){start.y, (start.z) - 1, 0, 0});
}
