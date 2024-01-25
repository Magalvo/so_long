/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:46:19 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/11 16:14:59 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*alt_s1;
	unsigned char	*alt_s2;

	alt_s1 = (unsigned char *)s1;
	alt_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (alt_s1[i] != alt_s2[i])
			return ((int)(alt_s1[i] - alt_s2[i]));
		i++;
	}
	return (0);
}

/* #include <string.h>
int	main(void)
{
    char x[] = "abc";
    char y[] = "abc";
    int n = 3;
    int out;
    
    printf("First String: %s\n", x);
    out = ft_memcmp(x, y, n);
    printf("Output %d\n", out);
    printf("Original Out %d", memcmp(x, y, n));
    return (0);
} */