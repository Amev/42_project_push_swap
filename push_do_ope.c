/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_do_ope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:57:19 by vame              #+#    #+#             */
/*   Updated: 2015/03/16 17:10:41 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push_print_double_ope(t_pile *d)
{
	char			*str;
	t_list			*tmp;

	while (tmp->next)
		tmp = tmp->next;
	str = (char *)tmp->content;
	if (d->c)
		ft_printf("{ylw}");
	ft_printf("%s :\na : ", str);
	ft_lstiter_r(d->a, push_print_node_int);
	ft_printf("\nb : ");
	ft_lstiter_r(d->b, push_print_node_int);
	ft_printf("{eoc}\n");
}

static void			push_print_simple_ope(t_pile *d, int l, int last)
{
	char			*str;
	t_list			*tmp;

	if (last)
		while (tmp->next->next)
			tmp = tmp->next;
	if (!last)
		while (tmp->next)
			tmp = tmp->next;
	str = (char *)tmp->content;
	push_print_pile(d, l, l == A ? 1 : 0);
	push_print_pile(d, l, l == A ? 1 : 0);
}

void				push_do_ope(t_pile *d, int a, int b)
{
	if (a && a == b)
	{
		push_new_ope(d, 0, a * b);
		if (d->v)
			push_print_double_ope(d);
	}
	else if (a)
	{
		push_new_ope(d, A, a);
		if (d->v)
			push_print_simple_ope(d, A, b == 0 ? 0 : 1);
	}
	else if (b)
	{
		push_new_ope(d, B, b);
		if (d->v)
			push_print_simple_ope(d, B, 0);
	}
}
