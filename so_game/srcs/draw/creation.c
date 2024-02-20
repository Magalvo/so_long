/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:17:56 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/20 11:18:10 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

t_object *create_object(int x, int y, t_img *imgs, void (*render)(t_object *))
{
	t_object *obj = ft_calloc(sizeof(t_object), 1);
	if (!obj)
		return NULL;
	obj->x = x;
	obj->y = y;
	obj->imgs = imgs;
	obj->render = render;
	obj->next = NULL;

	return obj;
}

void	append_object(t_object **list, t_object *new_obj)
{
	if (!*list)
		*list = new_obj;
	else
	{
		t_object *tmp = *list;
		while (tmp ->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new_obj;
	}
}
