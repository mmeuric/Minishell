CC = cc

NAME = libbuiltins.a

EXEC = minishell

CFLAGS = -Wall -Wextra -Werror -Iinclude -DFROM_SUBMODULE # -g -fsanitize=address
ECHO   = src/echo/echo.c src/echo/echo_utils.c
CD     = src/cd/cd.c src/cd/cds_nuts.c src/cd/path_utils.c
EXIT   = src/exit/exit.c
PWD    = src/pwd/pwd.c src/pwd/pwd_utils.c
UNSET  = src/unset/unset.c src/unset/unset_utils.c
EXPORT = src/export/export.c src/export/export_utils.c src/export/validation_utils.c src/export/utils.c
ENV    = src/env/env.c src/env/env_utils.c

M_SRC = $(ECHO) $(CD) $(EXIT) $(PWD) $(UNSET) $(EXPORT) $(ENV) src/global_utils.c src/global_utils2.c src/builtin_dispatcher.c src/lst_operations.c

EXEC_SRC = main.c $(M_SRC)

M_HEAD = ./builtin_dispatcher.h ./cd/cd.h ./cd/cd_utils.h ./echo/echo.h ./echo/echo_utils.h ./env/env_utils.h ./exit/exit_utils.h ./export/export_utils.h ./global_utils.h ./lst_operations.h ./pwd/pwd_utils.h ./unset/unset_utils.h ./utils.h

M_OBJ = $(M_SRC:.c=.o)
EXEC_OBJ = main.o $(M_SRC:.c=.o)

LIBFT = ../libft

all: $(NAME) clean

$(NAME): rf_lib $(M_OBJ)
	ar rcs $@ $(M_OBJ)

exec:	$(EXEC_OBJ) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(EXEC_OBJ) $(LIBFT)/libft.a -o $(EXEC)

cp: fclean
	find . -name "*~" -delete

$(LIBFT)/libft.a:
	make -C $(LIBFT) all

%.o : %.c $(M_HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
rf_lib:
	rm -f $(NAME)
clean:
	rm -rf $(M_OBJ)

exec_clean:
	make -C $(LIBFT) clean
	rm -rf $(EXEC_OBJ)

fclean: clean
	rm -rf $(NAME)

exec_fclean: exec_clean
	rm -rf $(EXEC)
	rm -rf $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re bonus
