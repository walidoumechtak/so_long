/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:55:47 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/15 08:34:40 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_struct_var(t_long *ptr, char **av)
{
	ptr->e_count = 0;
	ptr->p_count = 0;
	ptr->c_count = 0;
	ptr->boll1 = 0;
	ptr->boll2 = 0;
	ptr->height = 0;
	ptr->string = map_to_array(av[1]);
	if (ptr->string == NULL)
		exit(0);
	ptr->arr = ft_split(ptr->string, '\n');
	ptr->flood_arr = ft_split(ptr->string, '\n');
	ptr->width = ft_strlen(ptr->arr[0]);
	while (ptr->arr[ptr->height])
		ptr->height++;
	ptr->p.steps = 0;
	ptr->is_ready_to_exit = 0;
	ptr->is_near_exit = 0;
	ptr->collect_size = collect_size(ptr);
}
