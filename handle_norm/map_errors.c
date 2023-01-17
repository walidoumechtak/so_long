/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:58:15 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/17 20:02:40 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_errors(t_long *ptr, char **av)
{
	if (check_extenstion(av) == 0 || is_5_comp(ptr->string) == 0
		|| is_ecp_exist(ptr->string) == 0 || is_only_one_p_e(ptr) == 0
		|| is_rectangular(ptr->string) == 0
		|| is_closed_by_walls(ptr->string) == 0 || is_there_newline(ptr) == 0)
	{
		ft_printf("Error : Invalid map");
		free_mlx_res(ptr);
	}
}
