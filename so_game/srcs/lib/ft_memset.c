/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:34:03 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/14 17:34:05 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pos;
	unsigned char	ac;

	ac = (unsigned char)c;
	pos = (unsigned char *)b;
	while (len--)
		*pos++ = ac;
	return (b);
}
