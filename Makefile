##
## Makefile for  in /home/bourre_a/Semestre_4/PSU_reseau/PSU_2016_zappy
## 
## Made by Bourreau Quentin
## Login   <quentin.bourreau@epitech.eu>
## 
## Started on  Sun Jul  2 14:38:49 2017 Bourreau Quentin
## Last update Sun Jul  2 23:35:05 2017 
##

CC		=	gcc

CPP		= 	g++

RM		=	rm -rf

AI_PATH		=	ia/srcs

SERVER_PATH	=	server

AI		=	zappy_ai

SERVER		=	zappy_server

SERVER_SRC	=	$(SERVER_PATH)/src/main.c			\
			$(SERVER_PATH)/src/server.c			\
			$(SERVER_PATH)/src/server_tools.c            \
			$(SERVER_PATH)/src/opts1.c                   \
			$(SERVER_PATH)/src/opts2.c                   \
                        $(SERVER_PATH)/src/client_tools.c            \
                        $(SERVER_PATH)/src/handle_client.c           \
                        $(SERVER_PATH)/src/handle_guest.c            \
                        $(SERVER_PATH)/src/handle_graph.c            \
                        $(SERVER_PATH)/src/handle_utils.c            \
                        $(SERVER_PATH)/src/inventory.c               \
                        $(SERVER_PATH)/src/cmd/cmd_ia.c              \
                        $(SERVER_PATH)/src/cmd/cmd_graph.c           \
                        $(SERVER_PATH)/src/cmd_parser/cmd_parser.c   \
                        $(SERVER_PATH)/src/cmd_parser/parser_utils.c \
                        $(SERVER_PATH)/src/world.c                   \
                        $(SERVER_PATH)/src/msz_to_pnw.c              \
                        $(SERVER_PATH)/src/plv_to_pic.c              \
                        $(SERVER_PATH)/src/rb/rb.c                   \
                        $(SERVER_PATH)/src/rb/rb_tools.c             \
                        $(SERVER_PATH)/src/queue/queue.c             \
                        $(SERVER_PATH)/src/list_client/client.c      \
                        $(SERVER_PATH)/src/list_client/list.c        \
                        $(SERVER_PATH)/src/queue/launcher.c          \
                        $(SERVER_PATH)/src/client_receive.c          \
                        $(SERVER_PATH)/src/move.c                    \
                        $(SERVER_PATH)/src/eject.c                   \
                        $(SERVER_PATH)/src/take.c                    \
                        $(SERVER_PATH)/src/incantation.c             \
                        $(SERVER_PATH)/src/incantation_2.c           \
                        $(SERVER_PATH)/src/check_incantation.c       \
                        $(SERVER_PATH)/src/print_graph.c             \
			$(SERVER_PATH)/src/check_elevation_1.c       \
                        $(SERVER_PATH)/src/check_elevation_2.c       \
                        $(SERVER_PATH)/src/client_receive2.c         \
                        $(SERVER_PATH)/src/find.c                    \
                        $(SERVER_PATH)/src/look.c                    \
                        $(SERVER_PATH)/src/look_ptr_fcts.c           \
                        $(SERVER_PATH)/src/manage_east.c             \
                        $(SERVER_PATH)/src/manage_north.c            \
                        $(SERVER_PATH)/src/manage_south.c            \
                        $(SERVER_PATH)/src/manage_west.c             \
                        $(SERVER_PATH)/src/print_inv_1.c             \
                        $(SERVER_PATH)/src/print_inv_2.c             \
                        $(SERVER_PATH)/src/manage_pos_look.c         \
                        $(SERVER_PATH)/src/send_graph_init.c         \
                        $(SERVER_PATH)/src/list_client/display_team_info.c

AI_SRC		=	$(AI_PATH)/main.cpp		\
			$(AI_PATH)/Player.cpp		\
			$(AI_PATH)/iaRessource.cpp	\
			$(AI_PATH)/Game.cpp		\
			$(AI_PATH)/ParseSend.cpp

AIOBJ		=	$(AI_SRC:.cpp=.o)

SERVEROBJ	=	$(SERVER_SRC:.c=.o)


CFLAGS		=	-I$(SERVER_PATH)/inc -W -Wall -Wextra -Werror -pedantic

CPPFLAGS		=	-W -Wall -Wextra -I./ia/include/


all		:	$(AI) $(SERVER)

zappy_server	:	$(SERVEROBJ)
			$(CC) -o $(SERVER) $(SERVEROBJ) $(CFLAGS)

zappy_ai	:	$(AIOBJ)
			$(CPP) -o $(AI) $(AIOBJ) $(CPPFLAGS)


clean		:
			$(RM) $(AIOBJ)
			$(RM) $(SERVEROBJ)

fclean		:	clean
			$(RM) $(AI)
			$(RM) $(SERVER)

re		:	fclean all
