# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 13:27:42 by samunyan          #+#    #+#              #
#    Updated: 2022/04/12 13:27:43 by samunyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

#Directories
OBJDIR			= 	./objs
SRCDIR			=	./srcs
LIBFTDIR		=	./libft
HEADDIRS		=	./include $(LIBFTDIR)/include

#Files
FILES	=	ft_printf.c \
			ft_parse_format.c \
			ft_get_spec.c \
			ft_convert_diux.c \
			ft_convert_scp.c \
			ft_convert_percent.c \
			ft_filling.c \
			ft_padding.c
OBJS	=	$(addprefix $(OBJDIR)/, $(FILES:.c=.o))
SRCS	= 	$(addprefix $(SRCDIR)/, $(FILES))

#Libs
LIBFT	=	$(LIBFTDIR)/libft.a

#Compiler
SYSTEM		 := $(shell uname)
ifeq ($(SYSTEM),Linux)
CC			=	clang
else
CC			= 	gcc
endif
CFLAGS	=	-Wall -Werror -Wextra $(HEADDIRS:%=-I %)
ifeq ($(SANITIZER), 1)
		CFLAGS	+=	-g -fsanitize=address
endif
ifeq ($(DEBUG), 1)
		CFLAGS	+=	-g
endif

.PHONY:		all FORCE clean fclean re sanitizer debug bonus

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			@cp $(LIBFT) $(NAME)
			@ar rcs $(NAME) $(OBJS)
			@test -z '$(filter %.o,$?)' || (echo ✅ $(BBlue) [$(NAME)]"\t"$(BGreen)Compilation done.$(Color_Off) && \
				echo $(White)"\t\t\t"Compiler flags: $(CFLAGS)$(Color_Off))

$(OBJDIR)/%.o:  $(SRCDIR)/%.c
			@mkdir -p $(dir $@)
			@echo ⌛ $(BBlue)[$(NAME)]"\t"$(Yellow)Compiling $<$(Color_Off)
			@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): FORCE
			@make -C $(LIBFTDIR)

FORCE:

clean:
			@if [ -d $(OBJDIR) ]; then \
  					rm -rf $(OBJDIR); \
  					echo 🗑$(BBlue)[$(NAME)]"\t"$(BGreen)Object files removed.$(Color_Off); \
  			fi
			@make clean -C $(LIBFTDIR)

fclean:		clean
			@if [ -f $(NAME) ]; then \
					rm -rf $(NAME); \
					echo 🗑$(BBlue)[$(NAME)]"\t"$(BGreen)Library removed.$(Color_Off); \
			fi
			make fclean -C $(LIBFTDIR)

re:			fclean all

sanitizer:
			@SANITIZER=1 make re

debug:
			@DEBUG=1 make re

bonus:		all

# Colors
## Reset
Color_Off='\033[0m'       # Text Reset
## Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White
## Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White
## Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White
## Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White
## Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue