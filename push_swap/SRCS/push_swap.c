/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:54:46 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/22 20:49:43 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_arr *args)
{
	if (args->size <= 3)
		return (high3(args));
	if (args->size <= 16)
		return (high16(args));
	args->ch.mid = args->size / 2;
	if (args->size <= 150)
		args->ch.s = 8;
	else
		args->ch.s = 16;
	ft_pop(args);
	ft_push(args);
}

void	ft_push(t_arr *args)
{
	int		i;
	t_stack	*temp;

	i = args->size - 1;
	while (i >= 0)
	{
		temp = args->b_head;
		args->ch.mvs = 0;
		while (temp)
		{
			if (args->arr[i] == temp->nbr)
			{
				push_a(args, i);
				break ;
			}
			args->ch.mvs += 1;
			temp = temp->next;
		}
		i--;
	}
}

void	push_a(t_arr *args, int c)
{
	int	conf;

	conf = 0;
	if (args->b_size <= 0)
		return ;
	if (args->ch.mvs <= args->b_size / 2)
		conf = rotate(args, c);
	else if (args->ch.mvs > args->b_size / 2)
		conf = rev_rotate(args, c);
	pa(args);
	if (conf == 1)
		sa(args);
}

int	push_b(t_arr *args, int c)
{
	int	act;

	if (!c)
		return (0);
	if (args->ch.mvs <= args->a_size / 2)
	{
		act = args->ch.mvs;
		while (0 < act--)
			ra(args);
	}
	else if (args->ch.mvs > args->a_size / 2)
	{
		act = args->a_size - args->ch.mvs;
		while (0 < act--)
			rra(args);
	}
	pb(args);
	if (c == 1 && args->b_size > 1
		&& args->b_head->nbr < args->b_head->next->nbr)
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
			if (args->a_size <= 0)
				break ;
			if (push_b(args, ispart(temp->nbr, args)))
				break ;
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
