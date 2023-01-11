/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:04:55 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/11 09:56:14 by woumecht         ###   ########.fr       */
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

void	fill_image_addr(t_long *ptr)
{
	ptr->img.back_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/background.xpm", &(ptr->img.x), &(ptr->img.y));
	ptr->img.wall_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/wall.xpm", &(ptr->img.m), &(ptr->img.n));
	ptr->img.enemy_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/enemy.xpm", &(ptr->img.e1), &(ptr->img.e2));
	ptr->img.ship_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/ship.xpm", &(ptr->img.s1), &(ptr->img.s2));
	ptr->img.collect_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/col.xpm", &(ptr->img.c1), &(ptr->img.c2));
	ptr->img.exit_img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm_files/exit.xpm", &(ptr->img.x1), &(ptr->img.x2));
}

void	put_all_images_to_wind(t_long *ptr, char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
		{
			j = 0;
			while (arr[i][j])
			{
				mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, (ptr->img.x) * j, (ptr->img.y) * i);
				if (arr[i][j] == '1')
					mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.wall_img, (ptr->img.m) * j, (ptr->img.n) * i);
				else if (arr[i][j] == 'T')
					mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.enemy_img, (ptr->img.e1) * j, (ptr->img.e2) * i);
				else if (arr[i][j] == 'P')
					mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.ship_img, (ptr->img.s1) * j, (ptr->img.s2) * i);
				else if (arr[i][j] == 'C')
					mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.collect_img, (ptr->img.c1) * j, (ptr->img.c2) * i);
				else if (arr[i][j] == 'E')
					mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.exit_img, (ptr->img.x1) * j, (ptr->img.x2) * i);
				j++;
			}
			i++;
		}
}

int	main(int ac, char **av)
{
	t_long *ptr;
	char **arr;
	int	j;
	
	j = 0;
	// ================================
	if (ac == 2)
	{
		ptr = malloc(sizeof(t_long));
		if (!ptr)
			return (1);
		ptr->string = map_to_array(av[1]);
		arr = ft_split(ptr->string, '\n');
		ptr->witdt = ft_strlen(arr[0]) * 60;
		while (arr[j])
			j++;
		ptr->height = j * 60;
		if (is_5_comp(ptr->string) == 0 || is_ECP_exist(ptr->string) == 0
		|| is_rectangular(ptr->string) == 0 || is_closed_by_walls(ptr->string) == 0)
		{
			free(ptr);
			ft_printf("Error : Invalid map\n");
			return (0);
		}
		ptr->mlx_ptr = mlx_init();
		if (!(ptr->mlx_ptr))
			return (1);
		ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, ptr->witdt, ptr->height, "so_long");
		if (!(ptr->mlx_win))
		{
			free(ptr->mlx_win);
			return (1);
		}
		fill_image_addr(ptr); // fill image address ........................
		put_all_images_to_wind(ptr, arr); // put images to window ........................
		
		mlx_hook(ptr->mlx_win, 2, 0, hand_event, ptr);
		mlx_hook(ptr->mlx_win, 17, 0, ft_exit, ptr);
		mlx_loop(ptr->mlx_ptr);

		free(ptr->mlx_ptr);
		free(ptr);
	}
	// =================================
}