/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:30:45 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/11 16:10:19 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	unsigned char	*cpy;
	size_t			i;
	size_t			len;

	len = ft_strlen(src);
	i = 0;
	cpy = (unsigned char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return ((char *)cpy);
}

/* int main(int argc, char *argv[])
{
    char *rep;
    char *origin;

    if (argc == 2)
    {
        rep = ft_strdup(argv[1]);
        if (rep == NULL)
        {
            printf("Memory allocation failed for ft_strdup\n");
            return (1);
        }

        origin = strdup(argv[1]);
        if (origin == NULL)
        {
            printf("Memory allocation failed for strdup\n");
            free(rep); 
            return (1);
        }

        printf(":%s:\n", rep);
        printf(":%s:\n", origin);

        free(rep);    
        free(origin); 
    }
    return (0);
} */