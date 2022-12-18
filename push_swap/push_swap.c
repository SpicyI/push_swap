/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:46 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/18 21:30:40 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_arr *args)
{

	args->ch.mid = args->size / 2;
	if (args->size <= 10)
		args->ch.s = 5;
	else if (args->size <= 150)
		args->ch.s = 8;
	else
		args->ch.s = 18;
	ft_pop(args);
}

int push_b(t_arr *args,  int c)
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

void	ft_pop(t_arr *args)
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
			if(push_b(args, ispart(temp->nbr, args)))
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
	high3(args);
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
		if(list->next->nbr < list->nbr)
			return(0);
		list = list->next;
	}
	return (1);
}
