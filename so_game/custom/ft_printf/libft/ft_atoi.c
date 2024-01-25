/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:41:29 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/18 11:42:55 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	fac;

	res = 0;
	fac = 1;
	i = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			fac *= -1;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * fac);
}

/*

int	main(void)
{
    printf("%d", ft_atoi("\n \t \r \v \f   -123"));
    return (0);
}
 */