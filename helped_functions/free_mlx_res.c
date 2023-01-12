/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:18:25 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/12 15:18:47 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_mlx_res(t_long *ptr)
{
		mlx_destroy_image(ptr->mlx_ptr, ptr->img.back_img);
		mlx_destroy_image(ptr->mlx_ptr, ptr->img.wall_img);
		mlx_destroy_image(ptr->mlx_ptr, ptr->img.ship_img);
		mlx_destroy_image(ptr->mlx_ptr, ptr->img.right_img);
		mlx_destroy_image(ptr->mlx_ptr, ptr->img.bottom_img);
		mlx_destroy_image(ptr->mlx_ptr, ptr->img.left_img);
		mlx_destroy_image(ptr->mlx_ptr, ptr->img.collect_img);
		mlx_destroy_image(ptr->mlx_ptr, ptr->img.exit_img);
		mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
		free(ptr);
}
