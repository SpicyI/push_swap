/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:46 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/16 21:45:08 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_arr *args)
{
	if (args->size <= 3)
		high3(args);
	else
	{
		args->ch.mvs = 0;
		args->ch.mid = args->size / 2;
		if (args->size < 100)
		chunker(args);
	}
}

void	chunker(t_arr *args)
{
	while()
}
void	high3(t_arr *args)
{
	while (!is_sorted(args->arr, args->a_head))
	{
		if (args->a->next->nbr < args->a->nbr)
		{
			sa(args);
			printf("sa\n");
		}
		else
		{
			rra(args);
			printf("rra\n");
		}
	}
}

int	is_sorted(int *arr, t_stack *list)
{
	while (list)
	{
		if (list->nbr != *arr)
			return (0);
		list = list->next;
		arr++;
	}
	return (1);
}
