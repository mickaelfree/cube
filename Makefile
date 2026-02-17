NAME = cube

# Directories
PARSING_DIR = parsing/

PARSING_FILES = parse_colors/is_color_id.c \
				parse_colors/parse_color_line.c \
				parse_file/parse_file.c \
				parse_file/parse_line.c \
				parse_map/fill_grid_raw.c \
				parse_map/is_map_char.c \
				parse_map/parse_map.c \
				parse_map/store_map_line.c \
				parse_map/init_player_from_map.c \
				parse_texture/is_texture_id.c \
				parse_texture/parse_texture_line.c \
				parse_texture/set_texture_path.c \
				read_file/read_file.c \
				read_file/validate_extension.c \
				utils_parsing/free_parser.c \
				utils_parsing/is_empty_line.c \
				utils_parsing/is_player_char.c \
				utils_parsing/skip_spaces.c \
				validate_map/validate_map.c

OBJ_DIR = .obj/
LIBFT_DIR = libft/
MLX_DIR = minilibx-linux/

# Source lists
MAIN_FILES = main.c

CORE_FILES = core/run_game.c \
			 core/game_loop.c \
			 core/cleanup.c \
	   		 draw/draw_3d_column.c\
	   		 draw/draw_ceiling.c\
	   		 draw/draw_floor.c\
	  		 draw/draw_line.c \
	  		 draw/draw_fps.c \
	  		 draw/put_pixel.c \
			 minimap/minimap_draw.c \
			 minimap/draw_player_on_minimap.c \
	  		 render/render_minimap.c \
	  		 render/render_3d_view.c \
	  		 render/render_3d_raycast.c \
			 assets/load_all_textures.c \
			 utils/time.c \
			 utils/dda_utils.c \
			 utils/init_trig_tables.c \
			 utils/draw_utils.c \
			 utils/fps.c \
			 utils/minimap_utils.c \
	  		 io/input.c \
			 io/init_hooks.c \
			 io/key_press.c \
			 io/key_release.c \
			 io/inbound_collision.c

FILES = \
	$(addprefix $(PARSING_DIR), $(PARSING_FILES)) \
	$(CORE_FILES) \
	$(MAIN_FILES)

# Objects / deps
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
DEPS = $(addprefix $(OBJ_DIR), $(FILES:.c=.d))

# Compiler & Flags -fsanitize=address
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
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd -lpthread

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
	@$(MAKE) -C $(MLX_DIR) CC="gcc -std=gnu17" || echo "$(RED)mlx build failed$(RESET)"

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
