/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:40:05 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/11 12:02:00 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	str_d;
	unsigned int	str_s;
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(dest);
	j = 0;
	str_d = ft_strlen(dest);
	str_s = ft_strlen(src);
	if (size < 1)
		return (str_s + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < str_d)
		return (str_s + size);
	else
		return (str_d + str_s);
}

/* #include <stdio.h>
int	main(void) 
{ 
	char s[] = ""; 
	char target[20] = "Hello,42!!! "; 
	unsigned int size = 20;
	unsigned int result = ft_strlcat(target, s, size);
	printf("Concatenated String: \"%s\"\n", target); 
	printf("Return Value: %u\n", result); 

	return (0); 
} */