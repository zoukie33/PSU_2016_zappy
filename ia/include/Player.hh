//
// Player.hh for  in /home/bourre_a/Semestre_4/cpp/ia_zappy
//
// Made by Bourreau Quentin
// Login   <quentin.bourreau@epitech.eu>
//
// Started on  Mon Jun 26 22:59:23 2017 Bourreau Quentin
// Last update Sun Jul  2 14:15:07 2017 Bourreau Quentin
//

#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include <stdlib.h>


# include "iaRessource.hh"

# define NORD 0
# define EST 1
# define SUD 2
# define WEST 3

# define RIGHT 10
# define LEFT 11

class	Player
{

private:

  int		_level;
  int		_orientation;
  int		_health;
  int		_fd;
  int		_dead;
  int		_look[4][7];
public:

  IaRessource	_ressource;
  Player(int);
  Player(Player &a);
  ~Player();
  std::string	readServer();
  void	parse_case(std::string);
  int	get_level() const;
  int	get_number_player() const;
  int	get_orientation() const;
  int	get_health() const;
  int	get_dead() const;
  int	get_look_case(int) const;
  int	get_look_case_ressource(int, int) const;
  int	get_direction() const;
  void	set_dead(int);
  void	setFd(int);
  void	set_health(int);
  void	set_orientation(int);
  int	upgrade_level();
  void	go_to_broadcast(int);
  void	take_food();
  void	take_linemate();
  void	take_deraumere();
  void	take_sibur();
  void	take_mendiane();
  void	take_phiras();
  void	take_thystame();
  void	set_food();
  void	set_linemate();
  void	set_deraumere();
  void	set_sibur();
  void	set_mendiane();
  void	set_phiras();
  void	set_thystame();
  void	go_up();
  void	turn_left();
  void	turn_right();
  void	eject();
  void	fork_player();
  int	connect_nbr();
  void	broadcast(std::string);
  void	inventory();
  void	look();
};
