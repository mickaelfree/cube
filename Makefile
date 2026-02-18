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

# Rules
.PHONY: all clean fclean re bonus rebonus help

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

help:
	@echo "$(BOLD)$(PURPLE)Cub3D Makefile$(RESET)"
	@echo ""
	@echo "$(BOLD)$(BLUE)Usage:$(RESET)"
	@echo "  $(GREEN)make$(RESET)          - Build mandatory ($(NAME))"
	@echo "  $(YELLOW)make bonus$(RESET)    - Build bonus ($(NAME_BONUS))"
	@echo "  $(RED)make clean$(RESET)    - Remove objects"
	@echo "  $(RED)make fclean$(RESET)   - Remove all"
	@echo "  $(BLUE)make re$(RESET)       - Rebuild mandatory"
	@echo "  $(BLUE)make rebonus$(RESET)  - Rebuild bonus"
	@echo "  $(PURPLE)make help$(RESET)     - Show this"
