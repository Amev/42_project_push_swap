/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_which_ope.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 16:57:10 by vame              #+#    #+#             */
/*   Updated: 2015/03/17 17:07:53 by vame             ###   ########.fr       */
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
	ret[1] = 1;
	f[0] = sens == 1 ? push_rotate : push_rotate_r;
	f[1] = sens == 1 ? push_rotate_r : push_rotate;
	d->b = f[0](d->b);
	push_link_value(d->b, &res1, &res2);
	while ((l == B && (*res2 < *res1 || *res1 == d->min_b)) ||
			(l == A && (*res2 > *res1 || *res1 == d->max_a)))
	{
		ret[1] += 1;
		d->b = l == B ? f[0](d->b) : d->b;
		d->a = l == A ? f[0](d->a) : d->a;
		push_link_value(d->b, &res1, &res2);
	}
	while (ret[0]++ < ret[1])
	{
		d->b = l == B ? f[1](d->b) : d->b;
		d->a = l == A ? f[1](d->a) : d->a;
	}
	return (ret[1]);
}

static int			push_before_swap_a(t_pile *d, int sens)
{
	int				i;
	int				ret;
	int				*res1;
	int				*res2;
	t_list			*(f[2])(t_list *);

	i = 0;
	ret = 1;
	f[0] = sens == 1 ? push_rotate : push_rotate_r;
	f[1] = sens == 1 ? push_rotate_r : push_rotate;
	d->a = f[0](d->a);
	push_link_value(d->a, &res1, &res2);
	while (*res2 > *res1 || *res1 == d->max_a)
	{
		ret += 1;
		d->a = f[0](d->a);
		push_link_value(d->a, &res1, &res2);
	}
	while (i++ < ret)
		d->a = f[1](d->a);
	return (ret);
}

int					push_which_ope_b(t_pile *d)
{
	int				ret;
	int				ret_r;
	int				*res1;
	int				*res2;

	ret = 0;
	ret_r = 0;
	push_link_value(d->b, &res1, &res2);
	if (*res2 > *res1 && *res1 != d->min_b)
		ret = SIMPLE_S;
	else
	{
		ret = push_before_swap_b(d, 1);
		ret_r = push_before_swap_b(d, 2);
		ft_printf("b => rr = %d | r = %d.\n", ret_r, ret);
		ret = ret <= ret_r ? SIMPLE_R : SIMPLE_RR;
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
		ret = push_before_swap(d, 1, l);
		ret_r = push_before_swap(d, 2, l);
		ft_printf("b => rr = %d | r = %d.\n", ret_r, ret);
		ret = ret <= ret_r ? SIMPLE_R : SIMPLE_RR;
	}
	return (ret);
}

int					push_which_ope_a(t_pile *d)
{
	int				ret;
	int				ret_r;
	int				*res1;
	int				*res2;

	ret = 0;
	ret_r = 0;
	push_link_value(d->a, &res1, &res2);
	if (*res2 < *res1 && *res1 != d->max_a)
		ret = SIMPLE_S;
	else
	{
		ret = push_before_swap_a(d, 1);
		ret_r = push_before_swap_a(d, 2);
		ft_printf("a => rr = %d | r = %d.\n", ret_r, ret);
		ret = ret <= ret_r ? SIMPLE_R : SIMPLE_RR;
	}
	return (ret);
}