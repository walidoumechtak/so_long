/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:59:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/07 14:54:29 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include "mlx.h"

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
    t_image img;
}              t_long;


#endif