/*
** server.h for  in /home/beche/PSU_2016_zappy/francois/inc
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Thu Jun 29 17:04:25 2017 beche
** Last update Sun Jul  2 23:02:26 2017 Elodie
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include "mtype.h"
#include "client.h"
#include "ia.h"
#include "graph.h"
#include "list_client.h"

typedef struct          s_world
{
  int			players;
  t_pos                 pos;
  t_inv                 *inv;
}                       t_world;

typedef struct          s_args
{
  int                   port;
  t_pos               dim;
  char                  **nameT;
  int                   nbClients;
  int                   freq;
  int                 nb_team;
}                       t_args;

typedef struct		s_team
{
  char			*name;
  t_c_list		*clients;
  int			nb_free_eggs;
}			t_team;

typedef	struct		s_server
{
  t_world		**world;
  struct sockaddr_in	sin;
  int			fd;
  fd_set		fd_read;
  m_int			accept;
  t_args		*args;
  t_cmd_ia			*ia_cmd;
  t_cmd_graph			*g_cmd;
  t_team		*teams;
  t_c_list		*guest;
  t_c_list		*graph;

  m_int			run_server;
  m_void		too_much_clients;
  m_double			get_ms_time;
}			    t_server;

t_server		*construct_server(t_server*, t_args*);
struct s_client		*construct_client(int, t_server *);
int			log_client(t_server*, struct s_client*, int, t_cmd*);
int			is_opt(char **, int, t_args*, int);
void			my_fd_set(t_server*, int*);
void			my_fd_isset(t_server*);
int			my_socket(t_server*, int);

/*******opts1.c*********/
char            **opts();
int             check_opt(char **, char *);
int             is_opt(char **, int, t_args *, int);
int             p_opt(char **, t_args *, int, int);
int             x_opt(char **, t_args *, int, int);

/***********************/
/*******opts2.c*********/
int             is_num(char *);
int             y_opt(char **, t_args *, int, int);
int             n_opt(char **, t_args *, int, int);
int             c_opt(char **, t_args *, int, int);
int             f_opt(char **, t_args *, int, int);
/***********************/
/****handle_client.c****/
int		init_client(t_server*);

void		handle_client(t_server*, struct s_client*, t_c_list *);
void		handle_guest(t_server*, struct s_client*);
void		handle_graph(t_server*, struct s_client*);

/**********************/
/****handle_utils.c****/
int		is_valid_team(t_server*, char*);
void		quit_client(t_server*, t_c_list*, struct s_client*);
int		calc_fct_time(t_server*, int, t_cmd*);
int		check_fct_time(t_server*, int, t_cmd*);
char		*m_read(t_server*, t_client*, t_c_list*);
/**********************/
/******cmd_ia.c********/

void            cmd_broadcast(t_server *, t_cmd *, int);
void            cmd_eject(t_server *, t_cmd *, int);
void            cmd_forward(t_server *, t_cmd *, int);
void            cmd_inventory(t_server *, t_cmd *, int);
void            cmd_look(t_server *, t_cmd *, int);
void            cmd_set(t_server *, t_cmd *, int);
void            cmd_connect_nbr(t_server *, t_cmd *, int);
void            cmd_fork(t_server *, t_cmd *, int);
void            cmd_left(t_server *, t_cmd *, int);
void            cmd_right(t_server *, t_cmd *, int);
void            cmd_take(t_server *, t_cmd *, int);
void            cmd_incantation(t_server *, t_cmd *, int);

/*****************/
/**********cmd_graph.c********/
void            cmd_sst();
void            cmd_seg();
void            cmd_smg();
void            cmd_suc();
void            cmd_sbp();
void            cmd_msz(t_server *server, t_cmd *, int fd);
void            cmd_bct(t_server *serv, t_cmd *cmd, int);
void            cmd_mct(t_server *serv, t_cmd *, int);
void            cmd_tna(t_server *, t_cmd*, int);
void            cmd_pnw(t_server *, t_cmd *, int);
void            cmd_plv(t_server *, t_cmd *, int);
void            cmd_pin(t_server *, t_cmd *, int);
void            cmd_ppo(t_server *, t_cmd *, int);
void            cmd_pex();
void            cmd_pbc();
void            cmd_pic();
void            cmd_pie();
void            cmd_pfk();
void            cmd_pdr();
void            cmd_pgt();
void            cmd_pdi();
void            cmd_enw();
void            cmd_eht();
void            cmd_ebo();
void            cmd_edi();
void            cmd_sgt();

/*****************************/
/******cmd_parser.c****/
t_cmd           *cmd_parser(char*, t_cmd*);
int		get_nb_arg(char *);
char            **malloc_char_2d(char **, int, int);
char            **fill_tab(char*, char**);
void            display_cmd(t_cmd*);
/**********************/
/******world.c**********/
void            print_world(t_world **world, int , int, int);
int             init_world(t_server *);
/***********************/

t_launcher      *construct_launcher();
t_cmd_ia        *construct_cmd_ia(t_cmd_ia*, t_server*);
int             launcher(t_server *, t_client *);
int		check_life(t_server *, t_client *, t_c_list *);

/*********move.c*******/
void		move_up(t_server *, int);
void		move_down(t_server *, int);
void		move_left(t_server *, int);
void		move_right(t_server *, int);
/**********************/

t_client	*find_client(t_server *, int);
int		get_stone_index(char *);

/********eject.c*******/
int		find_orientation(t_client *, orientation);
/**********************/
/********incantation***/
bool		check_players_nbr(t_server *, t_client *, int);
void		empty_tile(t_server *, int, int);
void		elevation_one(t_server *, t_client *, int);
void		elevation_two(t_server *, t_client *, int);
void		elevation_three(t_server *, t_client *, int);
void		elevation_four(t_server *, t_client *, int);
void		elevation_five(t_server *, t_client *, int);
void		elevation_six(t_server *, t_client *, int);
void		elevation_seven(t_server *, t_client *, int);
/**********************/

void		display_team_info(t_server *, t_client *, int);
void		eject_players(t_server *, fct m[], t_client *, int i[]);
void		print_graph(t_server *, const char *);
void		print_take_set_graph(t_server *, t_client *, int);

/*****elevation.c*****/
bool		check_elevation_1(t_server *, int, int);
bool		check_elevation_2(t_server *, int, int);
bool		check_elevation_3(t_server *, int, int);
bool		check_elevation_4(t_server *, int, int);
bool		check_elevation_5(t_server *, int, int);
bool		check_elevation_6(t_server *, int, int);
bool		check_elevation_7(t_server *, int, int);
/*********************/

void		lvl_up(t_server *, int, int);
void		end_incantation(t_server *, int, int);

/******LOOK**********/
void		exec_look_fct(t_world **, t_server *, int);
void		look_North(t_server *, int);
void		look_East(t_server *, int);
void		look_West(t_server *, int);
void		look_South(t_server *, int);
int		manage_pos_y(int, t_server *);
int		manage_pos_x(int, t_server *);
int		manage_delim(int, t_server *);
void		print_bag(t_server *, int, int);
void		print_food(t_server *, int, int, int);
void		print_linemate(t_server *, int, int, int);
void		print_deraumere(t_server *, int, int, int);
void		print_sibur(t_server *, int, int, int);
void		print_mendiane(t_server *, int, int, int);
int		get_nbr_tiles(t_server *, int);
/********************/
/******INIT-GRAPH****/
void		send_graph_init_msz(t_server *, t_client *);
void		send_graph_init_mct(t_server *, t_client *);
void		send_graph_init_tna(t_server *, t_client *);
/********************/
#endif /* !SERVER_H_ */
