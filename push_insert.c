/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 11:18:32 by vame              #+#    #+#             */
/*   Updated: 2015/03/18 12:56:50 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				push_try_insert(t_pile *d)
{
	int				*a;
	int				*b;
	int				last_a;

	while (1)
	{
		a = (int *)d->a->content;
		b = (int *)d->b->content;
		last_a = push_value_last_node(d->a);
		if (*b < *a && *b > last_a)
			push_do_ope(d, SIMPLE_P, 0);
		else
			break ;
	}
}

static int			push_insert_min(t_pile *d, int sens)
{
	int				i;
	int				ret;
	int				*res;
	t_list			*(*f[2])(t_list *);

	i = 0;
	ret = 0;
	res = (int *)d->a->content;
	f[0] = sens == R ? push_rotate : push_rotate_r;
	f[1] = sens == R ? push_rotate_r : push_rotate;
	while (*res != d->min_a)
	{
		ret += 1;
		d->a = f[0](d->a);
		res = (int *)d->a->content;
	}
	while (i++ < ret)
		d->a = f[1](d->a);
	return (ret);
}

static int			push_insert_place(t_pile *d, int sens)
{
	int				*a;
	int				*b;
	int				last_a;
	int				ret[2];
	t_list			*(*f[2])(t_list *);

	ret[0] = 0;
	ret[1] = 0;
	a = (int *)d->a->content;
	b = (int *)d->b->content;
	last_a = push_value_last_node(d->a);
	f[0] = sens == R ? push_rotate : push_rotate_r;
	f[1] = sens == R ? push_rotate_r : push_rotate;
	while (*b > *a || *b < last_a)
	{
		ret[1] += 1;
		d->a = f[0](d->a);
		a = (int *)d->a->content;
		last_a = push_value_last_node(d->a);
	}
	while (ret[0]++ < ret[1])
		d->a = f[1](d->a);
	return (ret[1]);
}

static int			push_insert_which_ope(t_pile *d, int cas)
{
	int				ret;
	int				ret_r;

	ret = cas == MIN ? push_insert_min(d, R) : push_insert_place(d, R);
	ret_r = cas == MIN ? push_insert_min(d, RR) : push_insert_place(d, RR);
	ret = ret <= ret_r ? SIMPLE_R : SIMPLE_RR;
	return (ret);
}

void				push_insert_b(t_pile *d)
{
	int				*a;
	int				*b;
	int				ope;
	int				last_a;

	while (d->b)
	{
		push_minmax(A, d);
		push_link_value_insert(d, &a, &b, &last_a);
		if (*b < d->min_a || *b > d->max_a)
		{
			ope = push_insert_which_ope(d, MIN);
			while ((a = (int *)d->a->content) && *a != d->min_a)
				push_do_ope(d, ope, 0);
		}
		else if (*b > *a || *b < last_a)
		{
			ope = push_insert_which_ope(d, 0);
			while (push_link_value_insert(d, &a, &b, &last_a)
					&& (*b > *a || *b < last_a))
				push_do_ope(d, ope, 0);
		}
		push_do_ope(d, SIMPLE_P, 0);
	}
}
