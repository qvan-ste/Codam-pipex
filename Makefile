RED =\033[0;31m
ORANGE=\033[0;33m
GREEN =\033[0;32m
NO_COLOUR =\033[0m

CFILES = $(wildcard src/*.c) 

OFILES = $(CFILES:.c=.o)

LFILES = libft/libft.a

CFLAGS = -Wall -Werror -Wextra

NAME = pipex

all: $(NAME)

.c.o:
	@echo "${ORANGE}[${NAME}] Compiling $<${NO_COLOUR}"
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LFILES) $(OFILES) 
	@$(CC) $(CFLAGS) $(OFILES) $(LFILES) -o $(NAME)
	@echo "${GREEN}[${NAME}] Compiling finished${NO_COLOUR}"

$(LFILES): 
	@$(MAKE) --no-print-directory -C ./libft

clean:
	@$(MAKE) clean --no-print-directory -C ./libft
	@rm -f $(OFILES)
	@echo "${RED}[${NAME}] Removing .o files${NO_COLOUR}"

fclean:  clean
	@$(MAKE) libclean --no-print-directory -C ./libft
	@rm -f $(NAME)
	@echo "${RED}[${NAME}] Removing ${NAME}${NO_COLOUR}"

re: fclean all

.PHONY:  all clean fclean re .c.o