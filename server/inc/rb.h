/*
** rb.h for  in /home/beche/rb
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Mon Jun 26 09:00:08 2017 beche
** Last update Sun Jul  2 11:01:12 2017 beche
*/

#ifndef RB_H_
# define RB_H_

typedef int	(*member)();
typedef char*	(*fctchar)();
#define RB_SIZE 4096
typedef struct	s_rb
{
  char		*buff;
  int		read;
  int		write;
  member	rb_write;
  fctchar	rb_read;
  fctchar	rb_read_first_cmd;
  member	delete;
  int		size_to_read;
}		t_rb;

t_rb		*construct_rb();
int		get_index(char*, char*);
int		get_cmd_len(t_rb*);
char		*get_cmd_string(t_rb*, int, char*);
#endif /* !RB_H_ */
