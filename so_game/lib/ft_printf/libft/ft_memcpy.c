/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:50:38 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/13 16:35:58 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*altdest;
	unsigned char	*altsrc;

	altdest = (unsigned char *)dest;
	altsrc = (unsigned char *)src;
	if (!altdest && !altsrc)
		return (NULL);
	while (n-- > 0)
	{
		*altdest = *altsrc;
		altdest++;
		altsrc++;
	}
	return (dest);
}

/* int main(void)
{
	char *src = "Hello World";
	char *dest = malloc(sizeof(char) * 12);
	ft_memcpy(dest, src, 12);
	printf("%s\n", dest);
} */