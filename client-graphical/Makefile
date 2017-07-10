##
## Makefile for  in /home/elodie/C/reseau/Zappy/client
## 
## Made by Elodie
## Login   <elodie>
## 
## Started on  Wed Jun  7 16:59:28 2017 Elodie
## Last update Sun Jul  2 09:55:17 2017 
##

NAME	=	zappy_graphical

SRC	=	srcs/Case.cpp		\
		srcs/Map.cpp		\
		srcs/ParseSend.cpp	\
		srcs/Graphical.cpp	\
		srcs/Game.cpp		\
		srcs/main.cpp		 \
		srcs/Player.cpp		\

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++ -g

RM	=	rm -f

CPPFLAGS =	-std=c++11 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -Iinclude/ -g3

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
