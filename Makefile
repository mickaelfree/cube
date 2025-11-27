# Makefile for cube (42 project) modeled after minishell style
NAME = cube

# Directories
CORE_DIR = core/
IO_DIR = io/
OBJ_DIR = .obj/
LIBFT_DIR = libft/
MLX_DIR = minilibx-linux/

# Source lists
CORE_FILES = loop.c
IO_FILES = input.c
MAIN_FILES = main.c

FILES = \
	$(addprefix $(CORE_DIR), $(CORE_FILES)) \
	$(addprefix $(IO_DIR), $(IO_FILES)) \
	$(MAIN_FILES)

# Objects / deps
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
DEPS = $(addprefix $(OBJ_DIR), $(FILES:.c=.d))

# Compiler & Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP \
	-I include \
	-I $(MLX_DIR) \
	-I $(LIBFT_DIR)libft_functions/includes \
	-I $(LIBFT_DIR)vectors/includes \
	-I $(LIBFT_DIR)ft_printf/includes \
	-I $(LIBFT_DIR)get_next_line/includes

# Libraries
LIBFT = $(LIBFT_DIR)libft.a
MLXLIB = $(MLX_DIR)libmlx_Linux.a
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd

MAKEFLAGS += --no-print-directory

# Colors
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
PURPLE = \033[35m
RESET = \033[0m

.PHONY: all lib clean fclean re banner debug fdebug norm gdb print-vars FORCE
.DEFAULT_GOAL = all

all: banner lib $(NAME)

banner:
	@echo "$(PURPLE)🚀 Building cube$(RESET)"

# Build executable
$(NAME): $(OBJ) $(LIBFT) $(MLXLIB)
	@echo "$(YELLOW)Link $(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)
	@echo "$(GREEN)✅ Done$(RESET)"

# Object rule
$(OBJ_DIR)%.o: %.c Makefile
	@mkdir -p $(dir $@)
	@echo "CC $< -> $@"
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

# Library aggregation
FORCE:
lib: $(LIBFT) $(MLXLIB)

$(LIBFT): FORCE
	@echo "📦 libft"
	@$(MAKE) -C $(LIBFT_DIR) || echo "$(RED)libft build failed$(RESET)"

$(MLXLIB): FORCE
	@echo "📦 mlx"
	@$(MAKE) -C $(MLX_DIR) || echo "$(RED)mlx build failed$(RESET)"

# Cleaning
clean:
	@echo "$(RED)🧹 clean objects$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean || true
	@$(MAKE) -C $(MLX_DIR) clean || true
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)🧹 full clean$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean || true
	@rm -f $(NAME)

re: fclean all

# Debug targets
debug: CFLAGS += -g3
debug: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

fdebug: CFLAGS += -g3 -DDEBUG_MODE=1
fdebug: re
	DEBUG_MODE=1 valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./$(NAME)

norm:
	norminette . include/

gdb:
	gdb ./$(NAME) -ex "break main"

print-vars:
	@echo NAME=$(NAME)\nOBJ=$(OBJ)\nFILES=$(FILES)