/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:59:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/13 10:45:19 by woumecht         ###   ########.fr       */
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
	void		*back_img;
	void		*wall_img;
	void		*ship_img;
	void		*right_img;
	void		*bottom_img;
	void		*left_img;
	void		*collect_img;
	void		*temp;
	void		*enemy_img;
	void		*exit_img;
	int			x;
	int			y;
	int			m;
	int			n;
	int			e1;
	int			e2;
	int			s1;
	int			s2;
	int			c1;
	int			c2;
	int			x1;
	int			x2;
}				t_image;

typedef struct s_player
{
	int			y;
	int			z;
	int			steps;
	int			is_step;
}				t_player;

typedef struct s_long
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**arr;
	char		*string;
	int			width;
	int			height;
	int			collect_size;
	int			is_ready_to_exit;
	int			is_near_exit;
	int			e_count;
	int			p_count;
	int			c_count;
	t_image		img;
	t_player	p;
}				t_long;

char			*map_to_array(char *map_path);

// ======== Errors funs ========

int				is_5_comp(char *string);
int				is_ECP_exist(char *str);
int				is_rectangular(char *str);
int				is_closed_by_walls(char *str);
int				is_only_one_p_e(t_long *ptr);

// ======== helped funs ========

void			put_all_images_to_wind(t_long *ptr);
int				collect_size(t_long *ptr);
void			get_cord_palyer(t_long *ptr);
void			fill_image_addr(t_long *ptr);
int				ft_exit(t_long *ptr);
void			free_mlx_res(t_long *ptr);
void			flood_fill(char **arr, t_long start);

#endif
