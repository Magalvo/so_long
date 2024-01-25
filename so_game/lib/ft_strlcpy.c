/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:28:37 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/13 14:59:47 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}
/*#include <stdio.h>
    int main() {
    char source[] = "12345678942";
    char destination[3];

    unsigned int copied = ft_strlcpy(destination, source, sizeof(destination));

    printf("Copied: %u\n", copied);
    printf("Destination: %s\n", destination);

    return (0);
}*/