/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:07:17 by vame              #+#    #+#             */
/*   Updated: 2015/03/14 15:08:01 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push_check_format_in(int av, char **ac)
{
	int				i;
	int				j;

	i = 1;
	if (av < 2)
		push_print_error(ERR_ARG);
	while (i++ < av)
	{
		j = 0;
		if (ac[i - 1][j] == '-')
			j++;
		while (ac[i - 1][j])
			if (!ft_isdigit(ac[i - 1][j++]))
				push_print_error(ERR_ARG);
	}
}

static void			push_create_list_a(int av, char **ac, t_pile *d)
{
	int				i;
	int				res;
	size_t			len;
	t_list			*new;
	long long int	l_res;

	i = 1;
	while (i < av)
	{
		len = ft_strlen(ac[i]);
		l_res = ft_atoi_l(ac[i++]);
		if (l_res > INT_MAX || l_res < INT_MIN || ((l_res == -1 ||
					l_res == 0) && len > 2))
			push_print_error(ERR_ARG);
		res = (int)l_res;
		if (!(new = ft_lstnew(&res, 4)))
			push_print_error(ERR_MAL);
		ft_lstadd(&d->a, new);
	}
}

static void			push_check_doublons(t_pile *d)
{
	t_list			*list;
	t_list			*tmp;
	int				*a;
	int				*b;

	list = d->a;
	while (list)
	{
		tmp = list->next;
		a = (int *)list->content;
		while (tmp)
		{
			b = (int *)tmp->content;
			if (*a == *b)
				push_print_error(ERR_ARG);
			tmp = tmp->next;
		}
		list = list->next;
	}
}

void				push_check_in(int av, char **ac, t_pile *d)
{
	push_check_format_in(av, ac);
	push_create_list_a(av, ac, d);
	push_check_doublons(d);
}
