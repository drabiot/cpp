# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 07:48:53 by tchartie          #+#    #+#              #
#    Updated: 2024/12/05 20:05:22 by tchartie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============ NAME ============#

NAME		=	ClapTrap

#========= COMPILATOR =========#

CPP			=	c++

#=========== FLAGS ============#

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

#=========== COLOR ============#

BASE_COLOR 	=	\033[0;39m
GRAY 		=	\033[0;90m
RED 		=	\033[0;91m
GREEN 		=	\033[0;92m
YELLOW 		=	\033[0;93m
BLUE 		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN 		=	\033[0;96m
WHITE		=	\033[0;97m

#========== SOURCES ===========#

SRCS 		=	main.cpp \
				ClapTrap.cpp
OBJS		=	$(SRCS:.cpp=.o)

all : 			$(NAME)

$(NAME) :		$(OBJS)
				@$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)Exercice 00 successfully compiled! $(BASE_COLOR)"

%.o :			%.cpp
				@echo "$(YELLOW)Compiling: $< $(BASE_COLOR)"
				@$(CPP) $(CFLAGS) -c $< -o $@

clean :
				@rm -rf $(OBJS)
				@echo "$(BLUE)Exercice 00 objects files cleanned! $(BASE_COLOR)"

fclean :		clean
				@rm -rf $(NAME)
				@echo "$(CYAN)Exercice 00 executable file cleanned! $(BASE_COLOR)"

re :			fclean all

.PHONY :		all clean fclean re