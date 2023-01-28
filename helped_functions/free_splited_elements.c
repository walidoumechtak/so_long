/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splited_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 06:31:59 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/28 20:17:24 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_all_ele(t_long *ptr)
{
	int	i;

	i = 0;
	while (ptr->arr[i])
		free(ptr->arr[i++]);
	i = 0;
	while (ptr->flood_arr[i])
		free(ptr->flood_arr[i++]);
}
