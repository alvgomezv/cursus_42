/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:24:21 by alvgomez          #+#    #+#             */
/*   Updated: 2022/10/04 11:06:25 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	t_list	*extra;

	new = NULL;
	if (!lst && !f)
		return (NULL);
	while (lst)
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (temp == NULL)
		{
			while (new)
			{
				extra = new->next;
				del(new->content);
				free(new);
				new = extra;
			}
			return (0);
		}
		temp->content = f(lst->content);
		temp->next = 0;
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}

/*
Iterates the list ’lst’ and applies the function ’f’
 on the content of each node. Creates a new list 
 resulting of the successive applications of the function ’f’. 
 The ’del’ function is used to delete the content of a node if needed.
*/
