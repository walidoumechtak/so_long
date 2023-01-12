/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image_addr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:28:06 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/12 12:29:31 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_image_addr(t_long *ptr)
{
	ptr->img.back_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/background.xpm", &(ptr->img.x), &(ptr->img.y));
	ptr->img.wall_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/wall.xpm", &(ptr->img.m), &(ptr->img.n));
	ptr->img.enemy_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/enemy.xpm", &(ptr->img.e1), &(ptr->img.e2));
	ptr->img.ship_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/ship.xpm", &(ptr->img.s1), &(ptr->img.s2));
	ptr->img.left_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/left.xpm", &(ptr->img.s1), &(ptr->img.s2));
	ptr->img.bottom_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/bottom.xpm", &(ptr->img.s1), &(ptr->img.s2));
	ptr->img.right_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/right.xpm", &(ptr->img.s1), &(ptr->img.s2));
	ptr->img.collect_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/col.xpm", &(ptr->img.c1), &(ptr->img.c2));
	ptr->img.exit_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/exit.xpm", &(ptr->img.x1), &(ptr->img.x2));
}