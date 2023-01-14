/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_newline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:43:35 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/14 12:52:30 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_there_newline(t_long *ptr)
{
	size_t i;
    
    if (ptr->string[0] == '\n')
        return (0);
    else if (ptr->string[ft_strlen(ptr->string) - 1] == '\n')
        return (0);
    i = 1;
    while (ptr->string[i++])
        if (ptr->string[i] == '\n' && ptr->string[i + 1] == '\n')
            return (0);
    return (1);
}