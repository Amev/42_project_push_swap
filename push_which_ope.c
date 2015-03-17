/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_which_ope.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 16:57:10 by vame              #+#    #+#             */
/*   Updated: 2015/03/17 17:07:53 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push_link_value(t_list *list, int **res1, int **res2)
{
	*res1 = (int *)list->content;
	*res2 = (int *)list->next->content;
}

static int			push_how_before_swap_b(t_pile *d, int sens)
{
	int				i;
	int				ret;
	int				*res1;
	int				*res2;
	t_list			*(*f[2])(t_list *);

	i = 0;
	ret = 1;
	f[0] = sens == 1 ? push_rotate : push_rotate_r;
	f[1] = sens == 1 ? push_rotate_r : push_rotate;
	d->b = f[0](d->b);
	push_link_value(d->b, &res1, &res2);
	while (*res2 < *res1 || *res1 == d->min_b)
	{
		ret += 1;
		d->b = f[0](d->b);
		push_link_value(d->b, &res1, &res2);
	}
	while (i++ < ret)
		d->b = f[1](d->b);
	return (ret);
}

int					push_which_ope_b(t_pile *d)
{
	int				ret;
	int				ret_r;
	int				*res2;
	int				*res3;

	ret = 0;
	ret_r = 0;
	push_link_value(d->b, &res2, &res3);
	if (*res3 > *res2 && *res2 != d->min_b)
		ret = SIMPLE_S;
	else
	{
		ret = push_how_before_swap_b(d, 1);
		ret_r = push_how_before_swap_b(d, 2);
		ft_printf("b => rr = %d | r = %d.\n", ret_r, ret);
		ret = ret <= ret_r ? SIMPLE_R : SIMPLE_RR;
	}
	return (ret);
}
