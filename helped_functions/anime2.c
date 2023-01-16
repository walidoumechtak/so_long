/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:04:17 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/16 09:36:48 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	animation(t_long *ptr, int i, int j)
{
	if (ptr->count2 == 0)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.collect_img,
			60 * j, 60 * i);
	}
	else if (ptr->count2 == 2000)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.col90_img,
			60 * j, 60 * i);
	}
	else if (ptr->count2 == 4000)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.col180_img,
			60 * j, 60 * i);
	}
	else if (ptr->count2 == 6000)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.col270_img,
			60 * j, 60 * i);
		ptr->count2 = -2000;
	}
	ptr->count2 += 100;
}

int	anime2(t_long *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr->arr[i])
	{
		j = 0;
		while (ptr->arr[i][j])
		{
			if (ptr->arr[i][j] == 'C')
				animation(ptr, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
