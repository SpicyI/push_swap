/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:16:57 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/14 22:44:55 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(t_arr args)
{
	int	i;
	int	j;

	i = 0;
	while(i < args.size)
	{
		j = i + 1;
		while(j < args.size)
		{
			if (args.arr[i] == args.arr[j])
				exit(20); // doubles 
			j++;
		}
		i++;
	}
	put_stack(&args);
	ft_sort(&args);
}

void	ft_sort(t_arr *args)
{
	int temp;
	int	idx[2];
	int size;
	
	size = args->size/2;
	while(size > 0)
	{
		idx[0] = size;
		while (idx[0] < args->size)
		{
			temp = args->arr[idx[0]];
			idx[1] = idx[0];
			if (idx[1] >= size && args->arr[idx[1] - size] > temp)
			{
				args->arr[idx[1]] = args->arr[idx[1] - size];
				idx[1] -= size;
			}
			args->arr[idx[1]] = temp; 
			idx[0] += 1;
		}	
		size = size/2; 
	}
}

void	put_stack(t_arr *args)
{
	int i;
	t_list	*t;
	t = ft_lstnew(args->arr[0]);
	args->a = &t;
	i = 1;
	while(i < args->size)
	{
		t->next = ft_lstnew(args->arr[i]);
		t = t->next; 
		i++;
	}
}