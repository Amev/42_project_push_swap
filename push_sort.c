/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 15:58:35 by vame              #+#    #+#             */
/*   Updated: 2015/03/18 12:57:12 by vame             ###   ########.fr       */
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
		if (b == 0)
			push_try_insert(d);
		b = 0;
		if (!push_is_sort(d->a, CR))
			a = push_which_ope(d, A);
		if (!push_is_sort(d->b, DCR))
			b = push_which_ope(d, B);
		push_do_ope(d, a, b);
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
