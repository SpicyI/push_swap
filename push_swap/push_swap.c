/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:46 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/18 15:20:01 by del-khay         ###   ########.fr       */
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
		if (args->size < 100)
			args->ch.s = 3;
		else
			args->ch.s = 5;
		chunker(args);
	}
}

void to_b(t_arr *args,  int c)
{
	int act;

	if(!c)
		return ;
	if(args->ch.mvs <= args->a_size / 2)
	{
		act = args->ch.mvs;
		while(0 < act--)
		{
			ra(args);
			ft_putendl_fd("ra", 1);
		}
	}
	else if(args->ch.mvs > args->a_size / 2)
	{
		act = args->a_size - args->ch.mvs;
		while(0 < act--)
		{
			rra(args);
			ft_putendl_fd("rra", 1);
		}
	}
	pb(args);
	ft_putendl_fd("pb", 1);
	if(c == 1 && args->b_size > 1)
	{
		rb(args);
		ft_putendl_fd("rb", 1);
	}
}

void	chunker(t_arr *args)
{
	t_stack	*temp;

	args->ch.tail = args->ch.mid - (args->a_size / args->ch.s);
	args->ch.nose = args->ch.mid + (args->a_size / args->ch.s);
	while (args->a_size > 3)
	{
		temp = args->a_head;
		args->ch.mvs = 0;
		while (temp)
		{
			if(args->a_size < 4)
				break ;
			to_b(args, ispart(temp->nbr, args));
			args->ch.mvs += 1;
			temp = temp->next;
			if (!temp)
			{
				args->ch.tail -= (args->a_size / args->ch.s);
				args->ch.nose += (args->a_size / args->ch.s);
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
		if (nbr == args->arr[i++])
			return (1);
	while (i < args->size && i <= args->ch.nose)
		if (nbr == args->arr[i++])
			return (2);
	return (0);
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
