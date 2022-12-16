/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:12:22 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/16 15:21:58 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_arr *args)
{
	if (args->a_size < 2)
		return ;
	args->a_head = args->a_head->next;
	args->a->next = args->a->next->next;
	args->a_head->next = args->a;
	args->a = args->a_head;
}

void	sb(t_arr *args)
{
	if (args->b_size < 2)
		return ;
	args->b_head = args->b_head->next;
	args->b->next = args->b->next->next;
	args->b_head->next = args->b;
	args->b = args->b_head;
}

void	ss(t_arr *args)
{
	sa(args);
	sb(args);
}

void	pa(t_arr *args)
{
	if (args->b_size <= 0)
		return ;
	args->b_head = args->b->next;
	args->b->next = args->a_head;
	args->a_head = args->b;
	args->b = args->b_head;
	args->a = args->a_head;
	args->b_size -= 1;
}

void	pb(t_arr *args)
{
	if (args->a_size <= 0)
		return ;
	args->a_head = args->a->next;
	args->a->next = args->b_head;
	args->b_head = args->a;
	args->a = args->a_head;
	args->b = args->b_head;
	args->a_size -= 1;
}

void	ra(t_arr *args)
{
	args->a_head = args->a->next;
	args->a->next = 0;
	ft_last(args->a_head)->next = args->a;
	args->a = args->a_head;
}

void	rb(t_arr *args)
{
	args->b_head = args->b->next;
	args->b->next = 0;
	ft_last(args->b_head)->next = args->b;
	args->b = args->b_head;
}

void	rr(t_arr *args)
{
	ra(args);
	rb(args);
}

void	rra(t_arr *args)
{
	args->a = ft_last(args->a_head);
	ft_before_last(args->a_head)->next = 0;
	args->a->next = args->a_head;
	args->a_head = args->a;
}

void	rrb(t_arr *args)
{
	args->b = ft_last(args->b_head);
	ft_before_last(args->b_head)->next = 0;
	args->b->next = args->b_head;
	args->b_head = args->b;
}

void	rrr(t_arr *args)
{
	rra(args);
	rrb(args);
}