/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_do_ope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:57:19 by vame              #+#    #+#             */
/*   Updated: 2015/03/24 12:40:41 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push_print_double_ope(t_pile *d, int a)
{
	int				ope;
	char			*str;
	t_list			*tmp;

	ope = 0;
	tmp = d->ope;
	while (tmp->next)
		tmp = tmp->next;
	str = (char *)tmp->content;
	if (a == SIMPLE_S)
		ope = 1;
	ft_printf("%s :\na : ", str);
	push_print_list_int(d->a, ope, d->c);
	ft_printf("b : ");
	push_print_list_int(d->b, ope, d->c);
	ft_printf("\n");
}

static void			push_print_simple_ope(t_pile *d, int l, int a)
{
	int				ope;
	char			*str;
	t_list			*tmp;

	ope = 0;
	tmp = d->ope;
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
	ft_printf("\n");
}

static void			push_do_double(t_pile *d, int ope)
{
	if (ope == DOUBLE_S)
	{
		d->a = push_swap(d->a);
		d->b = push_swap(d->b);
	}
	else if (ope == DOUBLE_R)
	{
		d->a = push_rotate(d->a);
		d->b = push_rotate(d->b);
	}
	else if (ope == DOUBLE_RR)
	{
		d->a = push_rotate_r(d->a);
		d->b = push_rotate_r(d->b);
	}
}

void				push_do(t_pile *d, int l, int ope)
{
	t_list			*tmp;

	if (l == 0)
		push_do_double(d, ope);
	else
	{
		tmp = l == A ? d->a : d->b;
		if (ope == SIMPLE_S)
			tmp = push_swap(tmp);
		else if (ope == SIMPLE_R)
			tmp = push_rotate(tmp);
		else if (ope == SIMPLE_RR)
			tmp = push_rotate_r(tmp);
		d->a = l == A ? tmp : d->a;
		d->b = l != A ? tmp : d->b;
		if (ope == SIMPLE_P)
		{
			if (l == A)
				push_push(&d->b, &d->a);
			else
				push_push(&d->a, &d->b);
		}
	}
}

void				push_do_ope(t_pile *d, int a, int b)
{
	if (a && a == b)
	{
		push_do(d, 0, a * b);
		push_new_ope(d, 0, a * b);
		if (d->v)
			push_print_double_ope(d, a);
	}
	else
	{
		if (a)
		{
			push_do(d, A, a);
			push_new_ope(d, A, a);
			if (d->v)
				push_print_simple_ope(d, A, a);
		}
		if (b)
		{
			push_do(d, B, b);
			push_new_ope(d, B, b);
			if (d->v)
				push_print_simple_ope(d, B, b);
		}
	}
}
