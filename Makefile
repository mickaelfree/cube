CUBE= cube
CFLAGS = #-Wall -Wextra -Werror
NORELINK = -MMD -MP
INCLUDE = -I /include -I minilibx-linux
LIBS = minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm
MLXLIB = libmlx_Linux.a

PRINTSTART = @printf "\n$(MAGENTA)🔨Compiling cube🔨$(RESET)\n"
printstart:
	$(PRINTSTART)

# MKFILES=src/builtins/builtins.mk\
# 	src/exec/exec.mk\
# 	src/parsing/parsing.mk\
# 	src/signal/signal.mk\
# 	src/utils/utils.mk

SRCDIR = src
BUILDDIR = obj

#SRCS = $(SRCDIR)/main.c
SRCS = main.c \
	core/loop.c \
	draw/draw_3d_column.c\
	draw/draw_line.c \
	draw/draw_player_dot.c \
	draw/draw_player_ray.c \
	draw/draw_fov_cone.c \
	draw/draw_grid.c \
	draw/draw_rect.c \
	draw/put_pixel.c \
	draw/utils.c \
	render/render_minimap.c \
	assets/xpm.c \
	io/input.c


OBJS = $(SRCS:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)
DEPS = $(OBJS:.o=.d)

MAKEFLAGS += --no-print-directory

.DEFAULT_GOAL = all  # Set default goal to make all

# Base rule
all: printstart $(CUBE)

$(CUBE):$(MLXLIB) $(OBJS) #$(LIBFT)
	@printf "\n$(MAGENTA)🔨Compile exec🔨$(CYAN)\n"
	@printf "$(YELLOW)Compile $(CYAN)$@ $(YELLOW)from $(CYAN)$^$(RESET)\n"
	@$(CC) $(CFLAGS) $(NORELINK) $(INCLUDE) -o $@ $(OBJS) $(LIBS)
	@printf "\n$(YELLOW)✅ Build done!$(RESET)\n\n"

# $(LIBFT): FORCE
# 	@$(MAKE) -C ./libft

# Relink prevention for linked projects
FORCE:
# Individual source file rule
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(GREEN)🔨Compiling $(CYAN) $@ $(GREEN)from $(CYAN)$<"
	@$(CC) $(CFLAGS) $(NORELINK) $(INCLUDE) -o $@ -c $<
	@printf "$(RESET)\n"

$(MLXLIB):
	@echo "🔧 Building MiniLibX..."
	@$(MAKE) -C minilibx-linux > /dev/null 2>&1


clean:
	@printf "$(RED)🗑️  "
#	@$(MAKE) clean -C ./libft > /dev/null
	$(RM) -r $(BUILDDIR)
	@printf "$(RESET)\n"


fclean: clean
	@printf "$(RED)🗑️  "
#	@$(MAKE) fclean -C ./libft > /dev/null
	$(RM) $(CUBE)
	@printf "$(RESET)\n"

re: fclean all

# Compile for valgrind
debug: CFLAGS = -Wall -Wextra -Werror -g3
debug: fclean all
	valgrind $(shell cat .valgrindrc) ./cube

# Compile for debug mode + valgrind
fdebug: CFLAGS = -Wall -Wextra -Werror -g3 -DDEBUG_MODE=1
fdebug: fclean all
	DEBUG_MODE=1 valgrind $(shell cat .valgrindrc) --trace-children=yes ./cube

# Norminette for source and include
norm:
	norminette src/ inc/

gdb:
	gdb ./$(CUBE) -ex "break main"


.PHONY: all FORCE clean fclean re debug gdb tester

# COLORS
RESET = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
GREY = \033[1;90m
