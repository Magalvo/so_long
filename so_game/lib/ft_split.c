/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:40:21 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/13 14:24:53 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**split_free(char **splits)
{
	size_t	j;

	j = -1;
	while (splits[++j])
		free(splits[j]);
	free(splits);
	return (NULL);
}

static size_t	ft_wordctd(const char *str, char c, char ***splits)
{
	size_t	ctd;
	size_t	i;
	size_t	start;

	ctd = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			ctd++;
		start = i;
		while (str[i] != c && str[i])
			i++;
		if (*splits && ctd > 0 && i != start) 
			(*splits)[ctd - 1] = ft_substr(str, start, i - start);
		if (*splits && ctd && !(*splits)[ctd - 1])
		{
			(*splits) = split_free(*splits);
			return (0);
		}
	}
	return (ctd);
}

char	**ft_split(char const *s, char c)
{
	char	**splits;

	splits = NULL;
	splits = ft_calloc(ft_wordctd(s, c, &splits) + 1, sizeof(char *));
	if (!splits)
		return (NULL);
	ft_wordctd(s, c, &splits);
	return (splits);
}

/*  int	main(void)
{
	printf("split\n");
 char	*str = ""   lorem   ipsum dolor     sit amet, consectetur   
adipiscing elit. Sed non risus. Suspendisse   ", ' '";
	char	**arr = ft_split("   lorem   ipsum dolor     sit amet, 
consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	int		i;
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	while (i <= 0)
	{
		free (arr[i]);
		i--;
	}
	free (arr);
}  */