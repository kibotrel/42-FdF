# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 22:15:45 by kibotrel          #+#    #+#              #
#    Updated: 2019/02/04 23:44:08 by kibotrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable's name (Can be changed)

NAME		= fdf
LFT			= ./libft/libft.a
# All the directories needed to know where files should be (Can be changed)

OBJDIR		= objs/
SRCDIR		= srcs/
LFTDIR		= libft/
INCDIR		= ./includes/ ./libft/includes/

# Source files (Can be changed)

SRC			= main.c

# Some tricks in order to get the makefile doing his job the way I want (Can't be changed)

CSRC		= $(addprefix $(SRCDIR), $(SRC))
COBJ		= $(addprefix $(OBJDIR), $(OBJ))
INCLUDES	= $(foreach include, $(INCDIR), -I$(include))

# How files should be compiled with set flags (Can be changed)

CC			= gcc
OBJ			= $(SRC:.c=.o)
LIBS		= -L$(LFTDIR) -lft
CFLAGS		= $(INCLUDES) -Wall -Wextra -Werror

# Color codes

GREEN		= \033[32m
YELLOW		= \033[33m
RESET		= \033[0m


# Check if object directory exists, build libft and then the Project
all: $(NAME)

$(NAME): $(LFT) $(OBJDIR) $(COBJ)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) $(LIBS) -o $(NAME) $(COBJ)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Redefinition of implicit compilation rule to prompt some colors and file names during the said compilation

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Compilation rule for function library "libft"

$(LFT):
	@make -sC $(LFTDIR)

# Deleting all .o files and then the directory where they were located

clean:
	@echo "$(GREEN)***   Deleting all object from fdf   ...   ***\n$(RESET)"
	@rm -f $(COBJ)

# Deleting the executable after cleaning up all .o files

fclean: clean
	@make -sC $(LFTDIR) fclean
	@echo "$(GREEN)***   Deleting executable file from fdf   ...   ***\n$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
