/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:22:39 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/29 17:28:21 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n_nodes;

	n_nodes = 0;
	while (lst)
	{
		n_nodes++;
		lst = lst->next;
	}
	return (n_nodes);
}

/*
Counts the number of nodes in a list
*/