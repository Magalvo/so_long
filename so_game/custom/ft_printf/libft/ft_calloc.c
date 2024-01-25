/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:33:37 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/16 18:05:52 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	total;
	void	*ptr;

	if (size && nitems > (size_t)(-1) / size)
		return (NULL);
	total = (nitems * size);
	ptr = malloc(total);
	if (ptr != NULL)
		ft_bzero(ptr, total);
	return (ptr);
}

/* int	main()
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_calloc(100000000, 1);
	while (i < 100000000)
	{
		if (ptr[i] != 0)
			printf("Error\n");
		i++;
	}
	printf("Success\n");
	free(ptr);
	return (0);
} */