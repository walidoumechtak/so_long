/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:12:06 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/08 16:12:44 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int count_wrod(char *s)
{
    int i;
    int cpt;

    i = 0;
    cpt = 0;;

    while (s[i])
    {
        if (s[i] == '\n')
            cpt++;
        i++;
    }
    return (cpt);
}

char    *ft_substr(char *s, int start, int len)
{
    char *str;
    int len_string;
    int i;

    if (!s)
        return (NULL);
    len_string = ft_strlen();    
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

char    **ft_split(char *s)
{
    char **split;
    int i;
    int j;
    int wc;

    wc = count_wrod(s);
    split = malloc((wc + 1) * sizeof(char*));
    if (!split)
        return (NULL);
    i = 0;
    while (s[i])
    {
           
    }
}