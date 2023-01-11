/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:04:55 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/11 08:48:38 by woumecht         ###   ########.fr       */
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
}

int	main(int ac, char **av)
{
	t_long *ptr;
	char **arr;
	int	i;
	int	j;
	
	// ================================
	i = 0;
	j = 0;
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
		fill_image_addr(ptr);
		
		while (arr[i])
		{
			j = 0;
			while (arr[i][j])
			{
				mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.back_img, (ptr->img.x) * j, (ptr->img.y) * i);
				if (arr[i][j] == '1')
					mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.wall_img, (ptr->img.m) * j, (ptr->img.n) * i);
				j++;
			}
			i++;
		}
		mlx_hook(ptr->mlx_win, 2, 0, hand_event, ptr);
		mlx_hook(ptr->mlx_win, 17, 0, ft_exit, ptr);
		mlx_loop(ptr->mlx_ptr);

		free(ptr->mlx_ptr);
		free(ptr);
	}
	// =================================
}