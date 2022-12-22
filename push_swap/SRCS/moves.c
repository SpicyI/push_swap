/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:12:22 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/22 03:10:29 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_arr *args)
{
	if (args->b_size < 2)
		return ;
	args->b_head = args->b->next;
	args->b->next = 0;
	ft_last(args->b_head)->next = args->b;
	args->b = args->b_head;
	ft_putendl_fd("rb", 1);
}

void	rr(t_arr *args)
{
	ra(args);
	rb(args);
}

void	rra(t_arr *args)
{
	if (args->a_size < 2)
		return ;
	args->a = ft_last(args->a_head);
	ft_outmost(args->a_head)->next = 0;
	args->a->next = args->a_head;
	args->a_head = args->a;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_arr *args)
{
	if (args->b_size < 2)
		return ;
	args->b = ft_last(args->b_head);
	ft_outmost(args->b_head)->next = 0;
	args->b->next = args->b_head;
	args->b_head = args->b;
	ft_putendl_fd("rrb", 1);
}

void	ra(t_arr *args)
{
	if (args->a_size < 2)
		return ;
	args->a_head = args->a->next;
	args->a->next = 0;
	ft_last(args->a_head)->next = args->a;
	args->a = args->a_head;
	ft_putendl_fd("ra", 1);
}
