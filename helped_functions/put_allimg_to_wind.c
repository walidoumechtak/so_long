/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_allimg_to_wind.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:44:50 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/15 06:49:30 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_exit(t_long *ptr)
{
	free_mlx_res(ptr);
	return (0);
}

void	put_all_images_to_wind(t_long *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr->arr[i])
		{
			j = 0;
			while (ptr->arr[i][j])
			{
				mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, (ptr->img.x) * j, (ptr->img.y) * i);
				if (ptr->arr[i][j] == '1')
					mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.wall_img, (ptr->img.m) * j, (ptr->img.n) * i);
				else if (ptr->arr[i][j] == 'T')
					mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.enemy_img, (ptr->img.e1) * j, (ptr->img.e2) * i);
				else if (ptr->arr[i][j] == 'P')
					mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.ship_img, (ptr->img.s1) * j, (ptr->img.s2) * i);
				else if (ptr->arr[i][j] == 'C')
					mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.collect_img, (ptr->img.c1) * j, (ptr->img.c2) * i);
				else if (ptr->arr[i][j] == 'E')
					mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.exit_img, (ptr->img.x1) * j, (ptr->img.x2) * i);
				j++;
			}
			i++;
		}
}