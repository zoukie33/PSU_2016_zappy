//
// iaRessource.cpp for  in /home/bourre_a/Semestre_4/cpp/ia_zappy
//
// Made by Bourreau Quentin
// Login   <quentin.bourreau@epitech.eu>
//
// Started on  Mon Jun 26 22:42:08 2017 Bourreau Quentin
// Last update Fri Jun 30 14:22:50 2017 Bourreau Quentin
//

#include <iostream>
#include "iaRessource.hh"

IaRessource::IaRessource()
{
  this->_linemate = 0;
  this->_deraumere = 0;
  this->_sibur = 0;
  this->_mendiane = 0;
  this->_phiras = 0;
  this->_thystame = 0;
  this->_food = 0;
}

IaRessource::~IaRessource()
{
}

int	IaRessource::get_linemate() const
{
  return (this->_linemate);
}

int	IaRessource::get_deraumere() const
{
  return (this->_deraumere);
}

int	IaRessource::get_sibur() const
{
  return (this->_sibur);
}

int	IaRessource::get_mendiane() const
{
  return (this->_mendiane);
}

int	IaRessource::get_phiras() const
{
  return (this->_phiras);
}

int	IaRessource::get_thystame() const
{
  return (this->_thystame);
}

int	IaRessource::get_food() const
{
  return (this->_food);
}

void	IaRessource::set_linemate(int val)
{
  this->_linemate += val;
  if (this->_linemate < 0)
    this->_linemate = 0;
}

void	IaRessource::set_deraumere(int val)
{
  this->_deraumere += val;
  if (this->_deraumere < 0)
    this->_deraumere = 0;
}

void	IaRessource::set_sibur(int val)
{
  this->_sibur += val;
  if (this->_sibur < 0)
    this->_sibur = 0;
}

void	IaRessource::set_mendiane(int val)
{
  this->_mendiane += val;
  if (this->_mendiane < 0)
    this->_mendiane = 0;
}

void	IaRessource::set_phiras(int val)
{
  this->_phiras += val;
  if (this->_phiras < 0)
    this->_phiras = 0;
}

void	IaRessource::set_thystame(int val)
{
  this->_thystame += val;
  if (this->_thystame < 0)
    this->_thystame = 0;
}

void	IaRessource::set_food(int val)
{
  this->_food += val;
  if (this->_food < 0)
    this->_food = 0;
}

void	IaRessource::set_all(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame)
{
  this->_linemate = linemate;
  this->_deraumere = deraumere;
  this->_sibur = sibur;
  this->_mendiane = mendiane;
  this->_phiras = phiras;
  this->_thystame = thystame;
  this->_food = food;
  std::cout << "Inventory" << std::endl;
  std::cout << "Linemate : " << linemate << std::endl;
  std::cout << "Deraumere: " << deraumere << std::endl;
  std::cout << "Sibur    : " << sibur << std::endl;
  std::cout << "Mendiane : " << mendiane << std::endl;
  std::cout << "Phiras   : " << phiras << std::endl;
  std::cout << "Thystame : " << thystame << std::endl;
  std::cout << "Food     : " << food << std::endl;
}
