/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image_addr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:28:06 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/16 06:26:15 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_exit(t_long *ptr, void *img)
{
	if (img == NULL)
	{
		free_mlx_res(ptr);
	}
}

void	fill_parttwo(t_long *ptr)
{
	ptr->img.bottom_img = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"xpm_files/bottom.xpm", &(ptr->img.s1), &(ptr->img.s2));
	free_exit(ptr, ptr->img.bottom_img);
	ptr->img.right_img = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"xpm_files/right.xpm", &(ptr->img.s1), &(ptr->img.s2));
	free_exit(ptr, ptr->img.right_img);
	ptr->img.collect_img = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"xpm_files/col.xpm", &(ptr->img.c1), &(ptr->img.c2));
	free_exit(ptr, ptr->img.collect_img);
	ptr->img.exit_img = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"xpm_files/exit.xpm", &(ptr->img.x1), &(ptr->img.x2));
	free_exit(ptr, ptr->img.exit_img);
	ptr->img.ship_90 = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"xpm_files/90.xpm", &(ptr->img.s1), &(ptr->img.s2));
	free_exit(ptr, ptr->img.ship_90);
	ptr->img.ship_180 = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"xpm_files/180.xpm", &(ptr->img.s1), &(ptr->img.s2));
	free_exit(ptr, ptr->img.ship_180);
	ptr->img.ship_270 = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"xpm_files/270.xpm", &(ptr->img.s1), &(ptr->img.s2));
	free_exit(ptr, ptr->img.ship_270);
}

void	fill_image_addr(t_long *ptr)
{
	ptr->img.back_img = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"xpm_files/background.xpm", &(ptr->img.x), &(ptr->img.y));
	free_exit(ptr, ptr->img.back_img);
	ptr->img.wall_img = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"xpm_files/wall.xpm", &(ptr->img.m), &(ptr->img.n));
	free_exit(ptr, ptr->img.wall_img);
	ptr->img.enemy_img = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"xpm_files/enemy.xpm", &(ptr->img.e1), &(ptr->img.e2));
	free_exit(ptr, ptr->img.enemy_img);
	ptr->img.ship_img = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"xpm_files/ship.xpm", &(ptr->img.s1), &(ptr->img.s2));
	free_exit(ptr, ptr->img.ship_img);
	ptr->img.left_img = mlx_xpm_file_to_image(ptr->mlx_ptr,
			"xpm_files/left.xpm", &(ptr->img.s1), &(ptr->img.s2));
	free_exit(ptr, ptr->img.left_img);
	fill_parttwo(ptr);
}
