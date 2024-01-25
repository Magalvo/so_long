/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:49:32 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/13 14:46:27 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/* int main(void)
{
	t_list *node1 = ft_lstnew("This is node 42");
	t_list *node2 = ft_lstnew("This is node Lis");
	t_list *node3 = ft_lstnew("This is node Paco");

	node1->next = node2;
	node2->next = node3;
	
	int size = ft_lstsize(node1);
	printf("List size: %d\n", size);
	while (node1 != NULL) {
		t_list *tmp = node1;
		node1 = node1->next;
		free(tmp);
	}
	return (0);
} */