/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:16:56 by dde-maga          #+#    #+#             */
/*   Updated: 2024/01/31 17:32:02 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define LOW_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"
# define DEC "0123456789"
# define OCTAL "01234567"
# define BINARY "01"
# define FT_PRINTF_FLAGS "cspdiuxX%"
# include "../../lib/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

int	ft_printf(const char *s, ...);
int	ft_form(char *s, int *i, va_list args);
int	ft_print_str(char *s);
int	ft_print_num(long int n);
int	ft_print_point(unsigned long int p);
int	ft_putbase(unsigned long int n, char *base, int count);

#endif
