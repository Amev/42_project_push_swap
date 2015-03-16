/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:09:40 by vame              #+#    #+#             */
/*   Updated: 2015/03/14 15:58:23 by vame             ###   ########.fr       */
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

void				push_print_node_int(t_list *elem)
{
	int				*res;

	res = (int *)elem->content;
	ft_printf("%d", *res);
	if (elem->next)
		ft_printf(" ");
	else
		ft_printf("\n");
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