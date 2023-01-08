/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:58:57 by woumecht          #+#    #+#             */
/*   Updated: 2023/01/08 17:36:38 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helped.h"

char	*ft_strdup(char *s)
{
	char *str;
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}