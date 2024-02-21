NAME = so_long

SRC_PRINTF = aux_print.c ft_printf.c
SRC_GNL = get_next_line_bonus.c get_next_line_utils_bonus.c
SRC_DRAW = aux_func.c draw.c images.c map_draw.c sprites.c creation.c
SRC_MAPS = flood_fill.c map_check.c read_map.c
SRC_OBJS = player.c colectible.c exit.c cleaning.c
SRC_LIBFT = ft_putstr_fd.c ft_strlen.c ft_putchar_fd.c ft_memset.c \
			ft_calloc.c ft_strdup.c

SRC =	$(addprefix ./srcs/lib/, $(SRC_LIBFT)) \
		$(addprefix ./srcs/custom/get_next_line/, $(SRC_GNL)) \
		$(addprefix ./srcs/custom/ft_printf/, $(SRC_PRINTF)) \
		$(addprefix ./srcs/map/, $(SRC_MAPS)) \
		$(addprefix ./srcs/obj/, $(SRC_OBJS)) \
		$(addprefix ./srcs/draw/, $(SRC_DRAW))


SRCOBJ = obj/
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
LIBFLAGS = -lXext -lX11
LIB = minilibx-linux/libmlx_Linux.a
OBJ = $(addprefix $(SRCOBJ), $(SRC:./srcs/%.c=%.o))


all: $(NAME)

$(NAME): $(OBJ)
	@${CC} ${CFLAGS} -g3 main.c ${OBJ} ${LIB} ${LIBFLAGS} -o $(NAME)

$(SRCOBJ)%.o: srcs/%.c
	@mkdir -p $(SRCOBJ)
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -rf $(SRCOBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

r:
	make re && ./so_long map1.ber
