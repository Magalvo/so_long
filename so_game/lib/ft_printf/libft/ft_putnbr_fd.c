/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:25:10 by dde-maga          #+#    #+#             */
/*   Updated: 2023/10/12 14:09:53 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd((nbr / 10), fd);
		nbr = nbr % 10;
	}
	ft_putchar_fd(nbr + '0', fd);
}

/* int	main(void)
{
	int i = 42;
	int fd = 1;
	printf("Out: %d", ft_putnbr_fd(i, fd));
	return (0);
} */