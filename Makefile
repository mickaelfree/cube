# Names
NAME = cub3D
NAME_BONUS = cub3D_bonus

# Colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[35m

# Directories
MAND_DIR = CUB3D_MANDATORY
BONUS_DIR = CUB3D_BONUS

# Valgrind
VALGRIND_SUPP = valgrind.supp
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all
# Check if suppression file exists (without wildcard)
VALGRIND_SUPP_EXISTS := $(shell test -f $(VALGRIND_SUPP) && echo yes)
ifeq ($(VALGRIND_SUPP_EXISTS),yes)
	VALGRIND_FLAGS += --suppressions=$(VALGRIND_SUPP)
endif

# Rules
.PHONY: all clean fclean re bonus rebonus help debug debug-bonus fdebug fdebug-bonus gdb gdb-bonus norm

all: $(NAME)

$(NAME): $(MAND_DIR)/cub3D
	@cp $(MAND_DIR)/cub3D ./$(NAME)
	@echo "$(GREEN)$(BOLD)✅ $(NAME) created!$(RESET)"

$(MAND_DIR)/cub3D: FORCE
	@echo "$(BLUE)$(BOLD)🚀 Building MANDATORY version...$(RESET)"
	@$(MAKE) -C $(MAND_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_DIR)/cub3D
	@cp $(BONUS_DIR)/cub3D ./$(NAME_BONUS)
	@echo "$(GREEN)$(BOLD)✅ $(NAME_BONUS) created!$(RESET)"

$(BONUS_DIR)/cub3D: FORCE
	@echo "$(YELLOW)$(BOLD)🌟 Building BONUS version...$(RESET)"
	@$(MAKE) -C $(BONUS_DIR)

FORCE:

clean:
	@echo "$(RED)🧹 Cleaning...$(RESET)"
	-@$(MAKE) -C $(MAND_DIR) clean
	-@$(MAKE) -C $(BONUS_DIR) clean

fclean:
	@echo "$(RED)🗑️  Full clean...$(RESET)"
	-@$(MAKE) -C $(MAND_DIR) fclean
	-@$(MAKE) -C $(BONUS_DIR) fclean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

rebonus: fclean bonus

# Debug targets
debug: FORCE
	@echo "$(YELLOW)$(BOLD)🐛 Debug MANDATORY with Valgrind$(RESET)"
	@if [ -z "$(MAP)" ]; then \
		echo "$(RED)Error: MAP variable not set$(RESET)"; \
		echo "$(YELLOW)Usage: make debug MAP=<file.cub>$(RESET)"; \
		echo "$(BLUE)Example: make debug MAP=map.cub$(RESET)"; \
		exit 1; \
	fi
	@$(MAKE) -C $(MAND_DIR) CFLAGS="-Wall -Wextra -Werror -MMD -MP -g3"
	@cp $(MAND_DIR)/cub3D ./$(NAME)
	valgrind $(VALGRIND_FLAGS) ./$(NAME) $(MAP)

debug-bonus: FORCE
	@echo "$(YELLOW)$(BOLD)🐛 Debug BONUS with Valgrind$(RESET)"
	@if [ -z "$(MAP)" ]; then \
		echo "$(RED)Error: MAP variable not set$(RESET)"; \
		echo "$(YELLOW)Usage: make debug-bonus MAP=<file.cub>$(RESET)"; \
		echo "$(BLUE)Example: make debug-bonus MAP=map.cub$(RESET)"; \
		exit 1; \
	fi
	@$(MAKE) -C $(BONUS_DIR) CFLAGS="-Wall -Wextra -Werror -MMD -MP -g3"
	@cp $(BONUS_DIR)/cub3D ./$(NAME_BONUS)
	valgrind $(VALGRIND_FLAGS) ./$(NAME_BONUS) $(MAP)

fdebug: FORCE
	@echo "$(YELLOW)$(BOLD)🐛 Full Debug MANDATORY$(RESET)"
	@if [ -z "$(MAP)" ]; then \
		echo "$(RED)Error: MAP variable not set$(RESET)"; \
		echo "$(YELLOW)Usage: make fdebug MAP=<file.cub>$(RESET)"; \
		echo "$(BLUE)Example: make fdebug MAP=map.cub$(RESET)"; \
		exit 1; \
	fi
	@$(MAKE) -C $(MAND_DIR) CFLAGS="-Wall -Wextra -Werror -MMD -MP -g3 -DDEBUG_MODE=1"
	@cp $(MAND_DIR)/cub3D ./$(NAME)
	DEBUG_MODE=1 valgrind $(VALGRIND_FLAGS) --trace-children=yes ./$(NAME) $(MAP)

fdebug-bonus: FORCE
	@echo "$(YELLOW)$(BOLD)🐛 Full Debug BONUS$(RESET)"
	@if [ -z "$(MAP)" ]; then \
		echo "$(RED)Error: MAP variable not set$(RESET)"; \
		echo "$(YELLOW)Usage: make fdebug-bonus MAP=<file.cub>$(RESET)"; \
		echo "$(BLUE)Example: make fdebug-bonus MAP=map.cub$(RESET)"; \
		exit 1; \
	fi
	@$(MAKE) -C $(BONUS_DIR) CFLAGS="-Wall -Wextra -Werror -MMD -MP -g3 -DDEBUG_MODE=1"
	@cp $(BONUS_DIR)/cub3D ./$(NAME_BONUS)
	DEBUG_MODE=1 valgrind $(VALGRIND_FLAGS) --trace-children=yes ./$(NAME_BONUS) $(MAP)

gdb: FORCE
	@echo "$(PURPLE)$(BOLD)🔍 GDB Debug MANDATORY$(RESET)"
	@if [ -z "$(MAP)" ]; then \
		echo "$(RED)Error: MAP variable not set$(RESET)"; \
		echo "$(YELLOW)Usage: make gdb MAP=<file.cub>$(RESET)"; \
		echo "$(BLUE)Example: make gdb MAP=map.cub$(RESET)"; \
		exit 1; \
	fi
	@$(MAKE) -C $(MAND_DIR) CFLAGS="-Wall -Wextra -Werror -MMD -MP -g3"
	@cp $(MAND_DIR)/cub3D ./$(NAME)
	gdb --args ./$(NAME) $(MAP)

gdb-bonus: FORCE
	@echo "$(PURPLE)$(BOLD)🔍 GDB Debug BONUS$(RESET)"
	@if [ -z "$(MAP)" ]; then \
		echo "$(RED)Error: MAP variable not set$(RESET)"; \
		echo "$(YELLOW)Usage: make gdb-bonus MAP=<file.cub>$(RESET)"; \
		echo "$(BLUE)Example: make gdb-bonus MAP=map.cub$(RESET)"; \
		exit 1; \
	fi
	@$(MAKE) -C $(BONUS_DIR) CFLAGS="-Wall -Wextra -Werror -MMD -MP -g3"
	@cp $(BONUS_DIR)/cub3D ./$(NAME_BONUS)
	gdb --args ./$(NAME_BONUS) $(MAP)

norm:
	@echo "$(BLUE)$(BOLD)📏 Checking norm...$(RESET)"
	@$(MAKE) -C $(MAND_DIR) norm
	@$(MAKE) -C $(BONUS_DIR) norm

help:
	@echo "$(BOLD)$(PURPLE)Cub3D Makefile$(RESET)"
	@echo ""
	@echo "$(BOLD)$(BLUE)Build:$(RESET)"
	@echo "  $(GREEN)make$(RESET)              - Build mandatory ($(NAME))"
	@echo "  $(YELLOW)make bonus$(RESET)        - Build bonus ($(NAME_BONUS))"
	@echo "  $(BLUE)make re$(RESET)           - Rebuild mandatory"
	@echo "  $(BLUE)make rebonus$(RESET)      - Rebuild bonus"
	@echo ""
	@echo "$(BOLD)$(YELLOW)Debug:$(RESET)"
	@echo "  $(YELLOW)make debug MAP=file.cub$(RESET)       - Valgrind mandatory"
	@echo "  $(YELLOW)make debug-bonus MAP=file.cub$(RESET) - Valgrind bonus"
	@echo "  $(YELLOW)make fdebug MAP=file.cub$(RESET)      - Full debug mandatory"
	@echo "  $(YELLOW)make fdebug-bonus MAP=file.cub$(RESET)- Full debug bonus"
	@echo "  $(PURPLE)make gdb MAP=file.cub$(RESET)         - GDB mandatory"
	@echo "  $(PURPLE)make gdb-bonus MAP=file.cub$(RESET)   - GDB bonus"
	@echo ""
	@echo "$(BOLD)$(RED)Clean:$(RESET)"
	@echo "  $(RED)make clean$(RESET)        - Remove objects"
	@echo "  $(RED)make fclean$(RESET)       - Remove all"
	@echo ""
	@echo "$(BOLD)$(BLUE)Other:$(RESET)"
	@echo "  $(BLUE)make norm$(RESET)         - Check norminette"
	@echo "  $(PURPLE)make help$(RESET)         - Show this message"
