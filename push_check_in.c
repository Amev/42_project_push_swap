/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:07:17 by vame              #+#    #+#             */
/*   Updated: 2015/03/24 16:59:24 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push_check_format_in(int av, char **ac, int i)
{
	int				j;

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

static void			push_create_list_a(int av, char **ac, t_pile *d, int i)
{
	int				res;
	size_t			len;
	t_list			*new;
	long long int	l_res;

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
		ft_lstadd_back(&d->a, new);
		d->max = res > d->max ? res : d->max;
		d->min = res < d->min ? res : d->min;
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

static void			push_check_opt(int av, char **ac, t_pile *d)
{
	int				i;
	int				nb;

	nb = 1;
	while (av > 1 && nb < av && ac[nb][0] == '-' && (i = 1))
	{
		while (ac[nb][i])
		{
			if (ac[nb][i] == 'v')
				d->v = 1;
			else if (ac[nb][i] == 'c')
				d->c = 1;
			else if (ac[nb][i] == 'n')
				d->n = 1;
			else
				break ;
			i++;
		}
		if (ac[nb][i])
			break ;
		nb++;
	}
	d->nb = av - nb;
}

void				push_check_in(int av, char **ac, t_pile *d)
{
	push_check_opt(av, ac, d);
	push_check_format_in(av, ac, av - d->nb);
	push_create_list_a(av, ac, d, av - d->nb);
	push_check_doublons(d);
}
