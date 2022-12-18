/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:46 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/18 18:36:31 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_arr *args)
{
	if (args->size <= 3)
		high3(args);
	else
	{
		args->ch.mid = args->size / 2;
		if (args->size <= 10)
			args->ch.s = 5;
		else if (args->size <= 150)
			args->ch.s = 8;
		else
			args->ch.s = 18;
		chunker(args);
	}
}

int to_b(t_arr *args,  int c)
{
	int act;

	if(!c)
		return (0);
	if(args->ch.mvs <= args->a_size / 2)
	{
		act = args->ch.mvs;
		while(0 < act--)
			ra(args);
	}
	else if(args->ch.mvs > args->a_size / 2)
	{
		act = args->a_size - args->ch.mvs;
		while(0 < act--)
			rra(args);
	}
	pb(args);
	if(c == 1 && args->b_size > 1)
		rb(args);
	return (1);
}

void	chunker(t_arr *args)
{
	t_stack	*temp;

	args->ch.tail = args->ch.mid - (args->size / args->ch.s);
	args->ch.nose = args->ch.mid + (args->size / args->ch.s);
	while (args->a_size > 3)
	{
		temp = args->a_head;
		args->ch.mvs = 0;
		while (temp)
		{
			if(args->a_size < 4)
				break ;
			if(to_b(args, ispart(temp->nbr, args)))
				break;
			args->ch.mvs += 1;
			temp = temp->next;
			if (!temp)
			{
				args->ch.tail -= (args->size / args->ch.s);
				args->ch.nose += (args->size / args->ch.s);
				break ;
			}
		}
	}
	//high3(args);
}

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
	while (!is_sorted(args->arr, args->a_head))
	{
		if (args->a->next->nbr < args->a->nbr)
			sa(args);
		else
			rra(args);
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
