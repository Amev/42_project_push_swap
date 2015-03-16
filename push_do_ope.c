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

static void			push_print_double_ope(t_pile *d, int a)
{
	int				ope;
	char			*str;
	t_list			*tmp;

	ope = 0;
	while (tmp->next)
		tmp = tmp->next;
	str = (char *)tmp->content;
	if (a == SIMPLE_S)
		ope = 1;
	ft_printf("%s :\na : ", str);
	push_print_list_int(d->a, ope, d->c);
	ft_printf("b : ");
	push_print_list_int(d->b, ope, d->c);
}

static void			push_print_simple_ope(t_pile *d, int l, int last, int a)
{
	int				ope;
	char			*str;
	t_list			*tmp;

	ope = 0;
	if (last)
		while (tmp->next->next)
			tmp = tmp->next;
	if (!last)
		while (tmp->next)
			tmp = tmp->next;
	str = (char *)tmp->content;
	if (a == SIMPLE_S)
		ope = 1;
	else if (a == SIMPLE_P)
		ope = 2;
	ft_printf("%s :\na : ", str);
	push_print_list_int(d->a, ope, l == A ? d->c : 0);
	ft_printf("b : ");
	push_print_list_int(d->b, ope, l == B ? d->c : 0);
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
			push_print_simple_ope(d, A, b == 0 ? 0 : 1, a);
	}
	else if (b)
	{
		push_new_ope(d, B, b);
		if (d->v)
			push_print_simple_ope(d, B, 0, b);
	}
}