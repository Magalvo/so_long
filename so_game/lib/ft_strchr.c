/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:39:11 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/11 15:13:35 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*altstr;

	altstr = (char *)str;
	i = 0;
	while (altstr[i] != (char)c)
	{
		if (altstr[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)str + i);
}
