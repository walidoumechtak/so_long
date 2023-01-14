/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:04:55 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/14 11:54:18 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ^ : 126, > : 124, down : 125, < : 123
// ================================================================================================



int	hand_event(int key, t_long *ptr)
{
	int	y;
	int	y2;
	
	ptr->p.is_step = 0;
	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
		exit (0);
	}
	else if (key == 126 && ptr->arr[(ptr->p.z) - 1][ptr->p.y] != '1') // ===============
	{
		if (ptr->arr[(ptr->p.z) - 1][ptr->p.y] != 'E')
		{	
			y2 = ptr->img.s2 * ptr->p.z;
			y = y2 - 60;
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, ptr->img.s1 * (ptr->p.y), y);
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.ship_img, ptr->img.s1 * (ptr->p.y), y);
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, ptr->img.s1 * (ptr->p.y), y2);
			ptr->img.s2 = 60;
			ptr->p.z = y / 60;
			ptr->p.is_step = 1;
			if (ptr->arr[(ptr->p.z)][ptr->p.y] == 'C')
			{
				ptr->collect_size--;
				ptr->arr[(ptr->p.z)][ptr->p.y] = '0';
			}
		}
		else if (ptr->arr[(ptr->p.z - 1)][ptr->p.y] == 'E' && ptr->collect_size == 0)
			ptr->is_ready_to_exit = 1;
	}
	else if (key == 125 && ptr->arr[(ptr->p.z) + 1][ptr->p.y] != '1') // ===============
	{
		if (ptr->arr[(ptr->p.z) + 1][ptr->p.y] != 'E')
		{
			y2 = ptr->img.s2 * ptr->p.z;
			y = y2 + 60;
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, ptr->img.s1 * (ptr->p.y), y);
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.bottom_img, ptr->img.s1 * (ptr->p.y), y);
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, ptr->img.s1 * (ptr->p.y), y2);
			ptr->img.s2 = 60;
			ptr->p.z = y / 60;
			ptr->p.is_step = 1;
			if (ptr->arr[(ptr->p.z)][ptr->p.y] == 'C')
			{
				ptr->collect_size--;
				ptr->arr[(ptr->p.z)][ptr->p.y] = '0';
			}
		}
		else if (ptr->arr[(ptr->p.z) + 1][ptr->p.y] == 'E' && ptr->collect_size == 0)
				ptr->is_ready_to_exit = 1;
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
	int i;
	
	if (ac == 2)
	{
		ptr = malloc(sizeof(t_long));
		if (!ptr)
			return (1);
		ptr->height = 0;
		ptr->string = map_to_array(av[1]);
		if (ptr->string == NULL)
			return (1);
		ptr->arr = ft_split(ptr->string, '\n');
		ptr->flood_arr = ft_split(ptr->string, '\n');
		ptr->width = ft_strlen(ptr->arr[0]);
		while (ptr->arr[ptr->height])
			ptr->height++;
		ptr->p.steps = 0;
		ptr->is_ready_to_exit = 0;
		ptr->is_near_exit = 0;
		ptr->collect_size = collect_size(ptr);
		if (is_5_comp(ptr->string) == 0 || is_ECP_exist(ptr->string) == 0 || is_only_one_p_e(ptr) == 0
		|| is_rectangular(ptr->string) == 0 || is_closed_by_walls(ptr->string) == 0 || is_there_newline(ptr) == 0)
		{
			free(ptr);
			// ft_printf("Error : Invalid map\n"); 
			ft_printf("\033[1;31mError : Invalid map\033[0m\n"); 
			return (0);
		}
		ptr->mlx_ptr = mlx_init();
		if (!(ptr->mlx_ptr))
			return (1);
	
		ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, ptr->width * 60, ptr->height * 60, "so_long");
		if (!(ptr->mlx_win))
		{
			free(ptr->mlx_win);
			return (1);
		}
		fill_image_addr(ptr); // fill image address ........................
		ptr->flood = 9;
		put_all_images_to_wind(ptr); // put images to window ........................
		get_cord_palyer(ptr);
		flood_fill(ptr, ptr->p);
		if (check_path(ptr) == 0)
		{
			free(ptr);
			ft_printf("invalid path\n");
			exit (0);
		}
		i = 0;
		while (ptr->flood_arr[i])
			ft_printf("-- %s -- \n", ptr->flood_arr[i++]);
		mlx_hook(ptr->mlx_win, 2, 0, hand_event, ptr);
		mlx_hook(ptr->mlx_win, 17, 0, ft_exit, ptr);
		mlx_loop(ptr->mlx_ptr);

		free(ptr->mlx_ptr);
		free(ptr);
	}
}