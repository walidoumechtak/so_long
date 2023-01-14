/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:04:55 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/14 17:54:49 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ^ : 126, > : 124, down : 125, < : 123
// ================================================================================================

void	img_to_window(t_long *ptr, int y, int y2, int dirction)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, ptr->img.s1 * (ptr->p.y), y);
	if (dirction == 126)
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.ship_img, ptr->img.s1 * (ptr->p.y), y);
	else
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.bottom_img, ptr->img.s1 * (ptr->p.y), y);
		
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, ptr->img.s1 * (ptr->p.y), y2);
}

void	top_and_down(t_long *ptr, int dirction, int y, int y2)
{
	if (dirction == 126)
	{
		ptr->boll1 = ptr->p.z - 1;
		ptr->boll2 = -60;
	}
	else
	{
		ptr->boll1 = ptr->p.z + 1;
		ptr->boll2 = 60;
	}
	if (ptr->arr[ptr->boll1][ptr->p.y] != 'E')
		{	
			y2 = ptr->img.s2 * ptr->p.z;
			y = y2 + ptr->boll2;
			img_to_window(ptr, y, y2, dirction);
			
			ptr->p.z = y / 60;
			ptr->p.is_step = 1;
			if (ptr->arr[(ptr->p.z)][ptr->p.y] == 'C')
			{
				ptr->collect_size--;
				ptr->arr[(ptr->p.z)][ptr->p.y] = '0';
			}
		}
		else if (ptr->arr[(ptr->boll1)][ptr->p.y] == 'E' && ptr->collect_size == 0)
			ptr->is_ready_to_exit = 1;	
}

int	hand_event(int key, t_long *ptr)
{
	int	y;
	int	y2;
	
	ptr->p.is_step = 0;
	y = 0;
	y2 = 0;
	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
		exit (0);
	}
	else if (key == 126 && ptr->arr[(ptr->p.z) - 1][ptr->p.y] != '1')
	{
		top_and_down(ptr, key, y, y2);
		ptr->img.s2 = 60;
	}
	else if (key == 125 && ptr->arr[(ptr->p.z) + 1][ptr->p.y] != '1')
	{
		top_and_down(ptr, 125, y, y2);
		ptr->img.s2 = 60; // retunr to the real image size because we multiplay be the cord of the palyer
		// if (ptr->arr[(ptr->p.z) + 1][ptr->p.y] != 'E')
		// {
		// 	y2 = ptr->img.s2 * ptr->p.z;
		// 	y = y2 + 60;
		// 	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, ptr->img.s1 * (ptr->p.y), y);
		// 	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.bottom_img, ptr->img.s1 * (ptr->p.y), y);
		// 	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, ptr->img.s1 * (ptr->p.y), y2);
		// 	ptr->img.s2 = 60;
		// 	ptr->p.z = y / 60;
		// 	ptr->p.is_step = 1;
		// 	if (ptr->arr[(ptr->p.z)][ptr->p.y] == 'C')
		// 	{
		// 		ptr->collect_size--;
		// 		ptr->arr[(ptr->p.z)][ptr->p.y] = '0';
		// 	}
		// }
		// else if (ptr->arr[(ptr->p.z) + 1][ptr->p.y] == 'E' && ptr->collect_size == 0)
		// 		ptr->is_ready_to_exit = 1;
	}
	else if (key == 124 && ptr->arr[(ptr->p.z)][ptr->p.y + 1] != '1') // ===============
	{
		if(ptr->arr[(ptr->p.z)][ptr->p.y + 1] != 'E')
		{
			y2 = ptr->img.s1 * ptr->p.y;
			y = y2 + 60;
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, y,ptr->img.s2 * (ptr->p.z));
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.right_img, y,ptr->img.s2 * (ptr->p.z));
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, y2,ptr->img.s2 * (ptr->p.z));
			ptr->img.s1 = 60;
			ptr->p.y = y / 60;
			ptr->p.is_step = 1;
			if (ptr->arr[(ptr->p.z)][ptr->p.y] == 'C')
			{
				ptr->collect_size--;
				ptr->arr[(ptr->p.z)][ptr->p.y] = '0';
			}
		}
		else if (ptr->arr[(ptr->p.z)][ptr->p.y + 1] == 'E' && ptr->collect_size == 0)
			ptr->is_ready_to_exit = 1;
	}
	else if (key == 123 && ptr->arr[(ptr->p.z)][ptr->p.y - 1] != '1') // ===============
	{
		if (ptr->arr[(ptr->p.z)][ptr->p.y - 1] != 'E')
		{
			y2 = ptr->img.s1 * ptr->p.y;
			y = y2 - 60;
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, y,ptr->img.s2 * (ptr->p.z));
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.left_img, y,ptr->img.s2 * (ptr->p.z));
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, y2,ptr->img.s2 * (ptr->p.z));
			ptr->img.s1 = 60;
			ptr->p.y = y / 60;
			ptr->p.is_step = 1;
			if (ptr->arr[(ptr->p.z)][ptr->p.y] == 'C')
			{
				ptr->collect_size--;
				ptr->arr[(ptr->p.z)][ptr->p.y] = '0';
			}
		}
		else if (ptr->arr[(ptr->p.z)][ptr->p.y - 1] == 'E' && ptr->collect_size == 0)
			ptr->is_ready_to_exit = 1;
	}
	if (ptr->p.is_step == 1)
	{
		(ptr->p.steps)++;
		ft_printf("step : %d\n", ptr->p.steps);
	}
	if (ptr->is_ready_to_exit == 1 )
	{
		free_mlx_res(ptr);
		exit (0);
	}
	return (0);
}

// ================================================================================================
int	main(int ac, char **av)
{
	t_long *ptr;
	if (ac == 2)
	{
		ptr = malloc(sizeof(t_long));
		if (!ptr)
			exit (0);
		init_struct_var(ptr, av);
		map_errors(ptr);
		ptr->mlx_ptr = mlx_init();
		if (!(ptr->mlx_ptr))
			return (1);
		ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, ptr->width * 60, ptr->height * 60, "so_long");
		if (!(ptr->mlx_win))
		{
			free(ptr->mlx_win);
			return (1);
		}
		fill_image_addr(ptr);
		put_all_images_to_wind(ptr);
		get_cord_palyer(ptr);
		
		path_flood_fil(ptr);
		hooks_and_free(ptr);
		// while (1);	
	}
}