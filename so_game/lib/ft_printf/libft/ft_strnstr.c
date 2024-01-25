/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:07:05 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/11 20:33:21 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

/* int main()
{
	char	x[];
	char	y[];
	char	*p;

    x[] = "hello wworld";
    y[] = "wo";
    p = NULL;
    printf("String : %s\n", x);
    printf("Search for : %s\n", y);
    p = ft_strnstr(x, y, 2);
    if (p != NULL)
    {
        printf("Out: %s\n", p);
    }
    else
    {
        printf("Substring not found\n");
    }
    return (0);
}
 */