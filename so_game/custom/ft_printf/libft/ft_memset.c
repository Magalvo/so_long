/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:54:16 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/13 14:46:59 by dde-maga         ###   ########.fr       */
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

/* int main(void)
{
	char *s;
	char *s2;

	s = malloc(10);
	s2 = malloc(10);
	ft_memset(s, 'a', 10);
	ft_memset(s2, 'a', 10);
	printf("%s\n", s);
	printf("%s\n", s2);
	return (0);
}
 */