/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:09:40 by vame              #+#    #+#             */
/*   Updated: 2015/03/14 14:50:42 by vame             ###   ########.fr       */
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

void				push_print_node(t_list *elem)
{
	int				*res;

	res = (int *)elem->content;
	ft_printf("%d\n", *res);
}

void				push_del_node(void *content, size_t size)
{
	(void)size;
	ft_memdel(&content);
}
