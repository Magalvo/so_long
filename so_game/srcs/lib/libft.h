/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:35:52 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/16 17:04:19 by dde-maga         ###   ########.fr       */
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
void				*ft_memset(void *b, int c, size_t len);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strdup(char *str);

#endif
