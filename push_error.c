/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 10:37:41 by vame              #+#    #+#             */
/*   Updated: 2015/03/17 13:00:04 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				push_print_error(int err)
{
	if (err == ERR_ARG)
		ft_putstr_fd("Error\n", 2);
	else if (err == ERR_MAL)
		ft_putstr_fd("Malloc error.\n", 2);
	exit(err);
}
