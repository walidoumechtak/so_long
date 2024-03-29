/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:59:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/17 20:04:36 by woumecht         ###   ########.fr       */
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
	void		*ship_90;
	void		*ship_180;
	void		*ship_270;
	void		*bottom_img;
	void		*left_img;
	void		*collect_img;
	void		*col90_img;
	void		*col180_img;
	void		*col270_img;
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

typedef struct s_exit
{
	int			ex1;
	int			ex2;
}				t_exit;

typedef struct s_long
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**arr;
	char		**flood_arr;
	char		*string;
	int			width;
	int			height;
	int			collect_size;
	int			is_ready_to_exit;
	int			is_near_exit;
	int			e_count;
	int			p_count;
	int			c_count;
	int			flood;
	int			boll1;
	int			boll2;
	int			count;
	int			count2;
	t_image		img;
	t_player	p;
	t_exit		exit;
}				t_long;

char			*map_to_array(char *map_path);

// ======== Errors funs ========

int				is_5_comp(char *string);
int				is_ecp_exist(char *str);
int				is_rectangular(char *str);
int				is_closed_by_walls(char *str);
int				is_only_one_p_e(t_long *ptr);
int				is_5_comp_bonus(char *string);
int				check_extenstion(char **av);

// ======== helped funs ========

void			put_all_images_to_wind(t_long *ptr);
int				collect_size(t_long *ptr);
void			get_cord_palyer(t_long *ptr);
void			fill_image_addr(t_long *ptr);
int				ft_exit(t_long *ptr);
void			free_mlx_res(t_long *ptr);
void			flood_fill(t_long *ptr, t_player start);
int				check_path(t_long *ptr);
int				is_there_newline(t_long *ptr);
void			free_all_ele(t_long *ptr);
int				anime1(t_long *ptr);

// ======== handle norm ========

void			init_struct_var(t_long *ptr, char **av);
void			map_errors(t_long *ptr, char **av);
void			map_errors_bonus(t_long *ptr, char **av);
void			path_flood_fil(t_long *ptr);
void			hooks_and_free(t_long *ptr);
void			top_and_down(t_long *ptr, int dirction, int y, int y2);
void			right_and_left(t_long *ptr, int dirction, int y, int y2);

int				hand_event(int key, t_long *ptr);
#endif
