/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:27:37 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/30 11:18:21 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

/*void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	temp = NULL;
	if (lst->next)
		temp = lst->next;
	del(lst->content);
	free(lst);
	lst = temp;
}*/

/*
Takes as a parameter a node and frees the memory 
of the node’s content using the function ’del’ 
given as a parameter and free the node. 
The memory of ’next’ must not be freed.
*/