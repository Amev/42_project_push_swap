/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 15:58:35 by vame              #+#    #+#             */
/*   Updated: 2015/03/14 16:50:35 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					push_is_sort(t_list *list)
{
	int				*prev;
	int				*next;

	while (list && list->next)
	{
		prev = (int *)list->content;
		next = (int *)list->next->content;
		if (*next < *prev)
			return (0);
		list = list->next;
	}
	return (1);
}
