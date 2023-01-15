/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_down_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 05:51:27 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/15 06:19:44 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_to_win_td(t_long *ptr, int y, int y2, int dirction)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, ptr->img.s1 * (ptr->p.y), y);
	if (dirction == 126)
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.ship_img, ptr->img.s1 * (ptr->p.y), y);
	else
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.bottom_img, ptr->img.s1 * (ptr->p.y), y);
		
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, ptr->img.s1 * (ptr->p.y), y2);
}

void	top_and_down(t_long *ptr, int dirction, int y, int y2)
{
	if (dirction == 126)
	{
		ptr->boll1 = ptr->p.z - 1;
		ptr->boll2 = -60;
	}
	else
	{
		ptr->boll1 = ptr->p.z + 1;
		ptr->boll2 = 60;
	}
	if (ptr->arr[ptr->boll1][ptr->p.y] != 'E')
		{	
			y2 = ptr->img.s2 * ptr->p.z;
			y = y2 + ptr->boll2;
			img_to_win_td(ptr, y, y2, dirction);
			ptr->p.z = y / 60;
			ptr->p.is_step = 1;
			if (ptr->arr[(ptr->p.z)][ptr->p.y] == 'C')
			{
				ptr->collect_size--;
				ptr->arr[(ptr->p.z)][ptr->p.y] = '0';
			}
		}
		else if (ptr->arr[(ptr->boll1)][ptr->p.y] == 'E' && ptr->collect_size == 0)
			ptr->is_ready_to_exit = 1;	
}