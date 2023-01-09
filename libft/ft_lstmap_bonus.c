/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:41:33 by woumecht          #+#    #+#             */
/*   Updated: 2022/11/03 08:15:20 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*s;
	t_list	*k;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	p = NULL;
	s = lst;
	while (s)
	{
		k = ft_lstnew(f(s->content));
		if (k == NULL)
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, k);
		s = s->next;
	}
	return (p);
}
