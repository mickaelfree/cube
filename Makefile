# Executable
CUBE = cube

# Directories
OBJ_DIR = obj/
LIBFT_DIR = libft/
MLX_DIR = minilibx-linux/

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
LDFLAGS = -L $(LIBFT_DIR) -L $(MLX_DIR)
LDLIBS = -lft -lmlx_Linux -lXext -lX11 -lm -lbsd

# Sources
SRCS = main.c \
	core/loop.c \
	io/input.c

# Objects & deps
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.d))

MAKEFLAGS += --no-print-directory
.DEFAULT_GOAL = all

# Colors
RESET = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
MAGENTA = \033[1;35m
CYAN = \033[1;36m

# Banner / start
all: printstart lib $(CUBE)

printstart:
	@printf "\n$(MAGENTA)🔨Compiling cube🔨$(RESET)\n"

# Build executable (after libs)
$(CUBE): $(OBJS) $(LIBFT) $(MLXLIB)
	@printf "\n$(MAGENTA)🔨Link exec🔨$(CYAN)\n"
	@printf "$(YELLOW)Link $(CYAN)$@ $(YELLOW)from $(CYAN)$(OBJS) $(LIBFT) $(MLXLIB)$(RESET)\n"
	@if [ ! -f "$(LIBFT)" ]; then echo "$(RED)Error: $(LIBFT) not found. Build libft first (tabs in libft/Makefile?).$(RESET)"; exit 1; fi
	@if [ ! -f "$(MLXLIB)" ]; then echo "$(RED)Error: $(MLXLIB) not found. Build MiniLibX first.$(RESET)"; exit 1; fi
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)
	@printf "\n$(YELLOW)✅ Build done!$(RESET)\n\n"

# Object rule
$(OBJ_DIR)%.o: %.c Makefile
	@mkdir -p $(dir $@)
	@printf "$(GREEN)🔨Compiling $(CYAN)$@ $(GREEN)from $(CYAN)$<$(RESET)\n"
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

# Lib aggregation
data:
	@true

.PHONY: lib FORCE
FORCE:

lib: $(LIBFT) $(MLXLIB)

$(LIBFT): FORCE
	@echo "🔧 Building libft..."
	@$(MAKE) -C $(LIBFT_DIR) || echo "[cube] Warning: libft build failed (likely spaces instead of tabs at reported line). Fix libft/Makefile around line shown by make and rerun. Continuing without refreshed libft." 

$(MLXLIB): FORCE
	@echo "🔧 Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR) || true

# Cleaning
clean:
	@printf "$(RED)🗑️  Cleaning objects...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) clean || true
	@$(MAKE) -C $(MLX_DIR) clean || true
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@printf "$(RED)🗑️  Full clean...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) fclean || true
	$(RM) -f $(CUBE)

re: fclean all

# Debug targets
debug: CFLAGS += -g3
debug: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(CUBE)

fdebug: CFLAGS += -g3 -DDEBUG_MODE=1
fdebug: re
	DEBUG_MODE=1 valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./$(CUBE)

norm:
	norminette . include/

gdb:
	gdb ./$(CUBE) -ex "break main"

.PHONY: all clean fclean re debug fdebug norm gdb printstart lib