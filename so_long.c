/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:04:55 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/08 20:32:02 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(int key, t_long *ptr)
{
	t_long	*s;
	
	s = ptr;

	ft_printf("%d\n", key);
	// if (key == 53 || key == 1)
    // {
		mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
		exit(0);
    // }
	return (key);
}

int	main(void)
{
	t_long *ptr;

	ptr = malloc(sizeof(t_long));
	if (!ptr)
		return (1);
	ptr->mlx_ptr = mlx_init();
	if (!(ptr->mlx_ptr))
		return (1);
	ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, 600, 600, "so_long");
	if (!(ptr->mlx_win))
	{
		free(ptr->mlx_win);
		return (1);
	}
	ptr->img.mlx_img = mlx_new_image(ptr->mlx_ptr, 600, 600);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.mlx_img, 0, 0);

	mlx_hook(ptr->mlx_win, 2, 0, destroy, ptr);
	mlx_mouse_hook(ptr->mlx_win, destroy, ptr);
	mlx_loop(ptr->mlx_ptr);

	free(ptr->mlx_ptr);
	free(ptr);
}