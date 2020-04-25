# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 16:16:29 by kibotrel          #+#    #+#              #
#    Updated: 2020/04/25 05:56:20 by demonwaves       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- VARIABLES ---------------------------------#

# Environment.

RM				= rm -rf
TAR				= tar -xf
CURL			= curl -L --output archive.tar
UNAME			= $(shell uname -s)
ABSDIR			= $(shell pwd)

# Executable / Libraries.

FT				= libft.a
NAME			= fdf

# Color codes.

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# Libraries.

LFT_DIR			= libft

# I/O Compilation.

SRCS_DIR		= srcs
OBJS_DIR		= objs

# Location of all header files used in the project.

INCS_DIR		:= incs
INCS_DIR		+= libft/incs

# All the subdirectories used in the project.

OBJS_SUBDIRS	:= core
OBJS_SUBDIRS	+= clean
OBJS_SUBDIRS	+= setup
OBJS_SUBDIRS	+= utils
OBJS_SUBDIRS	+= events
OBJS_SUBDIRS	+= graphic

#------------------------------------ FILES -----------------------------------#

# Every libraries needed to compile the project.

LFT				= $(LFT_DIR)/$(FT)
LSDL			= $(LSDL_DIR)/$(SDL)
LTTF			= $(LTTF_DIR)/$(TTF)

# Used header at each compilation to check file integrity.

INCS			:= incs/env.h
INCS			+= incs/core.h
INCS			+= incs/clean.h
INCS			+= incs/setup.h
INCS			+= incs/utils.h
INCS			+= incs/events.h
INCS			+= incs/structs.h
INCS			+= incs/graphic.h

# Source files.

SRCS			:= core/map.c
SRCS			+= core/hud.c
SRCS			+= core/main.c
SRCS			+= core/hooks.c
SRCS			+= core/usage.c
SRCS			+= core/parsing.c
SRCS			+= clean/env.c
SRCS			+= clean/sdl.c
SRCS			+= clean/ttf.c
SRCS			+= setup/env.c
SRCS			+= setup/sdl.c
SRCS			+= setup/ttf.c
SRCS			+= utils/parsing.c
SRCS			+= utils/graphic.c
SRCS			+= utils/miscellaneous.c
SRCS			+= events/zoom.c
SRCS			+= events/offset.c
SRCS			+= events/rotate.c
SRCS			+= events/colorset.c
SRCS			+= events/projection.c
SRCS			+= events/reset_view.c
SRCS			+= events/scale_height.c
SRCS			+= graphic/gradient.c
SRCS			+= graphic/draw_line.c
SRCS			+= graphic/projection.c


#------------------------------ OPERATING SYSTEM ------------------------------#

# Some changes have to be done depending on which OS we are currently
# dealing with. Darwin is for macOS else would include at least Linux.

ifeq ($(UNAME), Darwin)
	SDL			= libsdl2.a
	TTF			= libsdl2_ttf.a
	CONFIG		= ./configure --prefix
	LSDL_DIR	= $(HOME)/.brew/Cellar/sdl2/2.0.10/lib
	LTTF_DIR	= $(HOME)/.brew/Cellar/sdl2_ttf/2.0.15/lib
	INCS_DIR	+= $(HOME)/.brew/Cellar/sdl2/2.0.10/include/SDL2
	INCS_DIR	+= $(HOME)/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2
else
	SDL			= libSDL2.a
	TTF			= libSDL2_ttf.a
	L_LIBS		= /usr/local/lib
	L_INCS		= /usr/local/include
	URL_SDL		= https://www.libsdl.org/release/SDL2-2.0.10.tar.gz
	URL_TTF		= https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.15.tar.gz
	SRCS_SDL	= SDL2-2.0.10
	SRCS_TTF	= SDL2_ttf-2.0.15
	LSDL_DIR	= $(L_LIBS)
	LTTF_DIR	= $(L_LIBS)
	INCS_DIR	+= $(L_INCS)
	INCS_DIR	+= $(L_INCS)/SDL2

endif

#-------------------------------- MISCELANEOUS --------------------------------#

# Some tricks in order to get the makefile doing his job.

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS			= $(addprefix $(D_OBJS), $(OBJS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(D_OBJS)$(dir))

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled.

CC				= gcc
OBJS			= $(SRCS:.c=.o)

# Linked libraries at compile time.

LIBS			:= -L$(LSDL_DIR) -lSDL2
LIBS			+= -L$(LTTF_DIR) -lSDL2_ttf
LIBS			+= -L$(LFT_DIR) -lft
LIBS			+= -lm

# Compilation flags.

CFLAGS			= $(C_INCS) -Wall -Wextra -Werror

#------------------------------------ RULES -----------------------------------#

# Redefinition of the implicit compilation rule to prompt some informations.

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Implicit make rule simply using dependancies to compile our project.

all: $(OBJS_DIR) $(C_SUBDIRS) $(NAME)

$(NAME): $(LSDL) $(LTTF) $(LSND) $(LAO) $(LFT) $(LBMP) $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Libraries installation using brew or curl without prompting anything
# on standard output.

$(LSDL):
	@echo "$(GREEN)***   Installing library $(SDL)   ...  ***\n$(RESET)"
	@if [ $(UNAME) = Darwin ]; then												\
		brew install sdl2 > /dev/null 2>&1;										\
	elif [ ! -d "$(SRCS_SDL)" ]; then											\
		sudo apt-get install curl -y > /dev/null 2>&1;							\
		echo "$(GREEN)***   Curl sources   ...   ***\n$(RESET)";				\
		$(CURL) $(URL_SDL) > /dev/null 2>&1;									\
		echo "$(GREEN)***   Unpacking sources   ...   ***\n$(RESET)";			\
		$(TAR) archive.tar;	$(RM) archive.tar;									\
		echo "$(GREEN)***   Configure library   ...   ***\n$(RESET)";			\
		cd $(SRCS_SDL);	./configure > /dev/null 2>&1;							\
		echo "$(GREEN)***   Compile library   ...   ***\n$(RESET)";				\
		sudo make install -j > /dev/null 2>&1;									\
		echo "$(GREEN)***   $(SDL) successfully compiled   ***\n$(RESET)";		\
	fi

$(LTTF):
	@echo "$(GREEN)***   Installing library $(TTF)   ...  ***\n$(RESET)"
	@if [ $(UNAME) = Darwin ]; then												\
		brew install sdl2_ttf > /dev/null 2>&1;									\
	elif [ ! -d "$(SRCS_TTF)" ]; then											\
		sudo apt-get install libfreetype6-dev -y > /dev/null 2>&1;				\
		echo "$(GREEN)***   Curl sources   ...   ***\n$(RESET)";				\
		$(CURL) $(URL_TTF) > /dev/null 2>&1;									\
		echo "$(GREEN)***   Unpacking sources   ...   ***\n$(RESET)";			\
		$(TAR) archive.tar; $(RM) archive.tar;									\
		echo "$(GREEN)***   Configure library   ...   ***\n$(RESET)";			\
		cd $(SRCS_TTF);	./configure > /dev/null 2>&1;							\
		echo "$(GREEN)***   Compile library   ...   ***\n$(RESET)";				\
		sudo make install -j > /dev/null 2>&1;									\
		echo "$(GREEN)***   $(TTF) successfully compiled   ***\n$(RESET)";		\
	fi

# Libraries installion using their own Makefile.

$(LFT):
	@make -sC $(LFT_DIR) -j


# Rules used to create folders if they aren't already existing.

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(C_SUBDIRS):
	@mkdir -p $(C_SUBDIRS)

# Deleting all .o files.

clean:
	@make -sC $(LFT_DIR) clean
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(C_OBJS)

# Deleting all executables and libraries after cleaning up all .o files.

fclean: clean
	@make -sC $(LFT_DIR) fclean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)
	@if [ -f "$(LTTF)" ]; then													\
		echo "$(GREEN)***   Deleting library $(TTF)   ...  ***\n$(RESET)";		\
		if [ $(UNAME) = Darwin ]; then											\
			brew uninstall sdl2_ttf > /dev/null 2>&1;							\
		fi;																		\
	fi
	@if [ -f "$(LSDL)" ]; then													\
		echo "$(GREEN)***   Deleting library $(SDL)   ...  ***\n$(RESET)";		\
		if [ $(UNAME) = Darwin ]; then											\
			brew uninstall --ignore-dependencies sdl2 > /dev/null 2>&1;			\
		fi;																		\
	fi
	@if [ $(UNAME) = Linux ]; then												\
		if [ -d $(SRCS_SDL) ]; then												\
			sudo $(RM) $(SRCS_SDL);												\
		fi;																		\
		if [ -d $(SRCS_TTF) ]; then												\
			sudo $(RM) $(SRCS_TTF);												\
		fi;																		\
		if [ -f $(LSDL) ]; then													\
			sudo $(RM) $(L_LIBS)/libSDL2* $(L_INCS)/SDL2;						\
		fi;																		\
		if [ -f $(LTTF) ]; then													\
			sudo $(RM) $(L_LIBS)/libSDL2* $(L_INCS)/SDL2;						\
		fi;																		\
	fi

# Re-build libs.

re-libs: $(OBJS_DIR) $(C_SUBDIRS) $(C_OBJS)
	@make -sC $(LFT_DIR) re
	@echo "$(YELLOW)      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Re-compile everything.

re: fclean all

# Avoid unexpected behaviour when regular files get the same name
# as the following variables.

.PHONY: all clean fclean re
