/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:15:37 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/13 14:55:44 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/* int main(void)
{
	t_list *node1 = "Hello";
	t_list *node2 = "World";
	t_list *node3 = "!";

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	
	ft_lstlast(node1);
	printf("%s", ft_lstlast(node1));
	return (0);
} */