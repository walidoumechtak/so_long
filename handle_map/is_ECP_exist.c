/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ECP_exist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:54:58 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/09 18:03:33 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int is_ECP_exist(char *str)
{
    int i;
    int e;
    int c;
    int p;

    i = 0;
    e = 0;
    c = 0;
    p = 0;
    while (str[i])
    {
        if (str[i] == 'E')
            e++;
        else if (str[i] == 'C')
            c++;
        else if (str[i] == 'P')
            p++;
        if (e > 0 && c > 0 && p > 0)
            return (1);
        i++;
    }
    return (0);
}