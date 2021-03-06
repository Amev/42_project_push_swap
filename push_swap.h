/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 09:20:51 by vame              #+#    #+#             */
/*   Updated: 2015/03/24 13:30:56 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

# define A 1
# define B 2

# define R 1
# define RR 2

# define CR 1
# define DCR 2

# define MIN 1
# define MAX 2

# define ERR_ARG 1
# define ERR_MAL 2

# define SIMPLE_S 3
# define SIMPLE_R 4
# define SIMPLE_RR 5
# define SIMPLE_P 6
# define DOUBLE_S 9
# define DOUBLE_R 16
# define DOUBLE_RR 25

typedef struct		s_pile
{
	int				c;
	int				v;
	int				n;
	int				r;
	int				nb;
	int				min;
	int				max;
	int				min_a;
	int				max_a;
	int				min_b;
	int				max_b;
	int				sens_a;
	int				sens_b;
	int				nb_ope;
	int				recursion;
	struct s_list	*a;
	struct s_list	*b;
	struct s_list	*ope;
}					t_pile;

/*
** fonctions de preparation, de creation de la liste et de check des erreurs
*/

void				push_init_param(t_pile *d);
void				push_check_in(int av, char **ac, t_pile *d);

/*
** fonctions outils (erreurs, impression, free, etc.)
*/

void				push_print_error(int err);
void				push_print_node_str(t_list *elem);
void				push_do_ope(t_pile *d, int a, int b);
void				push_del_node(void *content, size_t size);
void				push_cpy_list(t_list *list, t_list **tmp);
void				push_print_list_int(t_list *list, int ope, int color);

/*
** fonctions d'operations : rotation, swap, push.
*/

t_list				*push_swap(t_list *list);
t_list				*push_rotate(t_list *list);
t_list				*push_rotate_r(t_list *list);
void				push_do(t_pile *d, int l, int ope);
void				push_new_ope(t_pile *d, int l, int ope);
void				push_push(t_list **minus, t_list **plus);

/*
** fonctions de tri.
*/

void				push_sort(t_pile *d);
void				push_insert_b(t_pile *d);
void				push_sort_long(t_pile *d);
void				push_try_insert(t_pile *d);
void				push_minmax(int l, t_pile *d);
int					push_which_ope(t_pile *d, int l);
int					push_value_last_node(t_list *list);
int					push_is_sort(t_list *list, int sens);
int					push_link_value_insert(t_pile *d, int **a, int **b, int *l);

#endif
