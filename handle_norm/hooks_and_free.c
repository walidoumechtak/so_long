/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:00:17 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/15 08:51:16 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	hooks_and_free(t_long *ptr)
{
	mlx_hook(ptr->mlx_win, 2, 0, hand_event, ptr);
	mlx_hook(ptr->mlx_win, 17, 0, ft_exit, ptr);
	mlx_loop(ptr->mlx_ptr);
	free_all_ele(ptr);
	free(ptr->arr);
	free(ptr->flood_arr);
	free(ptr->mlx_ptr);
	free(ptr);
}
