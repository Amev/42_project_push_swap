/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 11:39:29 by vame              #+#    #+#             */
/*   Updated: 2015/03/18 08:19:53 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static void			push_sort_list_b(t_pile *d)
{
	int				b;

	b = 1;
	push_minmax(B, d);
	while (b)
	{
		b = 0;
		if (!push_is_sort(d->b, DCR))
			b = push_which_ope(d->b, DCR, B, d);
		push_do_ope(d, 0, b);
	}
}

static void			push_push_b(t_pile *d)
{
	int				i;

	i = 0;
	while (d->b)
		push_do_ope(d, SIMPLE_P, 0);
	while (i++ < d->recursion)
		push_do_ope(d, SIMPLE_R, 0);
}

static void			push_recursion_sort(t_pile *d, int nb)
{
	int				i;
	int				*res1;
	int				*res2;

	i = 0;
	if (nb > d->recursion)
		push_recursion_sort(d, nb / 2);
	while (i++ < nb)
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
	push_sort_list_b(d);
	push_push_b(d);
}

void				push_sort_long(t_pile *d)
{
	while (d->recursion < d->nb / 2 && !push_is_sort(d->a, CR))
	{
		push_recursion_sort(d, d->recursion);
		d->recursion *= 2;
		ft_printf("x\n");
	}
	push_sort(d);
}*/
