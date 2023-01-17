/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:04:55 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/17 20:03:05 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ready_exit(t_long *ptr)
{
	if (ptr->is_ready_to_exit == 1)
	{
		free_mlx_res(ptr);
	}
}

int	hand_event(int key, t_long *ptr)
{
	int	y;
	int	y2;

	ptr->p.is_step = 0;
	y = 0;
	y2 = 0;
	if (key == 53)
		free_mlx_res(ptr);
	else if (key == 126 && ptr->arr[(ptr->p.z) - 1][ptr->p.y] != '1')
		top_and_down(ptr, key, y, y2);
	else if (key == 125 && ptr->arr[(ptr->p.z) + 1][ptr->p.y] != '1')
		top_and_down(ptr, 125, y, y2);
	else if (key == 124 && ptr->arr[(ptr->p.z)][ptr->p.y + 1] != '1')
		right_and_left(ptr, key, y, y2);
	else if (key == 123 && ptr->arr[(ptr->p.z)][ptr->p.y - 1] != '1')
		right_and_left(ptr, key, y, y2);
	if (ptr->p.is_step == 1)
	{
		(ptr->p.steps)++;
		ft_printf("step : %d\n", ptr->p.steps);
	}
	ready_exit(ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_long	*ptr;

	if (ac == 2)
	{
		ptr = malloc(sizeof(t_long));
		if (!ptr)
			exit(0);
		ptr->mlx_ptr = mlx_init();
		if (!(ptr->mlx_ptr))
			free_mlx_res(ptr);
		init_struct_var(ptr, av);
		map_errors(ptr, av);
		ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, ptr->width * 60, ptr->height
				* 60, "so_long");
		if (!(ptr->mlx_win))
		{
			free_mlx_res(ptr);
		}
		fill_image_addr(ptr);
		put_all_images_to_wind(ptr);
		get_cord_palyer(ptr);
		path_flood_fil(ptr);
		hooks_and_free(ptr);
	}
}
