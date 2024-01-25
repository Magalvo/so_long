/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:35:22 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/13 14:52:53 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *s1, char const *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = s2[i];
	return (s1);
}

static char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	cntr;

	i = 0;
	cntr = 0;
	while (dest[cntr])
		cntr++;
	while (src[i])
	{
		dest[cntr + i] = src[i];
		i++;
	}
	dest[cntr + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	total;

	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (total + 1));
	if (!join)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	return (join);
}

/* int main(void)
{
	char *s1;
	char *s2;

	s1 = "Hello ";
	s2 = "World!";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
} */