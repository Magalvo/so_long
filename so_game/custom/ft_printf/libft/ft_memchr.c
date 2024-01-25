/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:43:10 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/13 15:05:22 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*altstr;
	unsigned int	i;

	altstr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (altstr[i] == (unsigned char)c)
			return (&altstr[i]);
		i++;
	}
	return (NULL);
}

/* int main() {
    const char *str = "Hello, World!";
    char target = 'W';
    size_t n = strlen(str);

    void *result = ft_memchar(str, target, n);

    if (result != NULL) {
        printf("'%c' found at position %ld\n", target, (char *)result - str);
    } else {
        printf("'%c' not found in the string\n", target);
    }

    return (0);
} */
