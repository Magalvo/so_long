/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:33:48 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/13 18:24:55 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*buff_d;
	const unsigned char	*buff_s;

	buff_d = (unsigned char *)dest;
	buff_s = (unsigned char *)src;
	if (buff_s > buff_d)
		return (ft_memcpy(dest, src, n));
	if (buff_s < buff_d)
	{
		while (n--)
			buff_d[n] = buff_s[n];
	}
	return (dest);
}

/* int main(void)
{
	char *src = "Hello World";
	char *dest = malloc(sizeof(char) * 12);
	ft_memmove(dest, src, 12);
	printf("%s\n", dest);
} */
