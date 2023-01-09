/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:04:55 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/09 16:21:21 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hand_event(int key, t_long *ptr)
{
	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
		exit (0);
	}
	return (0);	
}

int	ft_exit(t_long *ptr)
{
	mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
	exit (0);
}

int	main(int ac, char **av)
{
	t_long *ptr;
	
	// ================================
	if (ac == 2)
	{
		ptr = malloc(sizeof(t_long));
		if (!ptr)
			return (1);
		ptr->string = map_to_array(av[1]);
		if (is_5_comp(ptr->string) == 0)
		{
			free(ptr);
			ft_printf("Error : Invalid map\n");
			return (0);
		}
		ptr->mlx_ptr = mlx_init();
		if (!(ptr->mlx_ptr))
			return (1);
		ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, 600, 600, "so_long");
		if (!(ptr->mlx_win))
		{
			free(ptr->mlx_win);
			return (1);
		}
		// ptr->img.mlx_img = mlx_new_image(ptr->mlx_ptr, 600, 600);
		// mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.mlx_img, 0, 0);

		mlx_hook(ptr->mlx_win, 2, 0, hand_event, ptr);
		mlx_hook(ptr->mlx_win, 17, 0, ft_exit, ptr);
		mlx_loop(ptr->mlx_ptr);

		free(ptr->mlx_ptr);
		free(ptr);	
	}
	// =================================
}