/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_one_ep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:20:56 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/12 15:47:12 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int is_only_one_p_e(t_long *ptr)
{
    int i;
    int j;
    int e_count;
    int p_count;

    i = 0;
    e_count = 0;
    p_count = 0;
    while (ptr->arr[i])
    {
        j = 0;
        while (ptr->arr[i][j])
        {
            if (ptr->arr[i][j] == 'E')
                e_count++;
            else if (ptr->arr[i][j] == 'P')
                p_count++;
            j++;
        }
        if (e_count > 1 || p_count > 1)
            return (0);
        i++;
    }
    return (1);
}