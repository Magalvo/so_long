/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:22:07 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/23 17:03:58 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H
# include "../minilibx-linux/mlx.h"
# include "../srcs/lib/libft.h"
# include "../srcs/custom/ft_printf/ft_printf.h"
# include "../srcs/custom/get_next_line/get_next_line_bonus.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

#define KEY_W 119 
#define KEY_A 97  
#define KEY_S 115 
#define KEY_D 100 
#define KEY_ESC 65307
#define KEY_UP 65362
#define KEY_LEFT 65361
#define KEY_DOWN 65364
#define KEY_RIGHT 65363
#define D_DOWN  0
#define D_UP 3
#define D_RIGHT 1
#define D_LEFT 2
#define WIDTH  64
#define HEIGHT 64

#endif
