/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:56:56 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/18 11:38:42 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* void	add_one(unsigned int i, char *c)
{
    *c += 1;
}

int	main(void)
{
    char	str[] = "hello, world!";

    printf("Before: %s\n", str);
    ft_striteri(str, add_one);
    printf("After: %s\n", str);
    return (0);
} */