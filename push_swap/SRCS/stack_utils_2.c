/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 03:29:49 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/22 15:30:20 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ispart(int nbr, t_arr *args)
{
	int	i;

	i = args->ch.tail;
	if (i < 0)
		i = 0;
	while (i <= args->ch.mid)
	{
		if (nbr == args->arr[i])
			return (1);
		i++;
	}
	while (i < args->size && i <= args->ch.nose)
	{
		if (nbr == args->arr[i])
			return (2);
		i++;
	}
	return (0);
}

void	high3(t_arr *args)
{
	if (args->a_size <= 0)
		return ;
	while (!is_sorted(args->a_head))
	{
		if (args->a->next->nbr < args->a->nbr)
			sa(args);
		else
			rra(args);
	}
}

int	is_sorted(t_stack *list)
{
	while (list->next)
	{
		if (list->next->nbr < list->nbr)
			return (0);
		list = list->next;
	}
	return (1);
}

int	rotate(t_arr *args, int c)
{
	int	conf;

	conf = 0;
	while (args->b_head->nbr != args->arr[c])
	{
		if (c > 0 && args->b_head->nbr == args->arr[c - 1])
		{
			conf = 1;
			pa(args);
		}
		else
			rb(args);
	}
	return (conf);
}

int	rev_rotate(t_arr *args, int c)
{
	int	conf;

	conf = 0;
	while (args->b_head->nbr != args->arr[c])
	{
		if (c > 0 && args->b_head->nbr == args->arr[c - 1])
		{
			conf = 1;
			pa(args);
		}
		else
			rrb(args);
	}
	return (conf);
}
