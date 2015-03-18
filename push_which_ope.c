/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_which_ope.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 16:57:10 by vame              #+#    #+#             */
/*   Updated: 2015/03/18 13:01:42 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push_link_value(t_list *list, int **res1, int **res2)
{
	*res1 = (int *)list->content;
	*res2 = (int *)list->next->content;
}

static int			push_before_swap(t_pile *d, int sens, int l)
{
	int				ret[2];
	int				*res1;
	int				*res2;
	t_list			*(*f[2])(t_list *);

	ret[0] = 0;
	ret[1] = 0;
	f[0] = sens == R ? push_rotate : push_rotate_r;
	f[1] = sens == R ? push_rotate_r : push_rotate;
	push_link_value(l == B ? d->b : d->a, &res1, &res2);
	while (((l == B && (*res2 < *res1 || *res1 == d->min_b)) ||
			(l == A && (*res2 > *res1 || *res1 == d->max_a))) && ret[1] < d->nb)
	{
		ret[1] += 1;
		d->b = l == B ? f[0](d->b) : d->b;
		d->a = l == A ? f[0](d->a) : d->a;
		push_link_value(l == B ? d->b : d->a, &res1, &res2);
	}
	while (ret[0]++ < ret[1])
	{
		d->b = l == B ? f[1](d->b) : d->b;
		d->a = l == A ? f[1](d->a) : d->a;
	}
	return (ret[1]);
}

static int			push_is_sort_after_rot(t_pile *d, int sens, int l)
{
	int				i;
	int				ret;
	t_list			*(*f[2])(t_list *);

	i = 0;
	ret = 0;
	f[0] = sens == R ? push_rotate : push_rotate_r;
	f[1] = sens == R ? push_rotate_r : push_rotate;
	while ((l == A && !push_is_sort(d->a, CR)) ||
			(l == B && !push_is_sort(d->b, DCR)))
	{
		ret += 1;
		d->b = l == B ? f[0](d->b) : d->b;
		d->a = l == A ? f[0](d->a) : d->a;
	}
	while (i++ < ret)
	{
		d->b = l == B ? f[1](d->b) : d->b;
		d->a = l == A ? f[1](d->a) : d->a;
	}
	return (ret);
}

int					push_which_ope(t_pile *d, int l)
{
	int				ret;
	int				ret_r;
	int				*res1;
	int				*res2;

	ret = 0;
	ret_r = 0;
	push_link_value(l == A ? d->a : d->b, &res1, &res2);
	if (l == B && *res2 > *res1 && *res1 != d->min_b)
		ret = SIMPLE_S;
	else if (l == A && *res2 < *res1 && *res1 != d->max_a)
		ret = SIMPLE_S;
	else
	{
		ret = push_before_swap(d, R, l);
		ret_r = push_before_swap(d, RR, l);
		if (ret == ret_r && ret == d->nb)
		{
			ret = push_is_sort_after_rot(d, R, l);
			ret_r = push_is_sort_after_rot(d, RR, l);
		}
		ret = ret <= ret_r ? SIMPLE_R : SIMPLE_RR;
	}
	return (ret);
}
