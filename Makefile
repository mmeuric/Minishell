# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 14:04:53 by mmeuric           #+#    #+#              #
#    Updated: 2025/03/30 03:34:51 by mmeuric          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# Couleurs
RESET		:= \033[0m
BOLD		:= \033[1m
RED		:= \033[91m
DARK_BLUE	:= \033[34m
GREEN		:= \033[92m

# Détection de l'OS et configuration de Readline
ifeq ($(shell uname -s), Darwin)
    RL_PATH = $(shell brew --prefix readline)
endif

LIB     = -L $(RL_PATH)/lib -lreadline
CFLAGS  = -Wall -Wextra -Iinclude -I$(RL_PATH)/include # -fsanitize=address -g
OBJSFOLDER = objs/

# Définition des sources classées par module
SRC_DIRS = src/lexer src/parser src/parser/syntax_tree src/execution src/arg_expansion \
           src/stringbuilder src/error src/heredoc src/signals src/exit

SRCS = src/main.c $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c, $(OBJSFOLDER)%.o, $(SRCS))

# Gestion des Builtins
BUILTINS_FOLD = src/cmds_minishell
BUILTINS_FILES = src/builtin_dispatcher.c src/global_utils.c src/global_utils2.c src/lst_operations.c src/parse_utils.c \
                 src/cd/cd.c src/cd/cd_utils2.c src/cd/path_utils.c \
                 src/echo/echo.c src/echo/echo_utils.c \
                 src/env/env.c src/env/env_utils.c \
                 src/exit/exit.c \
                 src/export/export.c src/export/export_utils.c src/export/validation_utils.c \
                 src/pwd/pwd.c src/pwd/pwd_utils.c \
                 src/unset/unset.c src/unset/unset_utils.c

SRCS_BUILTINS = $(foreach file, $(BUILTINS_FILES), $(BUILTINS_FOLD)/$(file))
L_BUILTINS    = $(BUILTINS_FOLD)/libbuiltins.a

# Libft
LIBFT = src/libft/libft.a

# Headers globaux
GLOBAL_HEADERS = include/globals.h

# Règles de compilation
all: banner $(OBJSFOLDER) $(LIBFT) $(L_BUILTINS) $(NAME)

banner:
	@echo "$(DARK_BLUE)"
	@echo " ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     " 
	@echo " ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     " 
	@echo " ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     " 
	@echo " ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     " 
	@echo " ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗" 
	@echo " ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝" 
	@echo "$(RESET)"

$(LIBFT):
	@make -s -C src/libft
	@echo "$(BOLD)$(RED)[Compiling Libft]$(RESET)"

$(OBJSFOLDER):
	@mkdir -p $(OBJSFOLDER) $(foreach dir, $(SRC_DIRS), $(OBJSFOLDER)$(dir))

$(L_BUILTINS): $(SRCS_BUILTINS)
	@make -s -C $(BUILTINS_FOLD)
	@echo "$(BOLD)$(RED)[Compiling Builtins]$(RESET)"

$(NAME): $(OBJS) $(L_BUILTINS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME) -L$(BUILTINS_FOLD) -lbuiltins -Lsrc/libft -lft $(LIB)
	@echo "$(BOLD)$(GREEN)[Build complete!]$(RESET)"

# Compilation des fichiers .c en .o
$(OBJSFOLDER)%.o: %.c $(GLOBAL_HEADERS)
	@echo "$(BOLD)$(RED)[Compiling $<...]$(RESET)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	@rm -rf $(OBJSFOLDER)
	@make -s -C src/libft clean
	@echo "$(BOLD)$(RED)[Objects removed!]$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -s -C src/libft fclean
	@make -s -C src/cmds_minishell fclean
	@echo "$(BOLD)$(RED)[Executable removed!]$(RESET)"

re: fclean all

.PHONY: all clean fclean re