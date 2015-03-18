/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 16:52:52 by vame              #+#    #+#             */
/*   Updated: 2015/03/18 12:56:59 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				push_init_param(t_pile *d)
{
	d->c = 0;
	d->v = 0;
	d->nb = 0;
	d->a = NULL;
	d->b = NULL;
	d->ope = NULL;
	d->min = INT_MAX;
	d->max = INT_MIN;
	d->recursion = 4;
}

int					push_is_sort(t_list *list, int sens)
{
	int				*prev;
	int				*next;

	while (list && list->next)
	{
		prev = (int *)list->content;
		next = (int *)list->next->content;
		if (sens == CR && *next < *prev)
			return (0);
		if (sens == DCR && *next > *prev)
			return (0);
		list = list->next;
	}
	return (1);
}

void				push_minmax(int l, t_pile *d)
{
	int				*res;
	t_list			*tmp;

	tmp = l == A ? d->a : d->b;
	d->min_a = l == A ? INT_MAX : d->min_a;
	d->max_a = l == A ? INT_MIN : d->max_a;
	d->min_b = l != A ? INT_MAX : d->min_b;
	d->max_b = l != A ? INT_MIN : d->max_b;
	while (tmp)
	{
		res = (int *)tmp->content;
		if (l == A)
		{
			d->min_a = *res < d->min_a ? *res : d->min_a;
			d->max_a = *res > d->max_a ? *res : d->max_a;
		}
		else if (l == B)
		{
			d->min_b = *res < d->min_b ? *res : d->min_b;
			d->max_b = *res > d->max_b ? *res : d->max_b;
		}
		tmp = tmp->next;
	}
}

int					push_link_value_insert(t_pile *d, int **a, int **b, int *l)
{
	*a = (int *)d->a->content;
	*b = (int *)d->b->content;
	*l = push_value_last_node(d->a);
	return (1);
}

int					push_value_last_node(t_list *list)
{
	int				*res;

	while (list->next)
		list = list->next;
	res = (int *)list->content;
	return (*res);
}
