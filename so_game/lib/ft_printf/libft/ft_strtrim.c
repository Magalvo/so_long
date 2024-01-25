/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:05:16 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/13 14:36:42 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	si;
	char	*trim;

	trim = NULL;
	if (s1 && set)
	{
		i = 0;
		si = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[si - 1] && ft_strchr(set, s1[si - 1]) && si > i)
			si--;
		trim = (char *)malloc(sizeof(char) * (si - i + 1));
		if (trim)
			ft_strlcpy(trim, &s1[i], si - i + 1);
	}
	return (trim);
}

/* int main(void)
{
	char *s1;
	char *set;

	s1 = " panquecas na grelha     ";
	set = " ";
	printf("Panquecas aparadas: %s\n", ft_strtrim(s1, set));
	return (0);
} */
