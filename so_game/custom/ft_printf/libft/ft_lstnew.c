/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:49:35 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/13 14:30:30 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* int main()
{
    t_list *node1 = ft_lstnew("Node 1 content");
    t_list *node2 = ft_lstnew("Node 2 content");
    
    node1->next = node2;

    t_list *current = node1;
    while (current != NULL) {
        printf("Node content: %s\n", (char*)current->content);
        current = current->next;
    }

    while (node1 != NULL) {
        t_list *tmp = node1;
        node1 = node1->next;
        free(tmp);
    }

    return 0;
} */