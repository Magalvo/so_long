/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:35:52 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/12 17:32:21 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t				ft_strlen(const char *s);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *str1, const void *str2, size_t n);

#endif
