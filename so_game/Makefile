NAME = so_long
BONUS_NAME = so_long_bonus
SRCS = $(addprefix $(SRCS_DIR)/,$(addsuffix .c, $(S)))
S = map_main name_check read_map
OBJS = (SRCS:.c=.o)
SRCS_DIR = maps
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

MLX = $(MLX_DIR)/libmlx_Linux.a -lX11 -lXext 
MLX_DIR = minilibx-linux

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(LIBFT) $(OBJS) $(MLX)
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