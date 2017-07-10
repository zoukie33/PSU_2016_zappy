//
// Player.cpp for  in /home/bourre_a/Semestre_4/cpp/ia_zappy
//
// Made by Bourreau Quentin
// Login   <quentin.bourreau@epitech.eu>
//
// Started on  Mon Jun 26 23:04:14 2017 Bourreau Quentin
// Last update Sun Jul  2 23:54:33 2017 Bourreau Quentin
//

# include <unistd.h>
# include <string.h>
# include "Player.hh"
# include "ParseSend.hh"

Player::Player(int	fd)
{
  this->_level = 1;
  this->_orientation = NORD;
  this->_health = 10;
  this->_fd = fd;
  this->_dead = 0;
}

Player::Player(Player &a)
{
  this->_level = a.get_level();
  this->_orientation = get_orientation();
  this->_health = a.get_health();
}

Player::~Player()
{
}

std::string	Player::readServer()
{
  size_t        len;
  char          *str;
  FILE          *fd;
  ParseSend     *pars = new ParseSend(this->_fd);
  std::string   res = "";

  str = NULL;
  fd = fdopen(this->_fd, "r+");
  if ((getline(&str, &len, fd)) != -1)
    res = str;
  else
    exit(0);
  if (res == "dead\n")
    {
      std::cout << "LOOSE" << std::endl;
      this->set_dead(1);
      exit(0);
    }
  delete pars;
  free(str);
  return (res);
}

void	Player::go_to_broadcast(int i)
{
  switch (i)
    {
    case 1:
      this->go_up();
      break;
    case 2:
      this->go_up();
      this->turn_left();
      this->go_up();
      break;
    case 3:
      this->turn_left();
      this->go_up();
      break;
    case 4:
      this->turn_left();
      this->go_up();
      this->turn_left();
      this->go_up();
      break;
    case 5:
      this->turn_left();
      this->turn_left();
      this->go_up();
      break;
    case 6:
      this->turn_right();
      this->go_up();
      this->turn_right();
      this->go_up();
      break;
    case 7:
      this->turn_right();
      this->go_up();
      break;
    case 8:
      this->go_up();
      this->turn_right();
      this->go_up();
      break;
    default:
      break;
    }
}

int	Player::get_look_case_ressource(int i, int y) const
{
  return (this->_look[i][y]);
}

int	Player::get_look_case(int i) const
{
  int	res;

  res = 0;
  res += this->get_look_case_ressource(i, 0);
  res += this->get_look_case_ressource(i, 1);
  res += this->get_look_case_ressource(i, 2);
  res += this->get_look_case_ressource(i, 3);
  res += this->get_look_case_ressource(i, 4);
  res += this->get_look_case_ressource(i, 5);
  res += this->get_look_case_ressource(i, 6);
  return (res);
}

int	Player::get_direction() const
{
  int	case_1;
  int	case_2;
  int	case_3;

  case_1 = this->get_look_case(1);
  case_2 = this->get_look_case(2);
  case_3 = this->get_look_case(3);
  if ((case_1 >= case_2) && (case_1 >= case_3))
    return (1);
  else if ((case_2 >= case_1) && (case_2 >= case_3))
    return (2);
  else if ((case_3 >= case_2) && (case_3 >= case_1))
    return (3);
  return (0);
}

int	Player::get_dead() const
{
  return (this->_dead);
}

int	Player::get_level() const
{
  return (this->_level);
}

int	Player::get_orientation() const
{
  return (this->_orientation);
}

int	Player::get_health() const
{
  return (this->_health);
}

void	Player::set_dead(int i)
{
  this->_dead = i;
}

void	Player::setFd(int fd)
{
  this->_fd = fd;
}

void	Player::set_health(int nb)
{
  this->_health += nb;
}

void	Player::set_orientation(int pos)
{
  if (pos == RIGHT)
    {
      if (this->_orientation == 4)
	this->_orientation = 0;
      else
	this->_orientation++;
    }
  else if (pos == LEFT)
    {
      if (this->_orientation == 0)
	this->_orientation = 4;
      else
	this->_orientation--;
    }
}

void		Player::parse_case(std::string in_map)
{
  std::stringstream	ss;
  std::string	sousChaine;

  in_map.erase(in_map.length() - 3, 8);
  ss << in_map;
  while (std::getline(ss, sousChaine, ' '))
    {
      if (sousChaine == "food")
	this->take_food();
      if (sousChaine == "linemate")
	this->take_linemate();
      if (sousChaine == "deraumere")
	this->take_deraumere();
      if (sousChaine == "sibur")
	this->take_sibur();
      if (sousChaine == "mendiane")
	this->take_mendiane();
      if (sousChaine == "phiras")
	this->take_mendiane();
      if (sousChaine == "thystame")
	this->take_thystame();
    }
}

int		Player::upgrade_level()
{
  std::string	res;

  std::cout << "Mon level actuel -> " << this->get_level() << std::endl;
  switch (this->get_level())
    {
    case 1:
      if (this->_ressource.get_linemate() >= 1)
	{
	  this->set_linemate();
	  std::cout << "Incantation" << std::endl;
	  if ((write(this->_fd, "Incantation\n", strlen("Incantation\n"))) == -1)
	    std::cout << "Erreur dans le write" << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  if (res != "ko")
	    {
	      res = this->readServer();
	      std::cout << "Rep -> " << res << std::endl;
	      if (res == "Current level: 2\n")
		  this->_level++;
	    }
	}
      else
	return (1);
      break;
    case 2:
      if (this->_ressource.get_linemate() >= 1 &&
	  this->_ressource.get_deraumere() >= 1 &&
	  this->_ressource.get_sibur() >= 1)
	{

	  std::cout << "Incantation" << std::endl;
	  this->set_linemate();
	  this->set_deraumere();
	  this->set_sibur();
	  if ((write(this->_fd, "Incantation\n", strlen("Incantation\n"))) == -1)
	    std::cout << "Erreur dans le write" << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  if (res == "Current level: 3\n")
	    this->_level++;
	}
      else
	return (1);
      break;
    case 3:
      if (this->_ressource.get_linemate() >= 2 &&
	  this->_ressource.get_phiras() >= 2 &&
	  this->_ressource.get_sibur() >= 1)
	{
	  this->set_linemate();
	  this->set_linemate();
	  this->set_phiras();
	  this->set_phiras();
	  this->set_sibur();
	  std::cout << "Incantation" << std::endl;
	  if ((write(this->_fd, "Incantation\n", strlen("Incantation\n"))) == -1)
	    std::cout << "Erreur dans le write" << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  if (res == "Current level: 4\n")
	    this->_level++;
	}
      else
	return (1);
      break;
    case 4:
      if (this->_ressource.get_linemate() >= 1 &&
	  this->_ressource.get_deraumere() >= 1 &&
	  this->_ressource.get_phiras() >= 1 &&
	  this->_ressource.get_sibur() >= 2)
	{
	  std::cout << "Incantation" << std::endl;
	  this->set_linemate();
	  this->set_phiras();
	  this->set_sibur();
	  this->set_sibur();
	  this->set_deraumere();
	  if ((write(this->_fd, "Incantation\n", strlen("Incantation\n"))) == -1)
	    std::cout << "Erreur dans le write" << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  if (res == "Current level: 5\n")
	    this->_level++;
	}
      else
	return (1);
      break;
    case 5:
      if (this->_ressource.get_linemate() >= 1 &&
	  this->_ressource.get_deraumere() >= 2 &&
	  this->_ressource.get_mendiane() >= 3 &&
	  this->_ressource.get_sibur() >= 1)
	{
	  std::cout << "Incantation" << std::endl;
	  this->set_linemate();
	  this->set_mendiane();
	  this->set_mendiane();
	  this->set_mendiane();
	  this->set_sibur();
	  this->set_deraumere();
	  this->set_deraumere();
	  if ((write(this->_fd, "Incantation\n", strlen("Incantation\n"))) == -1)
	    std::cout << "Erreur dans le write" << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  if (res == "Current level: 6\n")
	    this->_level++;
	}
      else
	return (1);
      break;
    case 6:
      if (this->_ressource.get_linemate() >= 1 &&
	  this->_ressource.get_deraumere() >= 2 &&
	  this->_ressource.get_sibur() >= 3 &&
	  this->_ressource.get_phiras() >= 1)
	{
	  std::cout << "Incantation" << std::endl;
	  this->set_linemate();
	  this->set_phiras();
	  this->set_sibur();
	  this->set_sibur();
	  this->set_sibur();
	  this->set_deraumere();
	  this->set_deraumere();
	  if ((write(this->_fd, "Incantation\n", strlen("Incantation\n"))) == -1)
	    std::cout << "Erreur dans le write" << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  if (res == "Current level: 7\n")
	    this->_level++;
	}
      else
	return (1);
      break;
    case 7:
      if (this->_ressource.get_linemate() >= 2 &&
	  this->_ressource.get_deraumere() >= 2 &&
	  this->_ressource.get_sibur() >= 2 &&
	  this->_ressource.get_mendiane() >= 2 &&
	  this->_ressource.get_phiras() >= 2 &&
	  this->_ressource.get_thystame() >= 1)
	{
	  std::cout << "Incantation" << std::endl;
	  this->set_linemate();
	  this->set_linemate();
	  this->set_deraumere();
	  this->set_deraumere();
	  this->set_sibur();
	  this->set_sibur();
	  this->set_mendiane();
	  this->set_mendiane();
	  this->set_phiras();
	  this->set_phiras();
	  this->set_thystame();
	  if ((write(this->_fd, "Incantation\n", strlen("Incantation\n"))) == -1)
	    std::cout << "Erreur dans le write" << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  res = this->readServer();
	  std::cout << "Rep -> " << res << std::endl;
	  if (res == "Current level: 8\n")
	    this->_level++;
	}
      else
	return (1);
      break;
    default:
      return (1);
    }
  return (0);
}

void	Player::take_food()
{
  std::string	res;
  std::cout << "Take food" << std::endl;
  if ((write(this->_fd, "Take food\n", strlen("Take food\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_food(1);
}

void	Player::take_linemate()
{
  std::string	res;
  std::cout << "Take linemate" << std::endl;
  if ((write(this->_fd, "Take linemate\n", strlen("Take linemate\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_linemate(1);
}

void	Player::take_deraumere()
{
  std::string	res;
  std::cout << "Take deraumere" << std::endl;
  if ((write(this->_fd, "Take deraumere\n", strlen("Take deraumere\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_deraumere(1);
}

void	Player::take_sibur()
{
  std::string	res;
  std::cout << "Take sibur" << std::endl;
  if ((write(this->_fd, "Take sibur\n", strlen("Take sibur\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_sibur(1);
}

void	Player::take_mendiane()
{
  std::string	res;
  std::cout << "Take mendiane" << std::endl;
  if ((write(this->_fd, "Take mendiane\n", strlen("Take mendiane\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_mendiane(1);
}

void	Player::take_phiras()
{
  std::string	res;
  std::cout << "Take phiras" << std::endl;
  if ((write(this->_fd, "Take phiras\n", strlen("Take phiras\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_phiras(1);
}

void	Player::take_thystame()
{
  std::string	res;
  std::cout << "Take thystame" << std::endl;
  if ((write(this->_fd, "Take thystame\n", strlen("Take thystame\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_thystame(1);
}

void	Player::set_food()
{
  std::string	res;
  std::cout << "Set food" << std::endl;
  if ((write(this->_fd, "Set food\n", strlen("Set food\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_food(-1);
}

void	Player::set_linemate()
{
  std::string	res;
  std::cout << "Set linemate" << std::endl;
  if ((write(this->_fd, "Set linemate\n", strlen("Set linemate\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_linemate(-1);
}

void	Player::set_deraumere()
{
  std::string	res;
  std::cout << "Set deraumere" << std::endl;
  if ((write(this->_fd, "Set deraumere\n", strlen("Set deraumere\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_deraumere(-1);
}

void	Player::set_sibur()
{
  std::string	res;
  std::cout << "Set sibur" << std::endl;
  if ((write(this->_fd, "Set sibur\n", strlen("Set sibur\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_sibur(-1);
}

void	Player::set_mendiane()
{
  std::string	res;
  std::cout << "Set mendiane" << std::endl;
  if ((write(this->_fd, "Set mendiane\n", strlen("Set mendiane\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_mendiane(-1);
}

void	Player::set_phiras()
{
  std::string	res;
  std::cout << "Set phiras" << std::endl;
  if ((write(this->_fd, "Set phiras\n", strlen("Set phiras\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_phiras(-1);
}

void	Player::set_thystame()
{
  std::string	res;
  std::cout << "Set thystame" << std::endl;
  if ((write(this->_fd, "Set thystame\n", strlen("Set thystame\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->_ressource.set_thystame(-1);
}

void	Player::go_up()
{
  std::string	res;
  std::cout << "Forward" << std::endl;
  if ((write(this->_fd, "Forward\n", strlen("Forward\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
}

void	Player::turn_left()
{
  std::string	res;
  std::cout << "Left" << std::endl;
  if ((write(this->_fd, "Left\n", strlen("Left\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->set_orientation(LEFT);
}

void	Player::turn_right()
{
  std::string	res;
  std::cout << "Right" << std::endl;
  if ((write(this->_fd, "Right\n", strlen("Right\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
  this->set_orientation(RIGHT);
}

void	Player::eject()
{
  std::string	res;
  std::cout << "Eject" << std::endl;
  if ((write(this->_fd, "Eject\n", strlen("Eject\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
}

void	Player::fork_player()
{
  std::string	res;
  std::cout << "Fork" << std::endl;
  if ((write(this->_fd, "Fork\n", strlen("Fork\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;
}

int	Player::connect_nbr()
{
  int	ret;

  ret = 0;
  std::cout << "Connect_nbr" << std::endl;
  return (ret);
}

void	Player::broadcast(std::string s)
{
  std::string	res;
  std::string	brod;

  brod = "";
  brod = "Broadcast ";
  brod += s;
  brod += "\n";
  std::cout << "Broadcast " << s << std::endl;
  if ((write(this->_fd, brod.c_str(), strlen(brod.c_str()))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  res = this->readServer();
  std::cout << "Rep -> " << res << std::endl;

}

void	Player::inventory()
{
  std::string		s = "";
  std::stringstream	ss;
  std::string		sousChaine;
  int			ressource[7];
  int			i;
  int			y;

  std::cout << "Inventory" << std::endl;
  if ((write(this->_fd, "Inventory\n", strlen("Inventory\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  s = this->readServer();
  i = 0;
  y = 0;
  s.erase(0, 2);
  s.erase(s.length() - 1, 1);
  ss << s;
  while (std::getline(ss, sousChaine, ' '))
    {
      if ((i % 2) == 1)
	{
	  ressource[y] = atoi(sousChaine.c_str());
	  y++;
	}
      i++;
    }
  this->_ressource.set_all(ressource[0], ressource[1], ressource[2], ressource[3], ressource[4], ressource[5], ressource[6]);
}

void	Player::look()
{
  std::string		s = "";
  std::stringstream	ss;
  std::string		sousChaine;
  int			y;
  int			i;

  y = 0;
  i = 0;
  std::cout << "Look" << std::endl;
  if ((write(this->_fd, "Look\n", strlen("Look\n"))) == -1)
    std::cout << "Erreur dans le write" << std::endl;
  s = this->readServer();
  s.erase(0, 8);
  s.erase(s.length() - 1, 1);
  ss << s;
  while (std::getline(ss, sousChaine, ','))
    {
      std::stringstream	ss2;
      std::string	string;

      while (i <= 6)
	this->_look[y][i++] = 0;
      ss2 << sousChaine;
      while (std::getline(ss2, string, ' ') && y <= 3)
	{
	  if (string == "food")
	    this->_look[y][0]++;
	  if (string == "linemate")
	    this->_look[y][1]++;
	  if (string == "deraumere")
	    this->_look[y][2]++;
	  if (string == "sibur")
	    this->_look[y][3]++;
	  if (string == "mendiane")
	    this->_look[y][4]++;
	  if (string == "phiras")
	    this->_look[y][5]++;
	  if (string == "thystame")
	    this->_look[y][6]++;
	}
      y++;
    }
}
