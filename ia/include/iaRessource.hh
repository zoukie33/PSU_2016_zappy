//
// iaRessource.hh for  in /home/bourre_a/Semestre_4/cpp/ia_zappy
//
// Made by Bourreau Quentin
// Login   <quentin.bourreau@epitech.eu>
//
// Started on  Mon Jun 26 22:36:19 2017 Bourreau Quentin
// Last update Tue Jun 27 18:16:54 2017 
//

#pragma once

# include <iostream>

class IaRessource
{

private:

  int	_linemate;
  int	_deraumere;
  int	_sibur;
  int	_mendiane;
  int	_phiras;
  int	_thystame;
  int	_food;

public:

  IaRessource();
  ~IaRessource();
  int	get_linemate() const;
  int	get_deraumere() const;
  int	get_sibur() const;
  int	get_mendiane() const;
  int	get_phiras() const;
  int	get_thystame() const;
  int	get_food() const;

  void	set_linemate(int);
  void	set_deraumere(int);
  void	set_sibur(int);
  void	set_mendiane(int);
  void	set_phiras(int);
  void	set_thystame(int);
  void	set_food(int);
  void	set_all(int, int, int, int, int, int, int);

};
