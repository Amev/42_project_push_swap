/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 09:20:51 by vame              #+#    #+#             */
/*   Updated: 2015/03/14 17:02:52 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft_ext.h"
# include <limits.h>

# define ERR_ARG 1
# define ERR_MAL 2

typedef struct		s_pile
{
	int				c;
	int				v;
	int				min;
	int				max;
	int				nb;
	struct s_list	*a;
	struct s_list	*b;
}					t_pile;

/*
** fonctions de preparation, de creation de la liste et de check des erreurs
*/

void				push_init_param(t_pile *d)
void				push_check_in(int av, char **ac, t_pile *d);

/*
** fonctions outils (erreurs, impression, free, etc.)
*/

void				push_print_error(int err);
void				push_print_node(t_list *elem);
void				push_del_node(void *content, size_t size);

/*
** fonctions d'operations : rotation, swap, push.
*/

void				push_push(t_list **minus, t_list **plus);
t_list				*push_rotate_r(t_list *list);
t_list				*push_rotate(t_list *list);
t_list				*push_swap(t_list *list);

/*
** fonctions de tri.
*/

int					push_is_sort(t_list *list);

#endif
