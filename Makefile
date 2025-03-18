# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 14:04:53 by mmeuric           #+#    #+#              #
#    Updated: 2025/03/18 04:51:23 by mmeuric          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

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

SRCS = main.c $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c, $(OBJSFOLDER)%.o, $(SRCS))

# Gestion des Builtins
BUILTINS_FOLD = src/cmds_minishell
BUILTINS_FILES = builtin_dispatcher.c global_utils.c global_utils2.c lst_operations.c parse_utils.c \
                 src/cd/cd.c src/cd/cds_nuts.c src/cd/path_utils.c \
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
all: $(OBJSFOLDER) $(LIBFT) $(L_BUILTINS) $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C src/libft

$(OBJSFOLDER):
	@mkdir -p $(OBJSFOLDER) $(foreach dir, $(SRC_DIRS), $(OBJSFOLDER)$(dir))

$(L_BUILTINS): $(SRCS_BUILTINS)
	@make -C $(BUILTINS_FOLD)

$(NAME): $(OBJS) $(L_BUILTINS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME) -L$(BUILTINS_FOLD) -lbuiltins -Lsrc/libft -lft $(LIB)

# Compilation des fichiers .c en .o
$(OBJSFOLDER)%.o: %.c $(GLOBAL_HEADERS)
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJSFOLDER)
	@make clean -C src/libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C src/libft

re: fclean all

.PHONY: all clean fclean re
