/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:09:39 by woumecht          #+#    #+#             */
/*   Updated: 2022/10/21 10:16:16 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*str;
	size_t	i;

	str = (char *)s1;
	i = 0;
	ptr = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(str) && s1)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
