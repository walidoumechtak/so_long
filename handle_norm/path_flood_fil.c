/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_flood_fil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:59:06 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/15 08:34:50 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	path_flood_fil(t_long *ptr)
{
	flood_fill(ptr, ptr->p);
	if (check_path(ptr) == 0)
	{
		ft_printf("invalid path\n");
		free_mlx_res(ptr);
	}
}
