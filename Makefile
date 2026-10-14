
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = ft_printf.c ft_print_numbers.c ft_print_string.c ft_print_hex.c ft_print_pointer.c

OBJS = $(SOURCES:.c=.o)

# RULE TO CREATE A LIBRARY
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	@$(AR) $@ $(OBJS)
	@echo "********************************"
	@echo "Compilation $(NAME) completed"
	@echo "********************************"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# CREATOR OBJS RULE
%.o : %.c
	@echo "Compiling..."
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c  $< -o $@

all:  $(NAME)

# RULE: DELETE OBJECT FILES
clean:
	@echo "Deleting objects files (*.o)..."
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf *.o

# RULE: DELETE OBJECT FILES AND LIBRARY
fclean: clean
	@echo "Deleting object files and library..."
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

# RULE: RECOMPILES ALL
re: fclean all
	@echo "Recompiling project..."

# PHONY TARGETS
.PHONY: all clean fclean re 
