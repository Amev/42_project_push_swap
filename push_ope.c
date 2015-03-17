/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 14:32:44 by vame              #+#    #+#             */
/*   Updated: 2015/03/17 15:45:42 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list				*push_rotate(t_list *list)
{
	t_list			*tmp;
	t_list			*first;
	t_list			*second;

	if (list && list->next)
	{
		tmp = list;
		first = list;
		second = list->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = first;
		first->next = NULL;
		list = second;
	}
	return (list);
}

t_list				*push_rotate_r(t_list *list)
{
	t_list			*tmp;
	t_list			*last;
	t_list			*first;

	if (list && list->next)
	{
		tmp = list;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp;
		first = tmp->next;
		last->next = NULL;
		first->next = list;
		list = first;
	}
	return (list);
}

void				push_push(t_list **minus, t_list **plus)
{
	t_list			*node;

	if (*minus)
	{
		node = *minus;
		*minus = node->next;
		node->next = *plus;
		*plus = node;
	}
}

t_list				*push_swap(t_list *list)
{
	t_list			*first;
	t_list			*second;

	if (list && list->next)
	{
		first = list;
		second = list->next;
		first->next = second->next;
		second->next = first;
		list = second;
	}
	return (list);
}

void				push_new_ope(t_pile *d, int l, int ope)
{
	char			*name;
	t_list			*new_ope;

	name = NULL;
	if (ope == SIMPLE_S)
		name = ft_strdup(l == A ? "sa" : "sb");
	else if (ope == SIMPLE_R)
		name = ft_strdup(l == A ? "ra" : "rb");
	else if (ope == SIMPLE_P)
		name = ft_strdup(l == A ? "pa" : "pb");
	else if (ope == SIMPLE_RR)
		name = ft_strdup(l == A ? "rra" : "rrb");
	else if (ope == DOUBLE_S)
		name = ft_strdup("ss");
	else if (ope == DOUBLE_R)
		name = ft_strdup("rr");
	else if (ope == DOUBLE_RR)
		name = ft_strdup("rrr");
	if (!name)
		push_print_error(ERR_MAL);
	if (!(new_ope = ft_lstnew(name, ft_strlen(name) + 1)))
		push_print_error(ERR_MAL);
	ft_lstadd_back(&d->ope, new_ope);
	ft_strdel(&name);
}
