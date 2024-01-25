# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 13:05:25 by dde-maga          #+#    #+#              #
#    Updated: 2023/10/27 13:06:27 by dde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_atoi.c    ft_itoa.c       ft_calloc.c  ft_isalnum.c \
		ft_isalpha.c ft_isascii.c    ft_isupper.c ft_isdigit.c \
	    ft_isprint.c ft_strlen.c     ft_islower.c ft_toupper.c \
		ft_strlcpy.c ft_strlcat.c    ft_strchr.c  ft_strnstr.c \
		ft_strrchr.c ft_strdup.c     ft_tolower.c ft_putchar_fd.c \
		ft_bzero.c   ft_putnbr_fd.c  ft_memcmp.c  ft_putendl_fd.c \
		ft_memset.c  ft_memcpy.c     ft_memmove.c ft_memchr.c \
		ft_strjoin.c ft_substr.c     ft_strtrim.c ft_strncmp.c \
		ft_strmapi.c ft_striteri.c   ft_split.c   ft_putstr_fd.c \
		
		 
NAME = libft.a

COMPRESS = ar rcs

RM = rm -rf

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(LST:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(NAME): $(OBJS)
	@$(COMPRESS) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re bonus
 
