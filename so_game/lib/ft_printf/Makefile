# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 12:16:06 by dde-maga          #+#    #+#              #
#    Updated: 2024/01/22 14:19:03 by dde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c aux_print.c

NAME = libftprintf.a

COMPRESS = ar rcs

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror 

CC = cc

OBJS = $(SRCS:.c=.o)

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	@$(COMPRESS) $(NAME) $(OBJS) libft/*.o

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) --no-print-directory

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME) ft_printf
	@$(MAKE) -C $(LIBFTDIR) fclean --no-print-directory

re: fclean all

.PHONY: all fclean clean re	