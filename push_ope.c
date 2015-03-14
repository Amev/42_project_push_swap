/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 14:32:44 by vame              #+#    #+#             */
/*   Updated: 2015/03/14 16:52:36 by vame             ###   ########.fr       */
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
