# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 18:00:44 by iderighe          #+#    #+#              #
#    Updated: 2022/10/25 11:22:40 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Containers

INC		=	Includes

CXC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -g -Wshadow -std=c++98 -I $(INC)
CDEP	=	-MMD
# -Wshadow : Warn whenever a local variable or type declaration shadows another 
#             variable, parameter, type or class member
CFA		=	-fsanitize=address -g3
RM		=	/usr/bin/rm -rf

vpath %.cpp Srcs

SRC		=	Srcs/main.cpp \
# SRC		=	Srcs/subject_main.cpp \

OBJ		=	$(SRC:Srcs/%.cpp=Objs/%.o)
DEP		=	$(SRC:Srcs/%.cpp=Objs/%.d)


all			:	obj $(NAME)

-include $(DEP)

$(NAME)		:	$(OBJ)
				$(CXC) $(CFLAGS) -o $(NAME) $(SRC)

obj			:
			@if [ ! -d "./Objs" ]; then\
				echo "mkdir -p Objs";\
				mkdir -p Objs;\
			fi
				@echo ""

Objs/%.o	:	Srcs/%.cpp
				$(CXC) -o $@ -c $< $(CFLAGS) $(CDEP)

clean		: 
				$(RM) $(OBJ)
				$(RM) $(DEP)
				$(RM) Objs

fclean		:	clean
				$(RM) $(NAME)

fsa			:	fclean obj $(OBJ)
				$(CXC) $(CFLAGS) $(CDEP) $(CFA) -o $(NAME) $(SRC)

re			:	fclean all

.PHONY		:	all obj clean fclean fsa re