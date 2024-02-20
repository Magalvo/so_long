/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:17:56 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/20 15:53:57 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"


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
