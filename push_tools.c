/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:09:40 by vame              #+#    #+#             */
/*   Updated: 2015/03/16 17:10:38 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				push_print_error(int err)
{
	if (err == ERR_ARG)
		ft_printf("{red}Error of arguments.{eoc}\n");
	else if (err == ERR_MAL)
		ft_printf("{red}Malloc error.{eoc}\n");
	exit(err);
}

static void			push_print_color(t_list *list, int color)
{
	int				*res;

	if (color)
		ft_printf("{ylw}");
	while (list)
	{
		res = (int *)list->content;
		ft_printf("%d ", *res);
		list = list->next;
	}
	if (color)
		ft_printf("{eoc}");
}

void				push_print_list_int(t_list *list, int ope, int color)
{
	int				*res;

	if (ope == 0 || !color)
		push_print_color(list, 0);
	else if (ope == 1)
	{
		while (list->next)
		{
			res = (int *)list->content;
			ft_printf("%d ", *res);
			list = list->next;
		}
		push_print_color(list, 1);
	}
	else if (ope == 2)
	{
		while (list->next->next)
		{
			res = (int *)list->content;
			ft_printf("%d ", *res);
			list = list->next;
		}
		push_print_color(list, 1);
	}
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