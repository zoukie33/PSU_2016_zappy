//
// Client.hpp for  in /home/elodie/C/reseau/Zappy/client/include
// 
// Made by Elodie
// Login   <elodie>
// 
// Started on  Wed Jun  7 12:03:14 2017 Elodie
// Last update Thu Jun  8 14:54:27 2017 Elodie
//


#ifndef CLIENT_HPP_
# define CLIENT_HPP_

class	Client{

private:
  int		_id;
  int		port;
  std::string	team;
  std::string	machine;
  IA		ia;
  
public:
  Connexion();
  Connexion(const int &, const std::string &, const std::string machine);
  Connexion(const int &, const std::string &);
  Connexion(const Connexion &);
  ~Connexion();

  //setters
  void			setPort();
  void			setTeam();
  void			setMachine();

  //getters
  int			getPort(const int &) const;
  std::string		getTeam(const std::string &) const;
  std::string		getMachine(const std::string &) const;

  Connexion		&operator=(const connexion &);

};

#endif /* CLIENT_HPP_ */
