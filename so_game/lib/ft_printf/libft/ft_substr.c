/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:48:48 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/11 20:28:37 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub_s = ft_calloc(sizeof(char), len + 1);
	if (!sub_s)
		return (NULL);
	ft_memcpy(sub_s, s + start, len);
	return ((char *)sub_s);
}

/* int main()
{
    char            x[] = "hello";
    unsigned int    st = 1;
    char            *out = ft_substr(x, st, 4); 
    if (out != NULL)
    {
        printf("Substr: %s\n", out); 
        free(out); 
    }
    else
        printf("Substr is NULL\n");
    return (0);
} */