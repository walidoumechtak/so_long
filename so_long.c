/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:04:55 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/07 20:42:09 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    my_mlx_put_pixel(t_image *data, int x, int y, int color)
{
    char    *s;

    s = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int*)s = color;
}

int main()
{
    t_long  ptr;

    ptr.mlx_ptr = mlx_init();
    ptr.mlx_win = mlx_new_window(ptr.mlx_ptr, 600, 600, "so_long");
    ptr.img.mlx_img = mlx_new_image(ptr.mlx_ptr, 600, 600);
    ptr.img.addr = mlx_get_data_addr(ptr.img.mlx_img, &(ptr.img.bpp), &(ptr.img.line_len), &(ptr.img.endian));
    my_mlx_put_pixel(&ptr.img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(ptr.mlx_ptr, ptr.mlx_win, ptr.img.mlx_img, 0, 0);
    mlx_loop(ptr.mlx_ptr);
    mlx_loop(ptr.mlx_win);
}