/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:09:40 by vame              #+#    #+#             */
/*   Updated: 2015/03/24 12:33:40 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push_print_color(t_list *list, int color, int rr)
{
	int				*res;

	if (color)
		ft_printf(rr ? "{ylw}" : "{grn}");
	while (list)
	{
		res = (int *)list->content;
		ft_printf("%d ", *res);
		list = list->next;
	}
	if (color)
		ft_printf("{eoc}");
	ft_printf("\n");
}

void				push_cpy_list(t_list *list, t_list **tmp)
{
	t_list			*new;

	if (list)
	{
		push_cpy_list(list->next, tmp);
		if (!(new = ft_lstnew(list->content, list->content_size)))
			push_print_error(ERR_MAL);
		ft_lstadd_back(tmp, new);
	}
}

void				push_print_list_int(t_list *list, int ope, int color)
{
	int				*res;
	t_list			*tmp;

	tmp = NULL;
	push_cpy_list(list, &tmp);
	if (ope == 0 || ope == 3 || !color)
		push_print_color(tmp, color ? 1 : 0, ope == 3 ? 1 : 0);
	else
	{
		while (ope == 1 && tmp->next->next && (res = (int *)tmp->content))
		{
			ft_printf("%d ", *res);
			tmp = tmp->next;
		}
		while (ope == 2 && tmp->next && (res = (int *)tmp->content))
		{
			ft_printf("%d ", *res);
			tmp = tmp->next;
		}
		push_print_color(tmp, 1, 0);
	}
	ft_lstdel(&tmp, push_del_node);
}

void				push_print_node_str(t_list *elem)
{
	char			*res;

	res = (char *)elem->content;
	ft_printf("%s", res);
	if (elem->next)
		ft_printf(" ");
	else
		ft_printf("\n");
}

void				push_del_node(void *content, size_t size)
{
	(void)size;
	ft_memdel(&content);
}
