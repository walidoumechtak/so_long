/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:04:55 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/08 12:50:25 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    destroy(int key, t_long *ptr)
{
    t_long *s;

    s = ptr;
    ft_printf("%d\n", key);
    if (key == 53)
        mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
    return (key);
}

int main()
{
    t_long  *ptr;

    ptr = malloc(sizeof(t_long));
    ptr->mlx_ptr = mlx_init();
    ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, 600, 600, "so_long");
    ptr->img.mlx_img = mlx_new_image(ptr->mlx_ptr, 600, 600);
    mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.mlx_img, 0, 0);
    
    mlx_hook(ptr->mlx_win,2, 0, destroy, ptr);
    mlx_loop(ptr->mlx_ptr);
    
}