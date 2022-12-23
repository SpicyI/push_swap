/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:49:45 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/23 17:29:22 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	high16(t_arr *args)
{
	int		i;
	t_stack	*temp;

	i = 0;
	while (args->a_size > 3)
	{
		temp = args->a_head;
		args->ch.mvs = 0;
		while (temp)
		{
			if (args->arr[i] == temp->nbr)
			{
				push_it(args, i);
				break ;
			}
			args->ch.mvs += 1;
			temp = temp->next;
		}
		i++;
	}
	high3(args);
	while (args->b_size)
		pa(args, DSPL);
}

void	push_it(t_arr *args, int i)
{
	if (args->ch.mvs <= args->a_size / 2)
	{
		while (args->a_head->nbr != args->arr[i])
			ra(args, DSPL);
	}
	else if (args->ch.mvs > args->a_size / 2)
	{
		while (args->a_head->nbr != args->arr[i])
			rra(args, DSPL);
	}
	pb(args, DSPL);
}

void	rrr(t_arr *args, int c)
{
	rra(args, N_DSPL);
	rrb(args, N_DSPL);
	if (c == DSPL)
		ft_putendl_fd("rrr", 1);
}

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}
