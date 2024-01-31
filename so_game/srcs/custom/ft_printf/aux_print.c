/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:53:34 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/24 11:25:22 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(unsigned long int n, char *base, int count)
{
	int		len;
	char	c;

	len = ft_strlen(base);
	if ((n / len) > 0)
	{
		count = ft_putbase(n / len, base, count);
		count = ft_putbase(n % len, base, count);
	}
	else
	{
		c = base[n];
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_print_point(unsigned long int p)
{
	int	count;

	count = 0;
	if (!p)
		count += ft_putstr_fd("(nil)", 1);
	else
	{
		count += write(1, "0x", 2);
		count += ft_putbase(p, LOW_HEX, 0);
	}
	return (count);
}

int	ft_print_num(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count += ft_putbase((n * -1), DEC, count);
		count++;
	}
	else
		count += ft_putbase(n, DEC, count);
	return (count);
}

int	ft_print_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
		count += ft_putstr_fd("(null)", 1);
	else
		count += ft_putstr_fd(s, 1);
	return (count);
}
