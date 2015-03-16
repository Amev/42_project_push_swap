/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 09:20:51 by vame              #+#    #+#             */
/*   Updated: 2015/03/16 16:48:00 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft_ext.h"
# include <limits.h>

# define A 1
# define B 2

# define CR 1
# define DCR 2

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
	int				nb;
	int				min;
	int				max;
	int				min_a;
	int				max_a;
	int				min_b;
	int				max_b;
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
void				push_print_node_int(t_list *elem);
void				push_print_node_str(t_list *elem);
void				push_del_node(void *content, size_t size);
void				push_print_progression(t_pile *d, int a, int b);

/*
** fonctions d'operations : rotation, swap, push.
*/

void				push_new_ope(t_pile *d, int l, int ope);
void				push_push(t_list **minus, t_list **plus);
t_list				*push_rotate_r(t_list *list);
t_list				*push_rotate(t_list *list);
t_list				*push_swap(t_list *list);

/*
** fonctions de tri.
*/

int					push_is_sort(t_list *list, int sens);
void				push_sort(t_pile *d);
void				push_minmax(int l, t_pile *d);
int					push_value_last_node(t_list *list);

#endif
