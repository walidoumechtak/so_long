/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:58:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/14 14:58:28 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_errors(t_long *ptr)
{
	if (is_5_comp(ptr->string) == 0 || is_ECP_exist(ptr->string) == 0 || is_only_one_p_e(ptr) == 0
		|| is_rectangular(ptr->string) == 0 || is_closed_by_walls(ptr->string) == 0 || is_there_newline(ptr) == 0)
		{
			free(ptr);
			// ft_printf("Error : Invalid map\n"); 
			ft_printf("\033[1;31mError : Invalid map\033[0m\n"); 
			exit (0);
		}
}