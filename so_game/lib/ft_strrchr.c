/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:58:19 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/13 14:34:28 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*altstr;

	altstr = (char *)str;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}

/* int main()
{
    char myString[] = "Hello, 42! Thest test test";
    int myChar = 'o';
    char *result = ft_strrchr(myString, myChar);

    if (result != NULL) {
        printf("Last occurrence of '%c': %s\n", myChar, result);
    } else {
        printf("Character '%c' not found.\n", myChar);
    }

    myChar = 'z';
    result = ft_strrchr(myString, myChar);

    if (result != NULL) {
        printf("Last occurrence of '%c': %s\n", myChar, result);
    } else {
        printf("Character '%c' not found.\n", myChar);
    }

    return (0);
} */