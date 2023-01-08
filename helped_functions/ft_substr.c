/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:25:53 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/08 16:59:34 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helped.h"

char    *ft_substr(char *s, int start, int len)
{
    char *str;
    int len_string;
    int i;

    if (!s)
        return (NULL);
    len_string = ft_strlen(s);
    if (start > len_string)
        ft_strdup("");
    if (len_string - start < len)
        len = len_string - start;
    i = 0;
    str = malloc(sizeof(char));
    if (!str)
        reutnr (NULL);
    if (start > len_string)
    while (start <= len)
    {
        str[i] = s[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return (str);
}