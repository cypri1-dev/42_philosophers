# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 13:34:36 by cyferrei          #+#    #+#              #
#    Updated: 2024/08/08 17:55:01 by cyferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g3
OBJDIR = obj
# -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -fstack-protector-strong -fno-optimize-sibling-calls

LIBFT_PHILOSOPHERS_PATH = libft
LIBFT_PHILOSOPHERS = libft/libft.a

BOLD    = \e[1m
FADE    = \e[2m
ITA     = \e[3m
BLINK   = \e[5m
GREEN   = \e[38;5;76m
RED     = \e[38;5;196m
YELLOW  = \e[38;5;227m
ORANGE  = \e[38;5;208m
PURPLE  = \e[38;5;201m
LBLUE   = \e[38;5;45m
BLUE    = \e[38;5;27m
INDI    = \e[38;5;91m
SPINK   = \e[38;5;225m
PEACH   = \e[38;5;223m
GREY    = \e[38;5;254m
RESET   = \e[00m

SOURCE = src/
MAIN = main.c
PARSER = parser.c parser_utils.c
INIT = init.c
PRT_DBG = print_debug.c
THRDS = threads.c
ERR = error_handler.c
PHILOSPHERS = $(MAIN) $(PARSER) $(INIT) $(PRT_DBG) $(THRDS) $(ERR)

SRC = $(addprefix $(SOURCE), $(PHILOSPHERS))
OBJS = $(patsubst $(SOURCE)%.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
		@echo "$(BOLD)Linking...$(RESET)"
		@make -sC $(LIBFT_PHILOSOPHERS_PATH)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PHILOSOPHERS) -o $(NAME)
		@echo "$(GREEN)Executable '$(NAME)' created successfully!$(RESET)"

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SOURCE)%.c
	@echo "$(BOLD)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$@ compiled successfully!$(RESET)"

clean:
	@echo "$(BOLD)Cleaning object files...$(RESET)"
	$(RM) $(OBJDIR)
	@make -s clean -C $(LIBFT_PHILOSOPHERS_PATH)
	@echo "$(GREEN)Object files cleaned successfully!$(RESET)"

fclean: clean
	@echo "$(BOLD)Cleaning executable...$(RESET)"
	@make -s fclean -C $(LIBFT_PHILOSOPHERS_PATH)
	$(RM) $(NAME)
	@echo "$(GREEN)Executable cleaned successfully!$(RESET)"

leak:
	valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes -q ./philosophers

re: fclean all

.PHONY: all clean fclean re
