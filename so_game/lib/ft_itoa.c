/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:18:19 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/11 18:57:55 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_s(int num)
{
	size_t	len;

	len = 1;
	if (num < 0)
		len++;
	while (num > 9 || num < -9)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = num_s(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, len + 1);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (len-- > 0 && str[len] != '-')
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
