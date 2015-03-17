/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 09:22:44 by vame              #+#    #+#             */
/*   Updated: 2015/03/17 14:09:56 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					main(int av, char **ac)
{
	t_pile			d;

	push_init_param(&d);
	push_check_in(av, ac, &d);
	if (d.a && push_is_sort(d.a, CR))
		ft_printf("{grn}List is already sort !{eoc}\n");
	else if (d.a)
	{
		push_sort(&d);
		ft_lstiter_r(d.ope, push_print_node_str);
	}
	ft_lstdel(&d.ope, push_del_node);
	ft_lstdel(&d.a, push_del_node);
	return (0);
}
