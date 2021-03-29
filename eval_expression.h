/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef EVAL_EXPRESSION_H
# define EVAL_EXPRESSION_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_num
{
	int				n;
	struct s_num	*next;
}					t_num;

typedef struct		s_symb
{
	char			*c;
	struct s_symb	*next;
}					t_symb;

int		eval_expression(char *str);

char	*remove_spaces(char *argv);
void	check_wrong(char *str);
void	display_error(void);

void	aka_putchar(char c);
void	aka_putnbr(int nbr);
int		aka_isdigit(char c);
int		aka_strlen(char *str);
int		aka_strchr(char *str, char c);

#endif
