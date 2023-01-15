/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_left_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 05:51:27 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/15 08:37:52 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_to_win_rl(t_long *ptr, int y, int y2, int dirction)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, y,
		ptr->img.s2 * (ptr->p.z));
	if (dirction == 124)
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.right_img,
			y, ptr->img.s2 * (ptr->p.z));
	else
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.left_img,
			y, ptr->img.s2 * (ptr->p.z));
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, y2,
		ptr->img.s2 * (ptr->p.z));
}

void	right_and_left(t_long *ptr, int dirction, int y, int y2)
{
	if (dirction == 124)
	{
		ptr->boll1 = ptr->p.y + 1;
		ptr->boll2 = 60;
	}
	else
	{
		ptr->boll1 = ptr->p.y - 1;
		ptr->boll2 = -60;
	}
	if (ptr->arr[ptr->p.z][ptr->boll1] != 'E')
	{
		y2 = ptr->img.s2 * ptr->p.y;
		y = y2 + ptr->boll2;
		img_to_win_rl(ptr, y, y2, dirction);
		ptr->p.y = y / 60;
		ptr->p.is_step = 1;
		if (ptr->arr[(ptr->p.z)][ptr->p.y] == 'C')
		{
			ptr->collect_size--;
			ptr->arr[(ptr->p.z)][ptr->p.y] = '0';
		}
	}
	else if (ptr->arr[(ptr->p.z)][ptr->boll1] == 'E' && ptr->collect_size == 0)
		ptr->is_ready_to_exit = 1;
}
