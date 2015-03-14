/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 09:22:44 by vame              #+#    #+#             */
/*   Updated: 2015/03/14 14:32:33 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					main(int av, char **ac)
{
	t_pile			d;

	d.a = NULL;
	d.b = NULL;
	push_check_in(av, ac, &d);
	ft_lstiter(d.a, push_print_node);
	ft_lstdel(&d.a, push_del_node);
	return (0);
}
