/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:16:57 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/16 15:23:46 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_arr *args)
{
	int	temp;
	int	idx[2];
	int	size;

	size = args->size / 2;
	while (size > 0)
	{
		idx[0] = size;
		while (idx[0] < args->size)
		{
			temp = args->arr[idx[0]];
			idx[1] = idx[0];
			while (idx[1] >= size && args->arr[idx[1] - size] > temp)
			{
				args->arr[idx[1]] = args->arr[idx[1] - size];
				idx[1] -= size;
			}
			args->arr[idx[1]] = temp;
			idx[0] += 1;
		}
		size = size / 2;
	}
}

t_stack	*ft_last(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_before_last(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_new(int nbr)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->nbr = nbr;
	new_node->next = 0;
	return (new_node);
}

void	put_stack(t_arr *args)
{
	int	i;

	args->b_head = 0;
	args->b = args->b_head;
	args->b_size = 0;
	args->a_head = ft_new(args->arr[0]);
	args->a = args->a_head;
	i = 1;
	while (i < args->size)
	{
		args->a->next = ft_new(args->arr[i]);
		args->a = args->a->next;
		i++;
	}
	args->a = args->a_head;
	args->a_size = args->size;
}
