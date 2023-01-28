/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:18:25 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/28 20:47:04 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_mlx_res(t_long *ptr)
{
	free_all_ele(ptr);
	free(ptr->string);
	free(ptr->arr);
	free(ptr->flood_arr);
	free(ptr);
	exit(0);
}
