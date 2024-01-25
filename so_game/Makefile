NAME = so_long
SRCS = main.c so_long.c
OBJS = $(SRCS:.c=.o)

D_SRCS = $(addprefix $(SRCS_DIR)/,$(addsuffix .c, $(D)))
D = aux_func draw images map_draw sprites
DRAW_DIR = draw
D_OBJS = $(D_SRCS:.c=.o)

S_SRCS = $(addprefix $(SRCS_DIR)/,$(addsuffix .c, $(S)))
S = flood_fill read_map map_check
SRCS_DIR = maps
S_OBJS = $(S_SRCS:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

MLX = $(MLX_DIR)/libmlx_Linux.a -lX11 -lXext 
MLX_DIR = minilibx-linux

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(LIBFT) $(SRCS) $(S_OBJS) $(D_OBJS) $(MLX)
	@$(CC) -o $(NAME) $(MLX) $(OBJS) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) --no-print-directory

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME) 
	@$(MAKE) -C $(LIBFTDIR) fclean --no-print-directory

re: fclean all