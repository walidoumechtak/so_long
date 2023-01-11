/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:59:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/11 12:36:09 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_image
{
	void	*back_img;
	void	*wall_img;
	void	*ship_img;
	void	*collect_img;
	void	*temp;
	void	*enemy_img;
	void	*exit_img;
	int	x;
	int	y;
	int	m;
	int	n;
	int	e1;
	int	e2;
	int	s1;
	int	s2;
	int	c1;
	int	c2;
	int	x1;
	int	x2;
}			t_image;

typedef	struct s_player
{
	int y;
	int	z;
}				t_player;


typedef struct s_long
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	*string;
	int		witdt;
	int		height;
	t_image	img;
	t_player	p;
}			t_long;

char		*map_to_array(char *map_path);

// ======== Errors funs =========

int			is_5_comp(char *string);
int			is_ECP_exist(char *str);
int			is_rectangular(char *str);
int			is_closed_by_walls(char *str);

#endif


