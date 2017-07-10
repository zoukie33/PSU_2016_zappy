##
## Makefile for  in /home/beche/PSU_2016_zappy/srv
## 
## Made by beche
## Login   <francois.beche@epitech.eu>
## 
## Started on  Sun Jun 11 13:56:34 2017 beche
## Last update Sun Jul  2 19:59:35 2017 Elodie
##

CC		=	gcc

RM		=	rm -rf

NAME		=	server

SRC		=	./src/main.c			\
			./src/server.c			\
			./src/server_tools.c		\
			./src/opts1.c			\
			./src/opts2.c			\
			./src/client_tools.c		\
			./src/handle_client.c		\
			./src/handle_guest.c		\
			./src/handle_graph.c		\
			./src/handle_utils.c		\
			./src/inventory.c		\
			./src/cmd/cmd_ia.c		\
			./src/cmd/cmd_graph.c		\
			./src/cmd_parser/cmd_parser.c	\
			./src/cmd_parser/parser_utils.c	\
			./src/world.c			\
			./src/msz_to_pnw.c		\
			./src/plv_to_pic.c		\
			./src/rb/rb.c			\
			./src/rb/rb_tools.c		\
			./src/queue/queue.c		\
			./src/list_client/client.c	\
			./src/list_client/list.c	\
			./src/queue/launcher.c		\
			./src/client_receive.c		\
			./src/move.c			\
			./src/eject.c			\
			./src/take.c			\
			./src/incantation.c		\
			./src/incantation_2.c		\
			./src/check_incantation.c	\
			./src/print_graph.c		\
			./src/check_elevation_1.c	\
			./src/check_elevation_2.c	\
			./src/client_receive2.c		\
			./src/find.c			\
			./src/look.c			\
			./src/look_ptr_fcts.c		\
			./src/manage_east.c		\
			./src/manage_north.c		\
			./src/manage_south.c		\
			./src/manage_west.c		\
			./src/print_inv_1.c		\
			./src/print_inv_2.c		\
			./src/manage_pos_look.c		\
			./src/send_graph_init.c		\
			./src/list_client/display_team_info.c

OBJ		=	$(SRC:.c=.o)

INC		=	-I./inc

CFLAGS		=	$(INC)  -W -Wall -Wextra -Werror -pedantic -g

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
