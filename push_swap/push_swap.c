/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:46 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/21 19:26:27 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_arr *args)
{

	if (args->size <= 3)
		return (high3(args));
	args->ch.mid = args->size / 2;
	if (args->size <= 10)
		args->ch.s = 5;
	else if (args->size <= 150)
		args->ch.s = 8;
	else
		args->ch.s = 18;
	ft_pop(args);
	ft_push(args);
}

void ft_push(t_arr	*args)
{
	int i;
	t_stack *temp;

	i = args->size - 1;
	//printf("------%d-----\n",i);
	while (i >=0)
	{
		temp = args->b_head;
		args->ch.mvs = 0;
		while (temp)
		{
			if (args->arr[i] == temp->nbr)
			{
				push_a(args, i);
				break;
			}
			args->ch.mvs += 1;
			temp = temp->next;
		}
		i--;
	}
}

int push_a(t_arr *args, int c)
{
	int act;
	int conf;

	if (args->b_size <= 0)
		return (0);
	conf = 0;
	if(args->ch.mvs <= args->b_size / 2)
	{
		act = args->ch.mvs;
		while(0 < act--)
		{
			if(c > 0  && args->b_head->nbr == args->arr[c - 1])
			{
				conf = 1;
				pa(args);
			}
			else
				rb(args);
		}
	}
	else if(args->ch.mvs > args->b_size / 2)
	{
		act = args->b_size - args->ch.mvs;
		while(0 < act--)
		{
			if(c > 0  && args->b_head->nbr == args->arr[c - 1])
			{
				conf = 1;	
				pa(args);
			}
			else	
				rrb(args);
		}
	}
	pa(args);
	if(conf == 1)
		sa(args);
	return (conf);
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
	if(c == 1 && args->b_size > 1 && args->b_head->nbr < args->b_head->next->nbr)
		rb(args);
	return (1);
}

void	ft_pop(t_arr *args)
{
	t_stack	*temp;

	args->ch.tail = args->ch.mid - (args->size / args->ch.s);
	args->ch.nose = args->ch.mid + (args->size / args->ch.s);
	while (args->a_size > 0)
	{
		temp = args->a_head;
		args->ch.mvs = 0;
		while (temp)
		{
			if(args->a_size <= 0)
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
		if(list->next->nbr < list->nbr)
			return(0);
		list = list->next;
	}
	return (1);
}
