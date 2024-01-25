/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:40:43 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/11 18:04:44 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && (s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* #include <stdio.h>
int	main(void)
{
	char x[] = "iwoeroi";
	char y[] = "iwoeroi";
	int n = 10;
	int output;

	printf("First String: %s\n", x);
	output = ft_strncmp(x, y, n);
	printf("Output: %d\n", output);
	return (0);
} */
