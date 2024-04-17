RED =\033[0;31m
ORANGE=\033[0;33m
GREEN =\033[0;32m
NO_COLOUR =\033[0m

CFILES = $(wildcard src/libft/*.c) $(wildcard src/ft_printf/*.c) \
			$(wildcard src/ft_printf_fd/*.c) $(wildcard src/get_next_line/*.c)

OFILES = $(CFILES:.c=.o)
			
CFLAGS = -Wall -Werror -Wextra

CC = cc

NAME = libft.a

all: $(NAME)

.c.o:
	@echo "$(ORANGE)[libft] Compiling $<$(NO_COLOUR)"
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OFILES)
	@ar rcs $(NAME) $(OFILES)
	@echo "$(GREEN)[libft] Compiling finished$(NO_COLOUR)"

clean:
	@echo "$(RED)[libft] Removing .o files$(NO_COLOUR)"
	@rm -f $(OFILES)


fclean:  clean
	@echo "$(RED)[libft] Removing $(NAME)$(NO_COLOUR)"
	@rm -f $(NAME)


libclean:
	@echo "$(RED)[libft] Removing $(NAME)$(NO_COLOUR)"
	@rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re .c.o libclean
