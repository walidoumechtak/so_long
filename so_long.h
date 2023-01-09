/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:59:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/09 15:18:35 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include "helped_functions/helped.h"

typedef struct s_image
{
    void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}           t_image;

typedef struct s_long
{
    void    *mlx_ptr;
    void    *mlx_win;
    char    *string;
    int x;
    int y;
    t_image img;
}              t_long;

char    *map_to_array(char *map_path);


#endif