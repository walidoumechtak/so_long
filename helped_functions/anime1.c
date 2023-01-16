/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:04:17 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/16 11:20:26 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	anime1(t_long *ptr)
{
	if (ptr->count == 0)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.exit_img,
			60 * ptr->exit.ex1, 60 * ptr->exit.ex2);
	}
	else if (ptr->count == 2000)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.ship_90, 60
			* ptr->exit.ex1, 60 * ptr->exit.ex2);
	}
	else if (ptr->count == 4000)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.ship_180,
			60 * ptr->exit.ex1, 60 * ptr->exit.ex2);
	}
	else if (ptr->count == 6000)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.ship_270,
			60 * ptr->exit.ex1, 60 * ptr->exit.ex2);
		ptr->count = -2000;
	}
	ptr->count += 2;
	return (1);
}
