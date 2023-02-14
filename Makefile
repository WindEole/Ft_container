# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 18:00:44 by iderighe          #+#    #+#              #
#    Updated: 2022/12/05 15:17:45 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Containers
NAME_FT	=	ft_containers
NAME_STD =	std_containers

INC		=	Includes

CXC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -g -Wshadow -std=c++98 -I $(INC)
CDEP	=	-MMD
CFA		=	-fsanitize=address -g3
RM		=	/usr/bin/rm -rf

vpath %.cpp Srcs

SRC		=	Srcs/main.cpp \

SRC_FT	=	Srcs/main_ft.cpp \

SRC_STD	=	Srcs/main_std.cpp
# SRC		=	Srcs/subject_main.cpp \

OBJ		=	$(SRC:Srcs/%.cpp=Objs/%.o)
OBJ_FT	=	$(SRC_FT:Srcs/%.cpp=Objs/%.o)
OBJ_STD	=	$(SRC_STD:Srcs/%.cpp=Objs/%.o)

DEP		=	$(SRC:Srcs/%.cpp=Objs/%.d)
DEP_FT	=	$(SRC_FT:Srcs/%.cpp=Objs/%.d)
DEP_STD	=	$(SRC_STD:Srcs/%.cpp=Objs/%.d)


all			:	obj $(NAME)

-include $(DEP)

$(NAME)		:	$(OBJ) $(OBJ_FT) $(OBJ_STD)
				$(CXC) $(CFLAGS) -o $(NAME) $(SRC)
				$(CXC) $(CFLAGS) -o $(NAME_FT) $(SRC_FT)
				$(CXC) $(CFLAGS) -o $(NAME_STD) $(SRC_STD)

# $(NAME_FT)	:	$(OBJ)
# 				$(CXC) $(CFLAGS) -o $(NAME_FT) $(SRC_FT)

# $(NAME_STD)	:	$(OBJ)
# 				$(CXC) $(CFLAGS) -o $(NAME_STD) $(SRC_STD)

obj			:
			@if [ ! -d "./Objs" ]; then\
				echo "mkdir -p Objs";\
				mkdir -p Objs;\
			fi
				@echo ""

Objs/%.o	:	Srcs/%.cpp
				$(CXC) -o $@ -c $< $(CFLAGS) $(CDEP)

clean		: 
				$(RM) $(OBJ) $(OBJ_FT) $(OBJ_STD)
				$(RM) $(DEP) $(DEP_FT) $(DEP_STD)
				$(RM) Objs

fclean		:	clean
				$(RM) $(NAME) $(NAME_FT) $(NAME_STD)

fsa			:	fclean obj $(OBJ)
				$(CXC) $(CFLAGS) $(CFA) -o $(NAME) $(NAME_FT) $(NAME_STD) $(SRC) $(SRC_FT) $(SRC_STD)

re			:	fclean all

.PHONY		:	all obj clean fclean fsa re