# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 07:48:53 by tchartie          #+#    #+#              #
#    Updated: 2025/01/27 22:59:35 by tchartie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============ NAME ============#

NAME		=	Bureaucrat

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
				Bureaucrat.cpp \
				Form.cpp
OBJS		=	$(SRCS:.cpp=.o)

all : 			$(NAME)

$(NAME) :		$(OBJS)
				@$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)Exercice 01 successfully compiled! $(BASE_COLOR)"

%.o :			%.cpp
				@echo "$(YELLOW)Compiling: $< $(BASE_COLOR)"
				@$(CPP) $(CFLAGS) -c $< -o $@

clean :
				@rm -rf $(OBJS)
				@echo "$(BLUE)Exercice 01 objects files cleanned! $(BASE_COLOR)"

fclean :		clean
				@rm -rf $(NAME)
				@echo "$(CYAN)Exercice 01 executable file cleanned! $(BASE_COLOR)"

re :			fclean all

.PHONY :		all clean fclean re