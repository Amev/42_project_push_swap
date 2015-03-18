/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 15:58:35 by vame              #+#    #+#             */
/*   Updated: 2015/03/18 08:43:58 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push_cut_a(t_pile *d)
{
	int				i;
	int				*res1;
	int				*res2;

	i = 0;
	while (i++ < d->nb / 2)
	{
		res1 = (int *)d->a->content;
		res2 = (int *)d->a->next->content;
		if (*res1 > *res2)
			push_do_ope(d, SIMPLE_S, 0);
		if (push_is_sort(d->a, CR))
			break ;
		else
			push_do_ope(d, 0, SIMPLE_P);
	}
}
/*
int					push_which_ope(t_list *list, int s, int l, t_pile *d)
{
	int				r[4];
	int				*res1;
	int				*res2;

	res1 = (int *)list->content;
	res2 = (int *)list->next->content;
	r[0] = push_value_last_node(d->a);
	r[1] = l == A ? d->min_a : d->min_b;
	r[2] = l == A ? d->max_a : d->max_b;
	if (s == CR && *res2 < *res1 && *res1 != r[2])
		r[3] = SIMPLE_S;
	else if (s == DCR && *res2 > *res1 && *res1 != r[1])
		r[3] = SIMPLE_S;
	else if (*res1 < r[0] && r[0] != (l == A ? r[2] : r[1]))
		r[3] = l == A ? SIMPLE_RR : SIMPLE_R;
	else
		r[3] = l == A ? SIMPLE_R : SIMPLE_RR;
	return (r[3]);
}*/

static void			push_sort_list(t_pile *d)
{
	int				a;
	int				b;

	a = 1;
	b = 1;
	push_minmax(A, d);
	push_minmax(B, d);
	while (a || b)
	{
		a = 0;
		b = 0;
		if (!push_is_sort(d->a, CR))
			a = push_which_ope(d, A);
		if (!push_is_sort(d->b, DCR))
			b = push_which_ope(d, B);
		ft_printf("a = %d | b = %d.\n", a, b);
		push_do_ope(d, a, b);
	}
}

static void			push_insert_b(t_pile *d)
{
	int				res3;
	int				*res1;
	int				*res2;

	while (d->b)
	{
		push_minmax(A, d);
		res1 = (int *)d->b->content;
		if (*res1 < d->min_a || *res1 > d->max_a)
			while (!push_is_sort(d->a, CR))
				push_do_ope(d, SIMPLE_RR, 0);
		while (*res1 > d->min_a && *res1 < d->max_a)
		{
			res2 = (int *)d->a->content;
			res3 = push_value_last_node(d->a);
			if (*res1 < *res2 && res3 < *res1)
				break ;
			push_do_ope(d, *res1 < *res2 ? SIMPLE_RR : SIMPLE_R, 0);
		}
		push_do_ope(d, SIMPLE_P, 0);
	}
}

void				push_sort(t_pile *d)
{
	push_cut_a(d);
	push_sort_list(d);
	push_insert_b(d);
	while (!push_is_sort(d->a, CR))
		push_do_ope(d, SIMPLE_RR, 0);
}
